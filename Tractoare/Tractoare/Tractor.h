#pragma once
#include <iostream>
using namespace std;
class Tractor {
private:
	int id;
	string denumire;
	string tip;
	int numar_roti;
public:
	Tractor(int i,string d,string t,int r): id{i},denumire{d},tip{t},numar_roti{r} {}
	int get_id() const {
		return id;
	}
	string get_denumire() const{
		return denumire;
	}
	string get_tip() const{
		return tip;
	}
	int get_roti() const{
		return numar_roti;
	}
};