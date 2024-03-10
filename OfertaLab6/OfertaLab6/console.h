#pragma once
#include "Service.h"
#include "Oferta.h"
#include "Service_cos.h"
class ConsolUI {
	Agentie& ctr;
	CosService& cos_serv;
	
	void adaugaUI();
	void stergeUI();
	void modificaUI();
	void cos_addUI();
	void print_cosUI();
	void undo();
	void uiExportToFile();
	
	void tipareste(const vector<Oferta>& pets);
public:
	ConsolUI(Agentie& ctr, CosService& cos_serv) :ctr{ ctr }, cos_serv{ cos_serv } {
	}
	ConsolUI(const ConsolUI& ot) = delete;

	void start();
}; 
