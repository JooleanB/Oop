#pragma once
#include <string>
#include <assert.h>
#include <stdlib.h>
#include "Cofetarie.h"

Cofetarie creare(string nume, string producator, int cantitate)
{
	Cofetarie cof;
	cof.nume = nume;
	cof.producator = producator;
	cof.cantitate = cantitate;
	return cof;
}

void stergere(Cofetarie* c)
{
	c->nume.erase();
	c->producator.erase();
	//delete c->nume;
	//delete c->producator;
	c->cantitate = -1;
}

Cofetarie copyCofetarie(Cofetarie m)
{
	return creare(m.nume, m.producator, m.cantitate);
}

int validare(Cofetarie c)
{
	if (c.nume.empty())
		return 0;
	if (c.producator.empty())
		return 0;
	if (c.cantitate < 0)
		return 0;
	return 1;
}

void test_creare()
{
	Cofetarie c1 = creare("bwa", "mm", 15);
	assert(c1.nume == "bwa");
	assert(c1.producator == "mm");
	assert(c1.cantitate == 15);
	stergere(&c1);
}

void test_validari()
{
	Cofetarie c1 = creare("", "Marius", 10);
	assert(validare(c1) == 0);
	Cofetarie c2 = creare("bwa", "", 10);
	assert(validare(c2) == 0);
	Cofetarie c3 = creare("bwa", "Marius", -1);
	assert(validare(c3) == 0);
	Cofetarie c4 = creare("bwa", "Marius", 10);
	assert(validare(c4) == 1);
	stergere(&c1);
	stergere(&c2);
	stergere(&c3);
	stergere(&c4);
}