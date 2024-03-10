#pragma once
#include "Repo.h"
#include "Melodii.h"
#include <vector>
#include <string>
using std::string;
using std::vector;

class Service {
	Repo& repo;
	
public:
	Service(Repo& r) : repo{ r } {}
	vector<Melodii>& get_all();
	void sortare(vector<Melodii>& v);
	void modifica(int id, string nume, int rank);
	int sterge(int id);
	void exportt();
};