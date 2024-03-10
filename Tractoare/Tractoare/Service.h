#pragma once
#include "Repo.h"
class Service {
private:
	Repo& repo;
public:
	Service(Repo& repo) :repo{repo} {}
	vector<Tractor>& get_all();
	void importare();
	void exportare();
	void store(int id, string denumire, string tip, int roti);
	void sortare(vector <Tractor>& t);
};