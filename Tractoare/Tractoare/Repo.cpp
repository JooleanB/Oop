#include "Repo.h"
#include <fstream>
using namespace std;
void Repo::importare()
{
	//cout << "MUIE";
	ifstream fin(filename);
	string line;

	while (1) {
		string nume, tip;
		int id, roti;
		if (!getline(fin, line))
			break;
		id = stoi(line);
		getline(fin, line);
		nume = line;
		getline(fin, line);
		tip= line;
		getline(fin, line);
		roti= stoi(line);
		store(id, nume, tip, roti);
	}
	fin.close();
}

void Repo::exportare() {
	ofstream fout(filename);
	for (auto m : all) {
		fout << m.get_id() << "\n" << m.get_denumire() << "\n" << m.get_tip() << "\n" << m.get_roti() << "\n";
	}
}

int Repo::store(int id, string denumire, string tip, int roti) {
	int ok = 1;
	for (auto m : all) {
		if (m.get_id() == id)
		{
			ok = 0;
			break;
		}
	}
	if (denumire == "")
		ok = 0;
	if (tip == "")
		ok = 0;
	if (roti % 2 != 0 || roti < 2 || roti>16)
		ok = 0;
	if (ok == 1)
	{
		Tractor t { id,denumire,tip,roti };
		all.push_back(t);
	}
	return ok;
}