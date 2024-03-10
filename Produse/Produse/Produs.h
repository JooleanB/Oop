#pragma once
#include <iostream>
#include <string>
using std::string;

class Produs {
private:
	int id;
	string nume;
	string tip;
	double pret;
public:
	Produs(int i,string n,string t,double p):id{i}, nume{n},tip{t}, pret{p} {}
	int get_id() const {
		return id;
	}
    string get_nume() const{
		return nume;
	}
	string get_tip() const {
		return tip;
	}
	double get_pret() const {
		return pret;
	}
};