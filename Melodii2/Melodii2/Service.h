#pragma once
#include "Repo.h"
class Service {
	Repo& repo;
	public:
		Service(Repo& r) : repo(r) {}
		void exportare();
		void store(int id, string titlu, string artist, string gen);
		void sterge(int id);
		vector<Melodii>& getAll();
};