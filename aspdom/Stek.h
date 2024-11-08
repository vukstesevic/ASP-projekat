#ifndef _stek_h_
#define _stek_h_
#include<string>
#include<iostream>
using namespace std;

class Stek {
private:
	struct Elem {
		string ime;
		Elem* iduci;
		Elem* prosli;
		Elem(string i, Elem* d=nullptr, Elem* e=nullptr):ime(i), iduci(d), prosli(e){}
	};
	Elem* poslednji = nullptr;
public:
	void PUSH(string naziv);
	string POP();
	Elem* dohvPoslednji() const { return poslednji; }
};
#endif