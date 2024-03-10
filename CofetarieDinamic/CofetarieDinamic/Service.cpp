#include <iostream>
using namespace std;
#pragma once
#include "Service.h"
#include "Cofetarie.h"
#include "Lista.h"
#include <cassert>
#include <cstring>
#include <stdlib.h>

int adaugare_cofetarie(Lista *v, string nume, string producator,int cantitate){

	Cofetarie c = creare(nume, producator, cantitate);
	int am_reusit = validare(c);
	if (!am_reusit)
	{
		stergere(&c);
		return 0;
	}
	int gasire = -1;
	for (int i = 0; i < v->lungime; i++)
	{
		ElemType* el = &v->elem[i];
		if (c.nume == el->nume)
		{
			gasire = 1;
			if (c.producator == el->producator)
				el->cantitate = el->cantitate+c.cantitate;
		}

	}
	if (gasire == -1)
		adaugare_lista(v, c);
	return 1;
}

int gasire_cofetarie(Lista* v, string nume)
{
	int pozitie = -1;
	for (int i = 0; i < v->lungime; i++)
	{
		Cofetarie c = getzi(v, i);
		if (c.nume == nume)
		{
			pozitie = i;
			break;
		}
	}
	return pozitie;
}

int modificare_cofetarie(Lista* v, string nume, string nume_nou, string producator_nou, int cantitate_noua)
{
	int pozitie = gasire_cofetarie(v, nume);

	if (pozitie != -1)
	{
		Cofetarie m = getzi(v, pozitie);
		Cofetarie medNOU = creare(nume_nou, producator_nou, cantitate_noua);

		setElem(v, pozitie, medNOU);
		return 1;
	}
	else
		return 0;
}

int stergere_materie_prima(Lista* v, string nume)
{
	int pozitie = gasire_cofetarie(v, nume);
	if (pozitie != -1)
	{
		Cofetarie c = stergere_elem(v, pozitie);
		stergere(&c);
		return 1;

	}
	return 0;
}

Lista vizualizare_ord(Lista* v,string criteriu,string mod)
{
	Lista lista = copiere_lista(v);
	for (int i = 0; i < v->lungime - 1; i++)
	{
		for (int j = i + 1; j < v->lungime; j++)
		{
			if (criteriu == "nume" && mod == "cresc")
			{
				if (lista.elem[i].nume.compare(lista.elem[j].nume) < 0)
				{
					Cofetarie cof = lista.elem[i];
					lista.elem[i] = lista.elem[j];
					lista.elem[j] = cof;
				}
			}
			else if(criteriu == "nume" && mod == "descresc")
			{
					if (lista.elem[i].nume.compare(lista.elem[j].nume) > 0)
					{
						Cofetarie cof = lista.elem[i];
						lista.elem[i] = lista.elem[j];
						lista.elem[j] = cof;
					}
			}
			else if (criteriu == "cantitate" && mod == "cresc")
				{
					if (lista.elem[i].cantitate > lista.elem[j].cantitate)
					{
						Cofetarie cof = lista.elem[i];
						lista.elem[i] = lista.elem[j];
						lista.elem[j] = cof;
					}
				}
			else if (criteriu == "cantitate" && mod == "descresc")
				{
					if (lista.elem[i].cantitate < lista.elem[j].cantitate)
					{
						Cofetarie cof = lista.elem[i];
						lista.elem[i] = lista.elem[j];
						lista.elem[j] = cof;
					}
				}
			
		}
			 
	}
	return lista;
}

Lista filtrare1(Lista* v, int cant_impusa)
{
	

	if (cant_impusa > 0)
	{
		Lista lista = creare_lista();
		for (int i = 0; i < v->lungime; i++)
		{
			Cofetarie cof = getzi(v, i);
			if (cof.cantitate < cant_impusa)
				adaugare_lista(&lista, creare(cof.nume, cof.producator, cof.cantitate));
		}
		return lista;
	}
	return copiere_lista(v);
}

Lista filtrare2(Lista* v, string litera)
{
	
	if (litera.length() > 0)
	{
		Lista lista = creare_lista();
		for (int i = 0; i < v->lungime; i++)
		{
			Cofetarie cof = getzi(v, i);
			if (cof.nume.rfind(litera, 0) == 0)
				adaugare_lista(&lista, creare(cof.nume, cof.producator, cof.cantitate));
			
		}
		return lista;
	}
	return copiere_lista(v);
}

void test_filtrare2()
{
	Lista l = creare_lista();
	Lista aux ;
	Lista aux1;
	Lista aux2;

	int succes1 = adaugare_cofetarie(&l, "Gogoasa", "Marius", 25);
	assert(succes1 == 1);

	int succes2 = adaugare_cofetarie(&l, "Clatite", "Mircea", 20);
	assert(succes2 == 1);

	aux = filtrare2(&l, "G");
	assert(size(&aux) == 1);
	aux1 = filtrare2(&l, "a");
	assert(size(&aux1) == 0);
	aux2 = filtrare2(&l, "");
	stergere_lista(&l);
	assert(size(&l) == 0);
	stergere_lista(&aux);
	stergere_lista(&aux1);
	stergere_lista(&aux2);
}

