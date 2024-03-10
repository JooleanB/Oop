#pragma once
#include "Repo.h"
class Service {
	Repo& repo;
public:
	Service(Repo& repo) : repo{repo} {}
	void importare();
	void exportare();
	void store(int nrmatricol, string nume, int varsta, string facultate);
	void stergere(int nrmatricol);
	vector <Student>& get_all() {
		return repo.get_all();
	}
	void sortare(vector<Student>& v);
	//void undo();
	//void redo();
};