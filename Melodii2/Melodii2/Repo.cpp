#include "Repo.h"
#include <fstream>
#include <assert.h>

void Repo::importare()
{
	//cout << "MUIE";
	std::ifstream fin("Melodii.txt");
	std::string line;

	while (1) {
		string nume, artist,gen;
		int id;
		if (!std::getline(fin, line))
			break;
		id = std::stoi(line);
		std::getline(fin, line);
		nume = line;
		std::getline(fin, line);
		artist = line;
		std::getline(fin, line);
		gen = line;
		store(id, nume, artist, gen);
	}
	fin.close();
}

void Repo::exportare()
{
	ofstream g("Melodii.txt");
	for (const auto& m : melodii) {
		g << m.getId() << " " << m.getTitlu() << " " << m.getArtist() << " " << m.getGen() << endl;
	}
	g.close();
}

void Repo::store(int id, string nume, string artist, string gen)
{
	Melodii melodie{ id,nume,artist,gen };
	int ok = 1;
	for(auto m :melodii)
		if(m.getId()==id)
			ok = 0;
	if(gen!="pop" && gen!="rock" && gen!="folk" && gen!="disco")
		ok = 0;
	if(ok==1)
		melodii.push_back(melodie);
}

void Repo::sterge(int id)
{
	auto it = std::remove_if(melodii.begin(), melodii.end(), [&](Melodii& melodie)
		{
			return melodie.getId() == id;
		}
	);
	melodii.erase(it,melodii.end());
}

vector <Melodii>& Repo::getAll()
{
	return melodii;
}

void testRepo() {
	Repo repo;
	repo.store(1, "nume1", "artist1", "pop");
	repo.store(2, "nume2", "artist2", "rock");
	repo.store(3, "nume3", "artist3", "folk");
	repo.store(4, "nume4", "artist4", "disco");
	assert(repo.getAll().size() == 4);
	repo.sterge(1);
	assert(repo.getAll().size() == 3);
	//repo.exportare();
}