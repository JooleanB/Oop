#pragma once
#include "Melodii.h"
#include <vector>
using namespace std;
class Repo {
	vector<Melodii> melodii;
	public:
	void importare();
	void exportare();
	void store(int id, string titlu, string artist ,string gen);
	void sterge(int id);
	vector<Melodii>& getAll();
};