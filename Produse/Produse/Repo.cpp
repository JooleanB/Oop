#include "Repo.h"
#include <fstream>
using namespace std;
void Repo::importare() {
	ifstream fin(filename);
	string line;
	while (1) {
		int id;
		string nume, tip;
		double pret;
		if (!getline(fin, line))
			break;
		id = stoi(line);
		getline(fin, line);
		nume = line;
		getline(fin, line);
		tip = line;
		getline(fin, line);
		pret = stod(line);
		store(id, nume, tip, pret);
	}
	fin.close();
}

void Repo::exportare() {
	ofstream fout(filename);
	for (auto m : all) {
		fout << m.get_id() << "\n" << m.get_nume() << "\n" << m.get_tip() << "\n" << m.get_pret() << "\n";
	}
	fout.close();
}

int Repo:: store(int id, string nume, string tip, double pret) {
	int ok = 0;
	for (auto m : all) {
		if (m.get_id() == id)
		{
			ok = 1;
			break;
		}
	}
	if (nume == "")
		ok = 2;
	if (pret < 1.0 || pret>100.0)
		ok = 3;
	if (ok == 0) {
		Produs p{ id,nume,tip,pret };
		all.push_back(p);
	}
	return ok;
}

vector<Produs>& Repo::get_all() {
	return all;
}