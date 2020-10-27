#include "Cvor.h"
#include "Red.h"
#include <cmath>

class Stablo {
public:
	Cvor *koren;
	int m;
public:
	Stablo(int m1, Cvor* kor = nullptr) :m(m1), koren(kor) {}


	Stablo& dodajcvor(const int pod) {
		bool nadjen = false;
		while (!nadjen) {
			if (!koren) {
				koren = new Cvor(pod, nullptr, nullptr, nullptr);
				nadjen = true;
			}
			else {
				Red r;
				r.dodaj(koren);
				while (!r.prazan()) {
					Cvor *next = r.izbrisi();
					if (!next->najlevsin) {
						next->najlevsin = new Cvor(pod, nullptr, nullptr, next);
						nadjen = true;
						break;
					}
					else {
						Cvor *sirinski = next->najlevsin;
						int brojac = 1;
						while (sirinski->desnibrat) {
							brojac++;
							r.dodaj(sirinski);
							sirinski = sirinski->desnibrat;
						}
						r.dodaj(sirinski);
						if (brojac < m) {
							sirinski->desnibrat = new Cvor(pod, nullptr, nullptr, next);
							nadjen = true;
							break;
						}
					}

				}



			}
		}
		return *this;
	}
	
	//Ispis u redu po Level Orderu
	void LevelOrderIspis() const {
		if (!koren) { cout << "Stablo je prazno!"<<endl; return;}
		Red r;
		Cvor *next = koren;
		r.dodaj(next);
		while (!(r.prazan())) {
			next = r.izbrisi();
			next->ispisicvor();
			
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
	int  brojcvorova() {
		if (!koren) {return 0; }
		int brojc=0;
		Red r;
		Cvor *next = koren;
		r.dodaj(next);
		while (!(r.prazan())) {
			next = r.izbrisi();
			brojc++;

			if (next->najlevsin) {
				Cvor *pom = next->najlevsin;
				while (pom) {
					r.dodaj(pom);
					pom = pom->desnibrat;
				}
			}
			
		}
		return brojc;

	}
	int visinastabla() {
		int h = 0;
		int prev = 0;
		while ((prev+pow(m, h)) < brojcvorova()) {
			prev += pow(m, h);
			h++;
		}
		return h;
	}
	void obrisiStablo() {
		if (!koren) {
			cout << "Stablo je vec prazno!";
			return;
		}
		Red r;
		Cvor *next = koren;
		r.dodaj(next);
		while (!r.prazan()) {
			next = r.izbrisi();
			if (next->najlevsin) {
				Cvor *old = next;
				while (old->desnibrat) {
					r.dodaj(old);
					old = old->desnibrat;

				}
				delete old;
			}
			
		}
		koren = nullptr;

		cout << "Uspesno ste obrisali stablo!" << endl;
	}
	int visinacvora(Cvor *c) {
		int visina = 0;
		while (c != koren) {
			c = c->otac;
			visina++;
		}
		return visina;
	}
	
	void ispisStabla() {
		if (!koren) { cout << "Stablo je prazno!" << endl; return; }
		Red r;
		int brojac=0,prev=0;
		Cvor *next = koren;
		r.dodaj(next);
		cout << "Koren:";
		while (!(r.prazan())) {
			next = r.izbrisi();
			next->ispisicvor();
			brojac++;
			if ((brojac % m)==1) cout << ",";
			if (brojac == (prev + pow(m, visinacvora(next)))) {
				cout << endl;
				cout << "H=" << visinacvora(next) + 1 << ": ";
				prev = brojac;
			}
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