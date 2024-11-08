#include "Stek.h"

void Stek::PUSH(string naziv)
{
	poslednji = new Elem(naziv, nullptr, poslednji);
	if (poslednji->prosli != nullptr)
	{
		poslednji->prosli->iduci = poslednji;
	}
}

string Stek::POP()
{
	if (poslednji != nullptr) {
		string str;
		str = poslednji->ime;
		Elem* pomoc = poslednji;
		poslednji=poslednji->prosli;
		delete pomoc;
		return str;
	}
	cout<<"GRESKA STEK JE PRAZAN";
	return "greska";
}
