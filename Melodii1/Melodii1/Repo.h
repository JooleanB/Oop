#pragma once
#include "Melodii.h"
#include <string>
#include <vector>
using std::vector;
using std::string;
class Repo {
	vector<Melodii> toate_melodiile;
public:
	vector<Melodii>& get_toate_melodiile();
	void store(int id,string nume,string artist,int rank);
	void exportare();
	void importt();
	int stergere(int id);
	void modificare(int id, string nume, int rank);
};