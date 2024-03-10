#pragma once
#include "Lista.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int adaugare_cofetarie(Lista* v, string nume, string producator, int cantitate);

int stergere_materie_prima(Lista* v, string nume);

int modificare_cofetarie(Lista* v, string nume, string nume_nou, string producator_nou, int cantitate);

int gasire_cofetarie(Lista* v, string nume);

Lista vizualizare_ord(Lista* v, string criteriu,string mod);

Lista filtrare1(Lista* v, int cant_impusa);

Lista filtrare2(Lista* v, string litera);


void test_filtrare2();
void test_adaugare();
void test_gasire();
void test_modificare();
void test_stergere();
void test_filtrare1();
void test_ordonare_cresc();
