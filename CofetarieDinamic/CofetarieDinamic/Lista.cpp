#pragma once
#include "Lista.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <cstdlib>
Lista creare_lista() {
	Lista v;
	v.lungime = 0;
	v.capacitate = 2;
	v.elem = new ElemType[v.capacitate];
	return v;
}

ElemType getzi(Lista* v, int poz)
{
	return v->elem[poz];
}

void stergere_lista(Lista* v)
{
	for (int i = 0; i < v->lungime; i++)
	{
		ElemType el = getzi(v, i);
		stergere(&el);
	}
	v->lungime = 0;
	delete[] v->elem;
}



ElemType setElem(Lista* v, int poz, ElemType el) {
	ElemType  replacedElement = v->elem[poz];
	v->elem[poz] = el;
	return replacedElement;
}

int size(Lista* v) {
	return v->lungime;
}

void adaugare_lista(Lista* v, ElemType el) {
		if (v->lungime == v->capacitate)
		{
			int capacitate_noua = v->capacitate * 2;
			ElemType* aux_elem = new ElemType[capacitate_noua];
			for (int i = 0; i < v->lungime; i++)
				aux_elem[i] = v->elem[i];
			delete[] v->elem;
			v->elem = aux_elem;
			v->capacitate = capacitate_noua;
		}
		v->elem[v->lungime] = el;
		v->lungime++;
}

ElemType stergere_elem(Lista* v, int poz) {
	int i;
	ElemType el = v->elem[poz];
	for (i = poz; i < v->lungime - 1; i++)
		v->elem[i] = v->elem[i + 1];
	v->lungime--;
	return el;
}

Lista copiere_lista(Lista* v)
{
	int i;
	Lista v_copie = creare_lista();
	for (i = 0; i < v->lungime; i++)
	{
		ElemType el = getzi(v, i);
		adaugare_lista(&v_copie, copyCofetarie(el));
	}

	return v_copie;
}

void test_stergere_elem()
{
	Lista v = creare_lista();
	Cofetarie c1 = creare("bwa", "mm", 15);
	Cofetarie c2 = creare("mihaie", "abc", 20);
	Cofetarie c3 = creare("cf", "sdnajk", 200);
	Cofetarie c4 = creare("shbajd", "sdasjhjk", 200);

	adaugare_lista(&v, c1);
	adaugare_lista(&v, c2);
	adaugare_lista(&v, c3);
	adaugare_lista(&v, c4);
	stergere_elem(&v, 0);
	stergere_lista(&v);
}

void test_creare_vector()
{
	Lista v = creare_lista();
	assert(size(&v) == 0);
	stergere_lista(&v);
}

void test_iterare()
{
	Lista v = creare_lista();
	Cofetarie c1 = creare("bwa", "mm", 15);
	Cofetarie c2 = creare("mihaie", "abc", 20);
	Cofetarie c3 = creare("cf", "sdnajk", 200);

	adaugare_lista(&v, c1);
	adaugare_lista(&v, c2);
	adaugare_lista(&v, c3);

	assert(size(&v) == 3);
	Cofetarie m = getzi(&v, 0);

	assert(m.nume == "bwa");
	assert(m.cantitate == 15);
	assert(m.producator=="mm");

	stergere_lista(&v);
	assert(size(&v) == 0);
}

void test_copiere()
{
	Lista v1 = creare_lista();
	adaugare_lista(&v1, creare("bwa", "bro", 30));
	adaugare_lista(&v1, creare("mihaie", "italia", 30));
	assert(size(&v1) == 2);
	Lista v2 = copiere_lista(&v1);
	assert(size(&v2) == 2);
	Cofetarie m = getzi(&v2, 0);
	assert(m.nume== "bwa");
	stergere_lista(&v1);
	stergere_lista(&v2);
}