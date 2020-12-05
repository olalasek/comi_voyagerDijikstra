//============================================================================
// Name        : comi_voyager.cpp
// Author      : Olga Lasek
// Version     : 1.0
// Copyright   : beerMe copyright - If you copy my code, you have to buy me a beer if we meet
// Description : zad1 AI 2020, sem. V, shortest path - Dijkstra algorithm, Ansi-style
//============================================================================

#include <iostream>
#include "graf.h"

using namespace std;

int main() {

	cout<<"Podaj ilość punktów: \n";
	int ilosc = 0;
	cin>>ilosc;
	cout<<"Podaj punkty: \n";

	graf G;

	while (ilosc--) {
		int a = 0, b = 0;
		char p='\0';
		cin>>p>>a>>b;
		wezel W {a,b,p};
		G.dodaj_wezel(W);
	}
	//G.wypisz_odleglosci();
	cout<<"Najkrótsza ścieżka: \n" <<G.znajdz_sciezke()<<endl;
	G.wypisz();
	return 0;
}
