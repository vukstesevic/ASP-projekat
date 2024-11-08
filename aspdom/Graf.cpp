#include "Graf.h"

void Graf::dodajCvor(string* s)
{
	for (int i = 0; i < brCvorova; i++) {
		niz[i] = new Cvor(s[i]);
	}
}

Graf::~Graf()
{
	for (int i = 0; i < brCvorova; i++) {
		Sused* pom = niz[i]->sused;
		while (pom) {
			Sused* stari = pom;
			pom = pom->sled;
			delete stari;
		}
		delete niz[i];
		}
	delete[] niz;
}

void Graf::dodajCvor(string s)
{
	Cvor** niz1 = new Cvor * [brCvorova+1];
	for (int i = 0; i < brCvorova; i++) {
		niz1[i] = niz[i];
	}
	niz1[brCvorova] = new Cvor(s);
	delete[] niz;
	niz = niz1;
	brCvorova++;

}

void Graf::brisiCvor(string ime) 
{
	int i = 0;
	for (i; i < brCvorova; i++) {
		if (ime == niz[i]->glavniCvor) {
			Sused* pom = niz[i]->sused;
			while (pom) {
				Sused* stari = pom;
				pom = pom->sled;
				delete stari;
			}
			delete niz[i];
			break;
		}
	}
	for (i; i < brCvorova; i++) {
		niz[i] = niz[i + 1];
	}
	brCvorova--;
	for (int j = 0; j < brCvorova; j++) {
		Sused* susedni = niz[j]->sused;
		Sused* pomocni = susedni;
		while (susedni) {
			if (susedni->cvor == ime) {
				if (pomocni == susedni) {
					niz[j]->sused = susedni->sled;
					delete susedni;
				}
				else {
					pomocni->sled = susedni->sled;
					delete susedni;
				}
				break;
			}
			pomocni = susedni;
			susedni = susedni->sled;
		}
	}
}

void Graf::brisiGranu(string pocetni, string sused)
{
	for (int i = 0; i < brCvorova; i++) {
		if (niz[i]->glavniCvor == pocetni) {
			Sused* sus = niz[i]->sused;
			Sused* pom = sus;
			while (sus->cvor != sused) {
				pom = sus;
				sus = sus->sled;
			}
			if (pom == sus) {
				niz[i]->sused = sus->sled;
				delete sus;
			}
			else {
				pom->sled = sus->sled;
				delete sus;
				}
		}
	}
}


void Graf::ispis() const {
	for (int i = 0; i < brCvorova; i++) {
		cout << niz[i]->glavniCvor << " ";
		if (niz[i]->sused != nullptr) {
			Sused* pom = niz[i]->sused;
			while (pom) {
				cout << "->" << pom->cvor << " " << pom->tezina << " ";
				pom = pom->sled;
			}
			cout << endl;
		}
		else { cout << endl; }
	}
}

void Graf::dodajGranu(string ime, string sused, double t) {
	for (int i = 0; i < brCvorova; i++) {
		if (niz[i]->glavniCvor == ime) {
			if (niz[i]->sused == NULL) {
				niz[i]->sused = new Sused(sused, t);
				break;
			}
			else {
				Sused* s = niz[i]->sused;
				while (s->sled) { s = s->sled; }
				s->sled = new Sused(sused, t);
				break;
			}
		}
	}
}

bool* Graf::DFS(string ime) 
{
	bool* poseta = new bool[brCvorova];
	for (int i = 0; i < brCvorova; i++) {
		poseta[i] = false;
	}
	Stek stek;
	stek.PUSH(ime);
	while (stek.dohvPoslednji()) {
		string v = stek.POP();
		int j = nadjiIndeks(ime);
		if (poseta[j] == false) {
			poseta[j] = true;
		}
		Sused* pom = niz[j]->sused;
		while (pom) {
			int ind = nadjiIndeks(pom->cvor);
			if (poseta[ind] == false) {
				stek.PUSH(pom->cvor);
			}
			pom = pom->sled;
		}
	}
	return poseta;
}


int Graf::nadjiIndeks(string ime)
{
	for (int i = 0; i < brCvorova; i++) {
		if (ime == niz[i]->glavniCvor) {
			return i;
		};
	}
	return -1;
}

Graf Graf::inverzovaniGraf()
{
	Graf g1(brCvorova);
	for (int i = 0; i < brCvorova; i++){
		g1.niz[i] = this->niz[i];
	}
	for (int i = 0; i < brCvorova; i++) {
		g1.niz[i]->sused = nullptr;
	}
	for (int i = 0; i < brCvorova; i++) {
		Sused* pom = niz[i]->sused;
		while (pom) {
			g1.dodajGranu(pom->cvor, niz[i]->glavniCvor, pom->tezina);
		}
	}
	return g1;
}

void CONNCOMP(Graf g1, string cvor)
{
	Graf g2 = g1.inverzovaniGraf();
	bool* b1 = g1.DFS(cvor);
	bool* b2 = g2.DFS(cvor);
	for (int i = 0; i < g1.dohvBr(); i++) {
		if (b1[i] == b2[i]) {
			cout << g1.niz[i]->glavniCvor << ' ';
		}
	}

}
