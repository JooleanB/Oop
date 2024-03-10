#include "Service.h"
#include <algorithm>
vector<Tractor>& Service::get_all() {
	return repo.get_all();
}
void Service::importare() {
	repo.importare();
}

void Service::exportare() {
	repo.exportare();
}

void Service::store(int id, string nume, string tip, int roti) {
	int x=	repo.store(id, nume, tip, roti);
	
	if (x == 0)
		throw std::exception("Nu se poate adauga");
}

void Service::sortare(vector<Tractor>& v) {
	sort(v.begin(), v.end(), [](Tractor& t1, Tractor& t2) {
		return t1.get_denumire() > t2.get_denumire();
		});
}