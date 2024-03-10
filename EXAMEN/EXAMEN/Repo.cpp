#include "Repo.h"
void Repo::importare() {
    all.clear();
    ifstream f("input.txt");
    string line;
    while (getline(f, line)) {
        string nume, facultate;
        int id = 0, varsta = 0;
        stringstream linestream(line);
        string curent;
        int nr = 0;
        while (getline(linestream, curent, ',')) {

            if (nr == 0)
                id = stoi(curent);
            if (nr == 1)
                nume = curent;
            if (nr == 2)
                varsta = stoi(curent);
            if (nr == 3)
                facultate = curent;
            nr++;
        }
        all.push_back(Student(id, nume, varsta, facultate));
    }
    f.close();
}

void Repo::exportare() {
    ofstream fout("input.txt");
    for (auto& s : all) {
        fout << s.get_nrmatricol() << "," << s.get_nume() << "," << s.get_varsta() << "," << s.get_facultate() << "\n";
    }
    fout.close();
}

void Repo::modifica(int value) {
    vector<Student> noul_all;
    for (auto it = all.begin(); it != all.end(); it++) {
        noul_all.push_back(Student(it->get_nrmatricol(), it->get_nume(), it->get_varsta() + value, it->get_facultate()));
    }
    this->all = noul_all;
}

void Repo::stergere(int id) {

    for (auto it = all.begin(); it != all.end(); it++) {
        if (it->get_nrmatricol() == id) {
            all.erase(it);
            break;
        }
    }
}