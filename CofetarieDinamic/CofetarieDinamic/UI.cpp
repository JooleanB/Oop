#include <iostream>
using namespace std;
#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>

#include "Ui.h"
#include "Service.h"
#include "Lista.h"

void testAll()
{
	test_creare();
	test_adaugare();
	test_copiere();
	test_gasire();
	test_modificare();
	test_stergere();
	test_iterare();
	test_creare_vector();

	test_validari();
	test_filtrare1();
	test_ordonare_cresc();
	test_stergere_elem();
	test_filtrare2();
}

void printAll(Lista* v)
{
	if (v->lungime == -1)
		cout<<"Nu exista materie prima. \n";
	else
	{
		cout<<"Cofetariile curente sunt: \n";
		for (int i = 0; i < size(v); i++)
		{
			Cofetarie c = getzi(v, i);
			cout << " Numele: " << c.nume << "| " << " Producator: " << c.producator << " | " << "Cantitatea : " << c.cantitate << endl;
		}
	}
}

void printMenu()
{
	printf("1. Adaugare materie prima. \n");
	printf("2. Actualizare materie prima dupa nume. \n");
	printf("3. Stergere materie prima dupa nume \n");
	printf("4. Vizualizare ordonata -nume - cantitate. \n");
	printf("5. Vizualizare filtrare 1, dupa o cant impusa. \n");
	printf("6. Vizualizare filtrare 2, dupa o litera. \n");
	printf("7. Afisare lista materie prima. \n");
	printf("\n");

}

void adaugare(Lista* v)
{
	int  cant;
	string nume;
	string producator;
	cout << "Numele materiei prime este: ";
	cin >> nume;
	cout<<"Producatorul este : ";
	cin>>producator;
	cout<<"Cantitatea este: ";
	cin >> cant;

	int succes = adaugare_cofetarie(v, nume, producator, cant);
	if (succes)
		cout<<"Materie prima adaugata cu succes. \n";
	else
		cout<<"Materie prima invalida. \n";
}

void uiMODIF(Lista* v)
{
	string nume;
	string producator_nou;
	string nume_nou;
	int cantitate_noua;

	cout << "Numele materiei prime de inlocuit: ";
	cin>> nume;

	cout<<"Numele NOU este : ";
	cin>> nume_nou;
	cout<<"Producatorul NOU este: ";
	cin>>producator_nou;
	cout<<"Cantitatea noua este : ";
	cin>>cantitate_noua;


	int succes = modificare_cofetarie(v, nume, nume_nou, producator_nou, cantitate_noua);
	if (succes)
		cout<<"Materie prima modificata cu succes. \n";
	else
		cout<<"Nu exista materie prima cu datele date. \n";
}


void uiDELETE(Lista* v)
{
	string nume;

	cout<<"Numele materiei prime de sters: \n";
	cin>> nume;

	int succes = stergere_materie_prima(v, nume);
	if (succes)
		cout<<"Materie prima stearsa cu succes. \n";
	else
		cout<<"Nu exista materie prima cu numele dat. \n";
}


void uiOrdonare(Lista* v)
{
	string criteriu, mod;
	cout << "Introduceti un criteriu : ";
	cin >> criteriu;
	cout << "Introduceti un mod: ";
	cin >> mod;
	Lista lista = vizualizare_ord(v,criteriu, mod);
	printAll(&lista);

}

void uiFiltrare1(Lista* v)
{
	int cant;

	cout<<"Cantitatea sub care sa se afle materia prima: \n";
	cin>>cant;

	Lista filtru = filtrare1(v, cant);
	printAll(&filtru);
}


void uiFiltrare2(Lista* v)
{
	string litera;
	cout << "Introduceti litera: \n";
	cin >> litera;
	Lista filtru = filtrare2(v, litera);
	printAll(&filtru);
}

void uiSfarsit(Lista* v)
{
	 stergere_lista(v);
}

void run()
{

	Lista medicam = creare_lista();
	int running = 1;
	while (running)
	{
		printMenu();
		int optiune;
		cout<<"Comanda este: ";
		cin>>optiune;
		switch (optiune)
		{
		case 1:
			adaugare(&medicam);
			break;
		case 2:
			uiMODIF(&medicam);
			break;
		case 3:
			uiDELETE(&medicam);
			break;
		case 4:
			uiOrdonare(&medicam);
			break;
		case 5:
			uiFiltrare1(&medicam);
			break;
		case 6:
			uiFiltrare2(&medicam);
			break;
		case 7:
			printAll(&medicam);
			break;
		case 0:
			uiSfarsit(&medicam);
			running = 0;
			break;
		default:
			printf("Comanda invalida! \n");

		}
	}
}
