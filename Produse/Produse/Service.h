#pragma once
#include "Repo.h"
#include "Observer.h"
class Service : public Observable {
private:
	Repo& repo;
public:
	Service(Repo& repo) :repo{repo} {}
	void importare();
	void exportare();
	void sortare(vector<Produs>& v);
	void store(int id, string nume, string tip, double pret);
	vector<Produs>& get_all();
	vector<Produs> filtrare_tip(string tip);
};