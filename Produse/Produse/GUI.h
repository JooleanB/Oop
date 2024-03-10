#pragma once
#include <qwidget.h>
#include "Service.h"
#include <qtableview.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include "custom_model.h"
#include <QtWidgets/qslider.h>
#include <QtWidgets/qmessagebox.h>
#include <qboxlayout.h>
#include <qformlayout.h>
#include <qlayout.h>
#include <qpainter.h>
#include "Window.h"
class GUI : public QWidget {
private:
	Service& serv;
	QTableView* tabel = new QTableView;
	QPushButton* butonAdauga = new QPushButton{ "&Adauga" };
	CustomTableModel* model = new CustomTableModel{ serv.get_all() };
	QLineEdit* id = new QLineEdit;
	QLineEdit* nume = new QLineEdit;
	QLineEdit* tip = new QLineEdit;
	QLineEdit* pret = new QLineEdit;
	QSlider* slider = new QSlider;


	void interfata();
	void connect();
	void load_data(const vector<Produs>& v);
	void add_window();

public:
	GUI(Service& serv) : serv{ serv } {
		interfata();
		load_data(serv.get_all());
		connect();
		add_window();
	}

};