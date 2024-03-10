#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	int nrmatricol;
	string nume;
	int varsta;
	string facultate;
public:
	Student(int nr,string n,int v,string f): nrmatricol{nr},nume{n},varsta{v},facultate{f} {}
	int set_varsta(int x) {
		varsta = x;
	}
	int get_nrmatricol() const {
		return nrmatricol;
	}
	string get_nume()const {
		return nume;
	}
	string get_facultate()const {
		return facultate;
	}
	int get_varsta() const {
		return varsta;
	}
};