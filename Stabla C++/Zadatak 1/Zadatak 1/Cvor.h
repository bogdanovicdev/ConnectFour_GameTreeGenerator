#pragma once
#include <iostream>
using namespace std;

class Cvor {
	int podatak;
	//Public atributi radi lakseg pristupanja.Za ovaj problem i ove klase enkapsulacija i nema neku svrhu.
public:
	Cvor *najlevsin, *desnibrat, *otac;

public:
	Cvor(int pod, Cvor* najlev=nullptr, Cvor* dbrat=nullptr, Cvor* ot=nullptr) :podatak(pod), najlevsin(najlev), desnibrat(dbrat), otac(ot) {}
	void ispisicvor() {
		cout << podatak << " ";
	}
	Cvor* dohvnajlevsin() const {
		return najlevsin;
	}
	Cvor* dohvdesnibrat() const {
		return desnibrat;
	}

};