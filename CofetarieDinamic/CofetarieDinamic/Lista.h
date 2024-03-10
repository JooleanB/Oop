#pragma once
#include "Cofetarie.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

typedef Cofetarie ElemType;
typedef struct {
	ElemType* elem;
	int lungime;
	int capacitate;

}Lista;

Lista creare_lista();

void stergere_lista(Lista* v);

ElemType getzi(Lista* v, int poz);

ElemType setElem(Lista* v, int poz, ElemType el);

int size(Lista* v);

void adaugare_lista(Lista* v, ElemType el);

ElemType stergere_elem(Lista* v, int poz);

Lista copiere_lista(Lista* v);

void test_stergere_elem();
void test_creare_vector();
void test_iterare();
void test_copiere();