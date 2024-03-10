#pragma once
#define _CRTDBG_MAP_ALLOC
using namespace std;
#include <stdlib.h>
#include <crtdbg.h>
#include <string>

typedef struct Cofetarie {
	string nume;
	string producator;
	int cantitate=0;
}Cofetarie;


Cofetarie creare(string nume, string producator, int cantitate);

Cofetarie copyCofetarie(Cofetarie c);

int validare(Cofetarie c);

void stergere(Cofetarie* c);

void test_creare();
void test_validari();
