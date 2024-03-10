#pragma once
#include <string>

using std::string;
class Melodii {
	int id;
	string nume;
	string artist;
	int rank;
public:
	Melodii(const int i, const string n,const string a,const int r) : id{ i }, nume{ n }, artist{ a }, rank{ r } {}
    int get_id() const {
		return id;
	}
	string get_nume() const {
		return nume;
	}
	string get_artist() const {
		return artist;
	}
	int get_rank() const{
		return rank;
	}
	void set_nume(string& n)
	{
		nume = n;
	}
	void set_rank(int& r)
	{
		rank = r;
	}
};