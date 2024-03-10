#include "Service.h"
#include <algorithm>
using std::sort;

void Service::exportare() {
	repo.exportare();
}

void Service::importare() {
	repo.importare();
}

vector <Joc>& Service::get_all() {
	return repo.get_all();
}

void Service::adaugare(int id, int dim, string tabla, string jucator, string stare)
{
	repo.store(id, dim, tabla, jucator, stare);
}

void Service::sortare(vector<Joc>& v)
{
	sort(v.begin(), v.end(), [](Joc& m1, Joc& m2) {
		return m1.get_stare() < m2.get_stare();
		});
}

int Service::modificare(int id, int dim, string tabla, string jucator, string stare)
{
	return repo.modificare(id, dim, tabla, jucator, stare);
}