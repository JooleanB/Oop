#include "console.h"

#include "Oferta.h"
#include "Service_cos.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;

void ConsolUI::tipareste(const vector<Oferta>& oferte) {
	cout << "Oferte:\n";
	for (const auto& oferta : oferte) {
		cout << ' ' << oferta.getDenumire() << ' ' << oferta.getDestinatie() << ' ' << oferta.getTip() <<' '<<oferta.getPret()<< '\n';
	}
	cout << "Sfarsit lista \n";
}

void ConsolUI::adaugaUI() {
	string n,d,t;
	int pret;
	cout << "Dati Denumire:";
	cin >> n;
	cout << "Dati Destinatie:";
	cin >> d;
	cout << "Dati Tip:";
	cin >> t;
	cout << "Dati pret:";
	cin >> pret;
	ctr.addOferta(n, d,t, pret);
	cout << "Adaugat cu succes\n";
}

void ConsolUI::stergeUI() {
	string n, d;
	cout << "Dati Denumire:";
	cin >> n;
	cout << "Dati Destinatie:";
	cin >> d;
	ctr.stergeOferta(n, d);
	cout << "Stergere reusita\n";
}

void ConsolUI::modificaUI() {
	string n, d, n_nou,d_nou,t;
	int pret;
	cout << "Dati Denumire:";
	cin >> n;
	cout << "Dati Destinatie:";
	cin >> d;
	cout << "Dati Denumire noua:";
	cin >> n_nou;
	cout << "Dati Destinatie noua:";
	cin >> d_nou;
	cout << "Dati Tip nou:";
	cin >> t;
	cout << "Dati pret nou:";
	cin >> pret;
	ctr.modificaOferta(n, d, n_nou, d_nou, t, pret);
	cout << "Modificat cu succes\n";
}

void ConsolUI::cos_addUI()
{
	string denumire, destinatie;
	cout << "Introduceti denumirea: ";
	cin >> denumire;
	cout << "Introduceti destinatia: ";
	cin >> destinatie;

	try
	{
		cos_serv.cos_add_service(denumire, destinatie);
		cout << "Produs adaugat cu succes in cos!\n";
	}
	catch (const OfertaException& eroare)
	{
		cout << eroare << "\n";
	}
	catch (ValidateException eroare)
	{
		cout << eroare << '\n';
	}
}

void ConsolUI::print_cosUI()
{
	vector<Oferta> all = cos_serv.cos_get_all_service();
	if (all.size() == 0)
	{
		cout << "Cosul este gol!\n";
		return;
	}
	int i = 0;
	for (const auto& product : all)
	{
		cout << "-> " << product.getDenumire() << " | " << product.getDestinatie() << '\n';
		i++;
	}
}

void ConsolUI::undo()
{
	try {
		ctr.undo();
		cout << "Undo done!" << std::endl;
	}
	catch (OfertaException& sE) {
		cout << sE << std::endl;
	}
}


void ConsolUI::uiExportToFile() {
	string fileName;
	cout << "Nume fisier: ";
	cin >> fileName;
	while (true) {
		string option;
		cout << "Doriti sa exportati fisierul in format CSV sau in format HTML? Tastati 'exit' pentru iesire: ";
		cin >> option;
		if (option == "exit") {
			cout << "Iesire export...\n";
			return;
		}
		else if (option == "CSV") {
			fileName.append(".csv");
			this->cos_serv.exportToFile(fileName);
			break;
		}
		else if (option == "HTML") {
			fileName.append(".html");
			this->cos_serv.exportToFile(fileName);
			break;
		}
		else {
			cout << "Optiune invalida!\n";
		}
	}
	cout << "Export cu succes!\n";
}



void ConsolUI::start() {
	while (true) {
		cout << "Meniu:\n";
		cout << "1 adauga\n2 tipareste\n3 sort Denumire\n4 sort Destinatie\n5 sort tip+pret\n6 filtrare pret\n7 Filtrare pret min max\n"
			"8 Sterge\n9 Modifica \n10 Adauaga in cos\n11 Sterge Cosul\n12 Afiseaza cosul\n13 Genereaza un cos\n14 Statistici"
			"\n15 Undo\n16 Export to file\n0 Iesire\nDati comanda:";
		int cmd;
		cin >> cmd;
		try {
			switch (cmd) {
			case 1:
				adaugaUI();
				break;
			case 2:
				tipareste(ctr.getAll());
				break;
			case 3:
				tipareste(ctr.sortDenumire());
				break;
			case 4:
				tipareste(ctr.sortDestinatie());
				break;
			case 5:
				tipareste(ctr.sortTipPret());
				break;
			case 6:
				cout << "Dati pret maxim:";
				int pret;
				cin >> pret;
				tipareste(ctr.filtrarePretMaiMic(pret));
				break;
			case 7:
				cout << "Dati pret minim:";
				int pretMin;
				cin >> pretMin;
				cout << "Dati pret maxim:";
				int pretMax;
				cin >> pretMax;
				tipareste(ctr.filtrarePret(pretMin, pretMax));
				break;
			case 8:
				stergeUI();
				break;
			case 9:
				modificaUI();
				break;
			case 10:
				cos_addUI();
				break;
			case 11:
				cos_serv.cos_delete_service();
				break;
			case 12:
				print_cosUI();
				break;
				
			case 13:
				try
				{
					cos_serv.cos_generate_service();
					cout << "Cosul a fost generat cu succes!\n";
				}
				catch (const OfertaException& eroare)
				{
					cout << eroare << '\n';
				}
				break;
			case 14:
			{
				cout << "Statistici:\n";
				map <string, int> m = ctr.getStats();
				for (auto it = m.begin(); it != m.end(); it++)
				{
					cout << it->first << " " << it->second << "\n";
				}
				break;
			}
			case 15:
			{
				undo();
				break;
			}
			case 16:
			{
				uiExportToFile();
				break; 
			}
			case 0:
				return;
			default:
				cout << "Comanda invalida\n";
			}
		}
		catch (const OfertaException& ex) {
			cout << ex << '\n';
		}
		catch (const ValidateException& ex) {
			cout << ex << '\n';
		}
	}
}