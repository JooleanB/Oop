#include "Service.h"
#include <algorithm>


void Service::importare() {
	repo.importare();
}
void Service::exportare() {
	repo.exportare();
}

void Service::store(int id, string nume, string tip, double pret) {
	int ok = repo.store(id, nume, tip, pret);
	if (ok == 1)
		throw std::exception("ID-UL EXISTA DEJA");
	if (ok == 2)
		throw std::exception("NUMELE NU POATE SA FIE VID");
	if (ok == 3)
		throw std::exception("PRETUL TREBUIE SA FIE INTRE 1.0 SI 100.0");
}

vector <Produs>& Service::get_all() {
	return repo.get_all();
}

void Service::sortare(vector<Produs>& v) {
	sort(v.begin(), v.end(), [](Produs& p1, Produs& p2) {
		return p1.get_pret() < p2.get_pret();
		});
}

vector <Produs> Service::filtrare_tip(string tip) {
	vector <Produs> v;
	for (auto m : get_all())
		if (m.get_tip() == tip)
			v.push_back(m);
	return v;

}