void test_adaugare()
{
	Lista lista_noua = creare_lista();
	int succes1 = adaugare_cofetarie(&lista_noua, "bwa", "marius", 20);
	assert(succes1 == 1);
	int succes2 = adaugare_cofetarie(&lista_noua, "", "marius", 20);
	assert(succes2 == 0);
	int succes3 = adaugare_cofetarie(&lista_noua, "bwa", "marius", -1);
	assert(succes3 == 0);
	assert(size(&lista_noua) == 1);
	int i = 0;
	Cofetarie c = getzi(&lista_noua, i);
	assert(c.nume == "bwa");
	assert(c.producator == "marius");
	assert(c.cantitate == 20);
	int succes4 = adaugare_cofetarie(&lista_noua, "bwa", "marius", 50);
	assert(succes4 == 1);
	Cofetarie cc = getzi(&lista_noua, i);
	assert(cc.cantitate == 70);
	stergere_lista(&lista_noua);
}

void test_gasire()
{
	Lista l = creare_lista();
	int succes1 = adaugare_cofetarie(&l, "Clatite", "Marius", 20);
	assert(succes1 == 1);

	int succes2 = adaugare_cofetarie(&l, "Gogoasa", "Mircea", 20);
	assert(succes2 == 1);

	int pozitie = gasire_cofetarie(&l, "Gogoasa");
	assert(pozitie == 1);

	pozitie = gasire_cofetarie(&l, "bwa");
	assert(pozitie == -1);

	stergere_lista(&l);
	assert(size(&l) == 0);

}

void test_modificare()
{
	Lista l = creare_lista();
	int succes1 = adaugare_cofetarie(&l, "Gogoasa", "Marius", 20);
	assert(succes1 == 1);

	int verif = modificare_cofetarie(&l, "Gogoasa", "Clatita", "Mircea", 5000);
	assert(verif == 1);

	int i = 0;
	Cofetarie m = getzi(&l, i);
	assert(m.nume== "Clatita");
	assert(m.producator== "Mircea");
	assert(m.cantitate == 5000);

	int verif1 = modificare_cofetarie(&l, "Gogoasa", "TRipsi", "BWA", 30);
	assert(verif1 == 0);

	stergere_lista(&l);
}

void test_stergere()
{
	Lista l = creare_lista();

	int succes = adaugare_cofetarie(&l, "Gogoasa", "Marius", 20);
	assert(succes == 1);

	int stergere= stergere_materie_prima(&l, "Gogoasa");
	assert(stergere == 1);
	stergere_lista(&l);
	assert(size(&l) == 0);

	int stergere1 = stergere_materie_prima(&l, "bwa");
	assert(stergere1 == 0);
}

void test_filtrare1()
{
	Lista l = creare_lista();
	Lista aux;
	Lista aux1;

	int succes1 = adaugare_cofetarie(&l, "Gogoasa", "Marius", 25);
	assert(succes1 == 1);

	int succes2 = adaugare_cofetarie(&l, "Clatite", "Mircea", 20);
	assert(succes2 == 1);

	aux = filtrare1(&l, 23);
	assert(size(&aux) == 1);
	aux1 = filtrare1(&l, -3);
	assert(size(&aux1) == size(&l));
	stergere_lista(&l);
	assert(size(&l) == 0);
	stergere_lista(&aux);
	stergere_lista(&aux1);

}

void test_ordonare_cresc()
{
	Lista l = creare_lista();

	int succes1 = adaugare_cofetarie(&l, "Marius", "Gogoasa", 12);
	assert(succes1 == 1);

	int succes2 = adaugare_cofetarie(&l, "aMihai", "Clatita", 20);
	assert(succes2 == 1);

	int succes3 = adaugare_cofetarie(&l, "Xihai", "pepelepe", 5);
	assert(succes3 == 1);

	Lista noua;
	noua = vizualizare_ord(&l,"nume","cresc");

	Cofetarie m = getzi(&noua, 0);
	assert(m.cantitate == 20);

	stergere_lista(&noua);

	Lista noua1;
	noua1 = vizualizare_ord(&l, "nume", "descresc");

	Cofetarie m1 = getzi(&noua1, 0);
	assert(m1.cantitate == 12);

	stergere_lista(&noua1);

	Lista noua2;
	noua2 = vizualizare_ord(&l, "cantitate", "cresc");

	Cofetarie m2 = getzi(&noua2, 0);
	assert(m2.cantitate == 5);

	stergere_lista(&noua2);

	Lista noua3;
	noua3 = vizualizare_ord(&l, "cantitate", "descresc");

	Cofetarie m3 = getzi(&noua3, 0);
	assert(m3.cantitate == 20);

	stergere_lista(&l);
	stergere_lista(&noua3);


}