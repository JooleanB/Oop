#pragma once
#include <string>
#include <vector>
#include "Joc.h"
using std::vector;
class Repo {
	vector<Joc> all;
public:
	void store(int id, int dim, string tabla, string jucator, string stare);
	void exportare();
	void importare();
	int modificare(int id, int dim, string tabla, string jucator, string stare);
	vector<Joc>& get_all() {
		return all;
	}
};