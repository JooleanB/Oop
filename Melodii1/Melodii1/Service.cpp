#include "Service.h"
#include <algorithm>


void Service::sortare(vector<Melodii>& v) {
	sort(v.begin(), v.end(), [](Melodii& m1, Melodii& m2) {
		return m1.get_rank() < m2.get_rank();
		});
}

vector<Melodii>& Service::get_all() {
	return repo.get_toate_melodiile();
}

int Service::sterge(int id) {
	return repo.stergere(id);
}

void Service::exportt() {
	repo.exportare();
}

void Service::modifica(int id, string nume, int rank)
{
	repo.modificare(id, nume, rank);
}