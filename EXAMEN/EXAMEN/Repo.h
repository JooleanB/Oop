#pragma once
#include "Student.h"
#include <vector>
#include <fstream>
#include <sstream>
class Repo
{
    vector<Student> all;
public:
    
    void add(const Student& s1) { all .push_back(s1); }
    vector<Student>& get_all() {
        return  all;
    }
    void importare();
    void exportare();
    void modifica(int value);
    void stergere(int id);
};