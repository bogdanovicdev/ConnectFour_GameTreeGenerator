#pragma once
#include "Cvor.h"

class Red {
	struct RedEl {
		Cvor* pok;
		RedEl* sled;
		RedEl(Cvor *p=nullptr, RedEl* s=nullptr) :pok(p), sled(s) {}
	};
	RedEl  *front, *rear;
public:
	Red() {
		front = rear = nullptr;
	}
	//Simuliranje dodavanja novog elementa u neprioritetni red
	void dodaj(Cvor* e) {
		if (!front) front = rear = new RedEl(e);
		else {
			rear->sled = new RedEl(e);
			rear = rear->sled;
		}
		
	}
	//Simuliranje skidanja elementa iz neprioritetnog reda
	Cvor* izbrisi() {
		if (front == nullptr) {
			cout << "Greska!Lista je prazna!";
		}
		else {
			RedEl *old = front;
			Cvor* pom = front->pok;
			front=front->sled;
			if (front == nullptr) rear = nullptr;
			delete old;
			return pom;
		}
	}
	bool prazan() const {
		return ((front == nullptr) && (rear == nullptr));
	}

	//Provera da li radi Red, test metoda
	void ispis() {
		RedEl *temp = front;
		while (temp) {
			temp->pok->ispisicvor();
			temp = temp->sled;
		}
	}


};