#include "Repo.h"
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;
vector<Melodii>& Repo::get_toate_melodiile() {
	//cout << toate_melodiile.size();
	return toate_melodiile;
}

int Repo::stergere(int id)
{
	string artist;
	int numar = 0;
	for (auto melodie : toate_melodiile)
		if (melodie.get_id() == id)
		{
			artist = melodie.get_artist();
			break;
		}
	for (auto melodie : toate_melodiile)
		if (melodie.get_artist() == artist)
			numar++;
	if (numar != 1)
	{
		auto it = std::remove_if(toate_melodiile.begin(), toate_melodiile.end(), [&](Melodii& melodie)
			{
				return melodie.get_id() == id;
			}
		);
		toate_melodiile.erase(it, toate_melodiile.end());
		return 1;
	}
	return 0;
}


void Repo::modificare(int id, string nume, int rank)
{
	for (auto& melodie : toate_melodiile)
		if (melodie.get_id() == id)
		{
			melodie.set_nume(nume);
			melodie.set_rank(rank);
			cout << melodie.get_nume() << " " << melodie.get_rank();
			break;
		}
	
}

void Repo::store(int id, string nume, string artist, int rank)
{
	/*int ok = 1;
	for (auto melodie : toate_melodiile)
	{
		cout << melodie.get_nume()<<"\n";
		if (melodie.get_id() == id)
			ok == 0;
	}
	if (rank < 0 || rank>10)
		ok == 0;
	*/
	Melodii m{ id, nume, artist, rank };
	//if (ok == 1)
	toate_melodiile.push_back(m);
	//cout << toate_melodiile.size();
	
}

void Repo::importt()
{
	//cout << "MUIE";
	std::ifstream fin("Melodii.txt");
	std::string line;

	while (1) {
		string nume, artist;
		int id, rank;
		if (!std::getline(fin, line))
			break;
		id = std::stoi(line);
		std::getline(fin, line);
		nume = line;
		std::getline(fin, line);
		artist = line;
		std::getline(fin, line);
		rank = std::stoi(line);
		store(id, nume, artist, rank);
	}
	fin.close();
}

void Repo::exportare()
{
	std::ofstream fout("Melodii.txt");
	std::string line;
	for (auto melodie : toate_melodiile)
	{
		fout << melodie.get_id() << "\n" << melodie.get_nume() << "\n" << melodie.get_artist() << "\n" << melodie.get_rank() << "\n";
	}
}

