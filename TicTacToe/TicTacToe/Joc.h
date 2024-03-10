#pragma once
#include <string>
using std::string;
class Joc {
	int id;
	int dim;
	string tabla;
	string jucator;
	string stare;
public:
	Joc()= default;
	Joc(int i,int d,string t,string j,string s) : id{i},dim{d},tabla{t},jucator{j},stare{s} {}
	int get_id() const{
		return id;
	}
	int get_dim() const{
		return dim;
	}
	string get_jucator() const{
		return jucator;
	}
	string get_tabla() const{
		return tabla;
	}
	string get_stare() const{
		return stare;
	}
	void set_tabla(string t)
	{
		tabla = t;
	}
	void set_stare(string s)
	{
		stare = s;
	}
	void set_jucator(string c) {
		jucator = c;
	}
};