#pragma once
#include "Cvor.h"
#include "Red.h"
#include <cstdlib>
#include <time.h>

class Stablo {
	Cvor *koren;
public:
	int prvi, drugi;
	int kostartuje = 0;
	Stablo(Cvor* kor = nullptr) :koren(kor) {}



	void generisiStablo(int **pocetna) {
		srand(time(NULL));
		prvi = (rand()%2)+1;
		if (prvi == 2) drugi = 1;
		else drugi = 2;
		int broj1kugl=0;
		int broj2kugl=0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				if (pocetna[i][j] == 1) broj1kugl++;
				if (pocetna[i][j] == 2) broj2kugl++;
			}
		if (broj1kugl < broj2kugl) {
			if (prvi == 1) kostartuje = prvi;
			else kostartuje = drugi;
		}
		if (broj2kugl < broj1kugl) {
			if (prvi == 2) kostartuje = prvi;
			else kostartuje = drugi;
		}
		if (broj1kugl == broj2kugl) {
			kostartuje = (rand() % 2) ? prvi : drugi;
		}
		koren = new Cvor(pocetna, kostartuje);
		Red r1;
		Red r2;
		r1.dodaj(koren);
		r2.dodaj(koren);

		while (!(r1.prazan())) {
			Cvor *next = r1.izbrisi();
			for (int j = 0; j < 5; j++) {
				if ((next->red(j)) < 0) {

					continue;
				}
				int **pommatrica = next->sin(next->red(j), j, next->koigra); //pravljenje sina od oca, dodavanjem u zavisnosti ko igra


				if (!(next->najlevsin)) {
					next->najlevsin = new Cvor(pommatrica, ((next->koigra % 2) + 1), nullptr, nullptr, next);
					if (!(next->najlevsin->pobeda(next->red(j), j))) {
						r1.dodaj(next->najlevsin);
						r2.dodaj(next->najlevsin);


					}
					else {
						next->najlevsin->indikator =( (next->koigra == prvi) ? 1 : -1);

					}


				}
				else {
					Cvor *pomocni = next->najlevsin;
					while (pomocni->desnibrat) {
						pomocni = pomocni->desnibrat;

					}
					pomocni->desnibrat = new Cvor(pommatrica, ((next->koigra%2)+1), nullptr, nullptr, next);
					if (!(pomocni->desnibrat->pobeda(next->red(j), j))) {
						r1.dodaj(pomocni->desnibrat);
						r2.dodaj(pomocni->desnibrat);

					}
					else {
						pomocni->desnibrat->indikator =((next->koigra==prvi) ? 1 : -1);


					}


				}



			}


		}
		r2.front = r2.invertliste(); //invertovanje reda r2 koji sadrzi unutrasnje cvorove
		while (!r2.prazan()) {
			Cvor *c = r2.izbrisi();
			if (!(c->najlevsin)) {
				c->indikator = 0;
				continue;
			}
			Cvor *pom = c->najlevsin;
			if (!(c->koigra)) {
				while (pom) {
					if (pom->indikator == -1) {
						c->indikator = -1;
					}
					pom = pom->desnibrat;
				}
				pom = c->najlevsin;
				while (pom) {
					if (pom->indikator == 0) {
						c->indikator = 0;
					}
					pom = pom->desnibrat;
				}
				pom = c->najlevsin;
				while (pom) {
					if (pom->indikator == 1) {
						c->indikator = 1;
					}
					pom = pom->desnibrat;
				}
				pom = c->najlevsin;
			}
			if ((c->koigra)) {
				while (pom) {
					if (pom->indikator == 1) {
						c->indikator = 1;
					}
					pom = pom->desnibrat;
				}
				pom = c->najlevsin;
				while (pom) {
					if (pom->indikator == 0) {
						c->indikator = 0;
					}
					pom = pom->desnibrat;
				}
				pom = c->najlevsin;
				while (pom) {
					if (pom->indikator == -1) {
						c->indikator = -1;
					}
					pom = pom->desnibrat;
				}
				pom = c->najlevsin;
			}


		}



	}

	void Ispis() {
		if (!koren) { cout << "Niste generisali stablo!"; return; }
		Red r;
		Cvor *next = koren;
		r.dodaj(next);
		while (!(r.prazan())) {
			next = r.izbrisi();
			next->ispisimatricu();
			cout << endl;
			cout << next->indikator << endl;
			cout << endl;
			if (next->najlevsin) {
				Cvor *pom = next->najlevsin;
				while (pom) {
					r.dodaj(pom);
					pom = pom->desnibrat;
				}
			}
		}
		cout << endl;
	}

	
	
};