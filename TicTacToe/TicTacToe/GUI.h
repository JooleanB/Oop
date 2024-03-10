#pragma once
#include <qwidget.h>
#include <QtWidgets/qlineedit.h>
#include <qtableview.h>;
#include "custom_model.h"
#include "Service.h"
#include <qboxlayout.h>
#include <qformlayout.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <vector>
#include <QPushButton>
using std::vector;
class GUI : public QWidget {
private:
	Service& serv;
	QLineEdit* id = new QLineEdit;
	QLineEdit* dim = new QLineEdit;
	QLineEdit* tabla = new QLineEdit;
	QLineEdit* jucator = new QLineEdit;
	QLineEdit* stare = new QLineEdit;
	QTableView* tabel = new QTableView;
	CustomTableModel* model = new CustomTableModel{ serv.get_all() };
	QPushButton* butonAdauga = new QPushButton{ "Adauga" };
	QPushButton* butonModifica = new QPushButton{ "Modifica" };
	vector<QPushButton*> butoane;
	QGridLayout* layout_butoane = new QGridLayout;
	void create_interface();
	void modifica();
	void adauga();
	void load_data(const vector<Joc>& m);
	void connect();
public:
	GUI(Service& service):serv{service} 
	{
		create_interface();
		load_data(serv.get_all());
		connect();
	}
};