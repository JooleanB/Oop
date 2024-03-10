#pragma once
#include "Repo.h"
class Service {
	Repo& repo;
public:
	Service(Repo& r) : repo{r} {}
	vector<Joc>& get_all();
	void sortare(vector<Joc>& v);
	int modificare(int id, int dim, string tabla, string jucator, string stare);
	void adaugare(int id, int dim, string tabla, string jucator, string stare);
	void exportare();
	void importare();
};