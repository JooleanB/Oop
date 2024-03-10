#pragma once
#include <qwidget.h>
#include <QtWidgets/qtableview.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include <QLineEdit>
#include "Service.h"
#include <qformlayout.h>
#include <qboxlayout.h>
#include <QtWidgets/qlayout.h>
#include "custom_model.h"
class GUI :public QWidget {
private:
	Service& serv;
	QPushButton* sterge = new QPushButton("Sterge");
	QPushButton* intinerire = new QPushButton("Intinerire");
	QPushButton* imbatranire = new QPushButton("Imbatranire");
	QPushButton* undo = new QPushButton("Undo");
	QPushButton* redo = new QPushButton("Redo");
	QTableView* tabel;
	CustomTableModel* model;
	
	void interfata();
	void load_data(vector<Student>& v);
	void conectare();
public:
	GUI(Service& serv) : serv{ serv } {
		interfata();
		load_data(serv.get_all());
		conectare();
	}
};