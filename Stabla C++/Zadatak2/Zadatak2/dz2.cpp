#include "Stablo.h"
#include <string>

int main() {
	cout << "Dobrodosli u interaktivni meni!" << endl;
	cout << "ASP DOMACI RTI 18/19" << endl;
	cout << "Milijan Bogdanovic 220/2017 RTI ETF" << endl;
	cout << "crvene kuglice=1, plave kuglice=2" << endl;
	while (1) {
		cout << "Unosite pocetno stanje igre(pocetnu matricu),999 za prekid programa" << endl;
		int **matrica;
		for (int i = 0; i < 5; i++)
			matrica = new int*[5];
		for (int j = 0; j < 5; j++)
			matrica[j] = new int[5];
		int brojac = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				cin >> matrica[i][j];
				if (matrica[i][j] == 999) return 0;
				brojac++;
				if (brojac % 5) cin.get();


			}
		cout << endl;
		cout << "Uneli ste pocetno stanje igre!" << endl;
		cout << "1.Generisite stablo igara sa indikatorima" << endl;
		cout << "2.Ispisite stablo igara sa identifikatorima po level order poretku" << endl;
		cout << "Izaberite zeljenu opciju!" << endl;
		int opcija;
		cin >> opcija;
		Stablo s;
		if (opcija == 1) {
			s.generisiStablo(matrica);
			cout<<"Generisali ste stablo!Opcija 2 za ispis" << endl;
		}
		cin >> opcija;
		if (opcija == 2) {
			cout << "Ispis po level orderu:" << endl;
			int kost= (s.kostartuje == s.prvi) ? s.prvi : s.drugi;
			string tekst = (s.kostartuje == s.prvi) ? "prvi" : "drugi";
			cout << "Startuje " << tekst << "(" << kost << ")" << endl;
			s.Ispis();
		}

		cin.ignore();
		
	}
}