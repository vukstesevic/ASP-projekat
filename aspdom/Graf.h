#ifndef _graf_h_
#define _graf_h_
#include<string>
#include<iostream>
#include"Stek.h"
using namespace std;

class Graf {
private:
	struct Sused {
		string cvor;
		double tezina;
		Sused* sled;
		Sused(string s, double i, Sused* sled = nullptr) :cvor(s), tezina(i), sled(sled) {}
	};

	struct Cvor {
		string glavniCvor;
		Sused* sused;

		Cvor(string s, Sused* sus = nullptr) : glavniCvor(s), sused(sus) {}

	};

	int brCvorova;
	Cvor** niz;

	void brisiGranu(string ss){
	}


public:
	Graf(int n) : brCvorova(n) {
		niz = new Cvor * [n];
		int i = 0;
		while (i != n) {
			niz[i] = nullptr;
			i++;
		}
	}

	int dohvBr() const { return brCvorova; }

	~Graf();

	void dodajCvor(string* s);

	void ispis() const;

	void dodajGranu(string ime, string sused, double t);

	void dodajCvor(string s);

	void brisiCvor(string ime);

	void brisiGranu(string pocetni, string sused);

	bool* DFS(string ime);

	int nadjiIndeks(string ime);

	Graf inverzovaniGraf();

	friend void CONNCOMP(Graf g1, string cvor);

};
#endif