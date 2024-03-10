#include "Service.h"
#include <algorithm>
void Service::exportare() {
	repo.exportare();
}

void Service::importare() {
	repo.importare();
}

void Service::store(int nrmatricol, string nume, int varsta, string facultate) {
	repo.add(Student(nrmatricol,  nume,  varsta, facultate));
}
void Service::stergere(int nrmatricol) {
	repo.stergere(nrmatricol);
}

void Service::sortare(vector <Student>& v) {
	sort(v.begin(), v.end(), [](Student& s1, Student& s2) {
		return s1.get_varsta() < s2.get_varsta();
		});
}