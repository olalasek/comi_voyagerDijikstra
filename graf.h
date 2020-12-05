/*
 * graf.h
 *
 *  Created on: 3 gru 2020
 *      Author: olalasek
 */


#ifndef GRAF_H_
#define GRAF_H_
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

struct wezel {
	int x;
	int y;
	char p;
};

float odlegl_pkt (wezel A, wezel B) {
	return sqrt(pow(B.x-A.x,2)+pow(B.y-A.y,2));
}

class graf {
public:
	graf() = default;
	virtual ~graf() = default;

	void dodaj_wezel (wezel W) {
		wezly.push_back(W);
	}

	void wypisz_odleglosci() {
		cout<<"Odleglosc miedzy punktami : \n";
		for (int i = 0; i < wezly.size(); i++) {
			for (int j = i+1; j < wezly.size(); j++) {
				cout<<odlegl_pkt(wezly.at(i), wezly.at(j))<<endl;
			}
		}
	}

	void wypisz() {
		cout<<"Graf: "<<endl;
		for(auto a:wezly) {
			cout<<a.p<<" "<<a.x<<" "<<a.y<<endl;
		}
	}

	float znajdz_sciezke () {
		float dl_sciezki = 0;
		float odleglosc = 0;
		float najkrotsza_odl = 0xffffffffffff;
		int indeks = 0;
		int j = 0;
		for (int i = 0; i < wezly.size()-1; i++) {
			for (j = i+1; j < wezly.size(); j++) {
				odleglosc = odlegl_pkt(wezly.at(i), wezly.at(j));
				if (odleglosc < najkrotsza_odl) {
					najkrotsza_odl = odleglosc;
					indeks = j;
				}
			}
			dl_sciezki += najkrotsza_odl;
			najkrotsza_odl = 0xffffffffffff;
			wezel tmp = wezly[i+1];
			wezly[i+1] = wezly[indeks];
			wezly[indeks] = tmp;
		}
		return dl_sciezki;
	}
private:
	vector <wezel> wezly;
};


#endif /* GRAF_H_ */
