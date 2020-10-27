#pragma once
#pragma once
#include "Cvor.h"

class Red {
public:
	struct RedEl {
		Cvor* pok;
		RedEl* sled;
		RedEl(Cvor *p = nullptr, RedEl* s = nullptr) :pok(p), sled(s) {}
	};
	friend class Stablo;
	RedEl  *front, *rear;
	Red() {
		front = rear = nullptr;
	}
	void dodaj(Cvor* e) {
		if (!front) front = rear = new RedEl(e);
		else {
			rear->sled = new RedEl(e);
			rear = rear->sled;
		}

	}
	Cvor* izbrisi() {
		if (front == nullptr) {
			cout << "Greska!Lista je prazna!";
			return nullptr;
		}
		else {
			RedEl* old = front;
			Cvor* pom = front->pok;
			front = front->sled;
			if (front == nullptr) rear = nullptr;
			delete old;
			return pom;
		}
	}
	Cvor* dohvati() {
		if (front == nullptr) {
			cout << "Greska! Lista je prazna!";
			return nullptr;
		}
		else {
			Cvor *pom = front->pok;
			front = front->sled;
			if (front == nullptr) rear = nullptr;
			return pom;
		}
	}
	bool prazan() const {
		return ((front == nullptr)&&(rear==nullptr));
	}

	//Provera da li radi Red.
	void ispis() {
		RedEl *temp = front;
		while (temp) {
			temp->pok->ispisimatricu();
			cout << endl;
			temp = temp->sled;
		}
	}
	RedEl* invertliste() {
		RedEl *p =front;
		RedEl *q = nullptr;
		RedEl *r = q;
		while (p != nullptr) {
			r = q;
			q = p;
			p = p->sled;
			q->sled = r;
		}
		rear = front;
		front = q;
		return front;

	}

};