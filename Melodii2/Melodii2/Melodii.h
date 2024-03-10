#pragma once
#include <string>
#include <assert.h>
using namespace std;
class Melodii {
	int id;
	string titlu;
	string artist;
	string gen;
public:
	Melodii(int i, string t, string a, string g) : id(i), titlu(t), artist(a), gen(g) {}
	Melodii()=default;
	int getId() const { return id; }
	string getTitlu() const { return titlu; }
	string getArtist() const { return artist; }
	string getGen() const{ return gen; }
	void setTitlu(string t) { titlu = t; }
	void setArtist(string a) { artist = a; }
	void setGen(string g) { gen = g; }

};

void test() {
	Melodii m{ 1,"a","b","c" };
	assert(m.getId() == 1);
	assert(m.getTitlu() == "a");
	assert(m.getArtist() == "b");
	assert(m.getGen() == "c");
	m.setTitlu("d");
	m.setArtist("e");
	m.setGen("f");
	assert(m.getTitlu() == "d");
	assert(m.getArtist() == "e");
	assert(m.getGen() == "f");
}