#include "Stablo.h"

int main() {
	cout << "INTERAKTIVNI MENI-IMPLEMENTACIJA M-ARNOG STABLA" << endl << endl;
	cout << "DOMACI ZADATAK ALGORITMI I STRUKTURE PODATAKA" << endl << endl;
	cout << "Milijan Bogdanovic 220/2017 RTI" << endl;
	cout << "Izaberite redni broj operacije koju zelite:" << endl;
	cout << "1.Dodavanje cvora:" << endl;
	cout << "2.Prolazak kroz stablo po level-order poretku:" << endl;
	cout << "3.Broj cvorova u stablu:" << endl;
	cout << "4.Visina stabla:" << endl;
	cout << "5.Ispis stabla:" << endl;
	cout << "6.Brisanje stabla:" << endl;
	cout << "Pritisnite 0 za zavrsetak programa" << endl;
	cout << "Napravite stablo, unesite stepen(m) stabla" << endl;
	
	int m;
	cin >> m;
	while (m < 2) {
		cout << "Nedozvoljen stepen stabla!" << endl;
		cout << "Napravite stablo, unesite stepen(m) stabla" << endl;
		cin >> m;
	}
	
	Stablo s(m);
	cout << "Izaberite zeljenu opciju:" << endl;
	int opcija;
	cin >> opcija;

	while (opcija != 0) {
		bool ispravanunos = false;
		if (opcija == 1) {
			cout << "Unesite podatak cvora koji zelite da dodate:" << endl;
			int podatak;
			cin >> podatak;
			s.dodajcvor(podatak);
			cout << "Dodali ste cvor " << podatak << "!" << endl;
			ispravanunos = true;
		}
		if (opcija == 2) {
			s.LevelOrderIspis();
			ispravanunos = true;
		}
		if (opcija == 3) {
			cout<<s.brojcvorova()<<endl;
			ispravanunos = true;
		}
		if (opcija == 4) {
			cout<<s.visinastabla()<<endl;
			ispravanunos = true;
		}
		if (opcija == 5) {
			s.ispisStabla();
			ispravanunos = true;
		}
		if (opcija == 6) {
			s.obrisiStablo();
			ispravanunos = true;
		}
		if (!(ispravanunos)) cout << "Neispravan unos!" << endl;
		cout << "Izaberite zeljenu opciju:" << endl;
		cin >> opcija;
	}
	
}