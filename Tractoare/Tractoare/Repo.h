#pragma once
#include "Tractor.h"
#include <vector>
#include <string>
using namespace std;
class Repo {
private:
	string filename;
	vector<Tractor> all;
public:
	Repo(string f) : filename{f} {}
	vector<Tractor>& get_all() {
		return all;
	}
	void importare();
	void exportare();
	int store(int id, string nume, string tip, int roti);
};