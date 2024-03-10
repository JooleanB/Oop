#include "Repo.h"
#include <fstream>
void Repo::exportare()
{
	std::ofstream fout("Joc.txt");
	for (auto j : all)
		fout << j.get_id() << "\n" << j.get_dim() << "\n" << j.get_tabla() << "\n" << j.get_jucator() << "\n" << j.get_stare() << "\n";
}

void Repo::importare()
{
	//cout << "MUIE";
	std::ifstream fin("Joc.txt");
	std::string line;

	while (1) {
		string tabla, jucator,stare;
		int id, dim;
		if (!std::getline(fin, line))
			break;
		id = std::stoi(line);
		std::getline(fin, line);
		dim = std::stoi(line);
		std::getline(fin, line);
		tabla = line;
		std::getline(fin, line);
		jucator = line;
		std::getline(fin, line);
		stare = line;
		store(id, dim,tabla,jucator,stare);
	}
	fin.close();
}

void Repo::store(int i, int d, string t, string j, string s) {
	Joc joc{ i,d,t,j,s };
	int ok = 1;
	for (auto j : all)
		if (j.get_id() == joc.get_id())
			ok = 0;
	if (joc.get_dim() < 3 || joc.get_dim() > 5)
		ok = 0;
	if (joc.get_tabla().length() != joc.get_dim() * joc.get_dim())
		ok = 0;
	if (joc.get_jucator() != "0" && joc.get_jucator() != "X")
		ok = 0;
	if (joc.get_stare() != "Terminat" && joc.get_stare() != "In derulare" && joc.get_stare() != "Neinceput")
		ok = 0;
	if (ok == 1)
		all.push_back(joc);
}

int Repo::modificare(int id, int dim, string tabla, string jucator, string stare)
{
	int ok = 1;
	if (dim < 3 || dim > 5)
		ok = 0;
	if (tabla.length() != dim * dim)
		ok = 0;
	if (jucator != "0" && jucator != "X")
		ok = 0;
	if (stare != "Terminat" && stare != "In derulare" && stare != "Neinceput")
		ok = 0;
	if (ok == 1)
		for(auto& j :all)
			if (j.get_id() == id)
			{
				j.set_jucator(jucator);
				j.set_stare(stare);
				j.set_tabla(tabla);
			}
	return ok;
}