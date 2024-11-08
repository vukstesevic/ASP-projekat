#include<iostream>
#include<fstream>
#include<string>
#include"Graf.h"
using namespace std;






int main() {
	fstream tekst;
	tekst.open("graf1.txt");
	int brojCvorova, brojGrana;
	tekst >> brojCvorova;
	tekst >> brojGrana;
	string* imena = new string[brojCvorova];
	string ime;
	for (int i = 0; i < brojCvorova; i++) {
		tekst >> ime;
		imena[i] = ime;
	}

	Graf graf(brojCvorova);

	graf.dodajCvor(imena);
	
	
	string imez;
	string sused;
	double t;
	for (int i = 0; i < brojGrana; i++) {
		tekst >> imez;
		tekst >> sused;
		tekst >> t;
		graf.dodajGranu(imez, sused, t);
	}

	CONNCOMP(graf, "podaci");

	//graf.ispis();


	

}