#pragma once
#include "Produs.h"
#include <vector>
using std::vector;
using std::string;

class Repo {
private:
	string filename;
	vector<Produs> all;
public:
	Repo(string f) :filename{ f } {}
	void importare();
	void exportare();
	int store(int id, string nume, string tip, double pret);
	vector<Produs>& get_all();
};