#pragma once
#include <iostream>
using namespace std;


class Cvor {
public:
	int **matrica,koigra,indikator;
	Cvor *najlevsin, *desnibrat, *otac;

	Cvor(int **m, int ko, Cvor* najlev = nullptr, Cvor* dbrat = nullptr,
		Cvor* ot = nullptr, int ind = 2) :koigra(ko),
		najlevsin(najlev), desnibrat(dbrat), otac(ot),
		 indikator(ind) {
		for (int i = 0; i < 5; i++)
			matrica = new int*[5];
		for (int j = 0; j < 5; j++)
			matrica[j] = new int[5];
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				matrica[i][j] = m[i][j];

	}
	void ispisimatricu() {
		int brojac = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				cout << matrica[i][j]<< " ";
				brojac++;
				if ((brojac % 5) == 0) cout << endl;
			}
	}

	int pobeda(int i, int j) {
		//horizontalno
		if ((j >= 0) && (j <= 2)&&(i>=0)&&(i<=4)) {
			if ((matrica[i][j] == matrica[i][j + 1]) && (matrica[i][j + 1] == matrica[i][j + 2]))
				return 1;
		}
		if ((j >= 1) && (j <= 3)&&(i>=0)&&(i<=4)) {
			if ((matrica[i][j] == matrica[i][j - 1]) && (matrica[i][j - 1] == matrica[i][j + 1]))
				return 1;
		}
		if ((j >= 2) && (j <= 4)&&(i>=0)&&(i<=4)) {
			if ((matrica[i][j] == matrica[i][j - 1]) && (matrica[i][j - 1] == matrica[i][j - 2]))
				return 1;
		}
		//vertikalno
		if ((i >= 0) && (i <= 2)&&(j>=0)&&(j<=4)) {
			if ((matrica[i][j] == matrica[i + 1][j]) && (matrica[i + 1][j] == matrica[i + 2][j]))
				return 1;
		}
		//levo dijagonalno
		if ((i <= 2) && (i >= 0) && (j >= 2) && (j <= 4)) {
			if ((matrica[i][j] == matrica[i + 1][j - 1]) && (matrica[i + 1][j - 1] == matrica[i + 2][j - 2]))
				return 1;
		}
		if ((j >= 1) && (j <= 3) && (i >= 1) && (i <= 3)) {
			if ((matrica[i][j] == matrica[i + 1][j - 1]) && (matrica[i + 1][j - 1] == matrica[i - 1][j + 1]))
				return 1;
		}
		if ((j >= 0) && (j <= 2) && (i >= 2) && (i <= 4)) {
			if ((matrica[i][j] == matrica[i - 1][j + 1]) && (matrica[i - 1][j + 1] == matrica[i - 2][j + 2]))
				return 1;
		}
		//desno dijagonalno
		if ((i <= 2) && (j <= 2) && (i >= 0) && (j >= 0)) {
			if ((matrica[i][j] == matrica[i + 1][j + 1]) && (matrica[i + 1][j + 1] == matrica[i + 2][j + 2]))
				return 1;
		}
		if ((j >= 1) && (j <= 3) && (i >= 1) && (i <= 3)) {
			if ((matrica[i][j] == matrica[i + 1][j + 1]) && (matrica[i + 1][j + 1] == matrica[i - 1][j - 1]))
				return 1;
		}
		if ((j >= 2) && (j <= 4) && (i >= 2) && (i <= 4)) {
			if ((matrica[i][j] == matrica[i - 1][j - 1]) && (matrica[i - 1][j - 1] == matrica[i - 2][j - 2]))
				return 1;
		}
		return 0;
	}
	int red(int j) { //metoda uzima red j matrice i vraca indeks u kom se redu nalazi prvo mesto u koloni j
		int slobodnomesto = 4;
		while (matrica[slobodnomesto][j]) {
			slobodnomesto--;
			if (slobodnomesto < 0) return -1;
		}
		return slobodnomesto;
	}
		
		
	
	int ** sin(int slobodnored,int kolona,int koigra) {
		int **pom;
		for (int i = 0; i < 5; i++)
			pom = new int*[5];
		for (int j = 0; j < 5; j++)
			pom[j] = new int[5];
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				pom[i][j] = matrica[i][j];
		pom[slobodnored][kolona] = koigra;
		return pom;
	}

	

};