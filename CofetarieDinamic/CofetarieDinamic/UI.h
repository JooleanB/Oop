#pragma once
#include "Service.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>

/*
* printeaza toate medicamentele
*
*/
void testAll();

void printAll(Lista* v);

/*
* printeaza meniu de optiuni
*/
void printMenu();

/*
*
*/
void adaugare(Lista* v);

/*
*
*/
void uiMODIF(Lista* v);

/*
*
*/
void uiDELETE(Lista* v);

/*
*
*/
//void uiFiltrare1(MyList* v);

/*
*
*/
//void uiFiltrare2(MyList* v);

/*
*
*/
//void uiOrdonare(MyList* v);

/*
*
*/
void run();