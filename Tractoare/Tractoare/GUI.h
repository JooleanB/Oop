#pragma once
#include <qwidget.h>
#include "Service.h"
#include <qtableview.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>
#include "custom_model.h"
#include <QtWidgets/qcombobox.h>
#include <QtWidgets/qmessagebox.h>
#include <qboxlayout.h>
#include <qformlayout.h>
#include <qlayout.h>
#include <qpainter.h>
class GUI : public QWidget {
private:
	Service& serv;
	QTableView* tabel = new QTableView;
	QPushButton* butonAdauga = new QPushButton{ "&Adauga" };
	CustomTableModel* model = new CustomTableModel{ serv.get_all() };
	QLineEdit* id = new QLineEdit;
	QLineEdit* denumire = new QLineEdit;
	QLineEdit* tip = new QLineEdit;
	QLineEdit* roti = new QLineEdit;
	QComboBox* combo = new QComboBox;
	

	void interface();
	void connect();
	void load_data(const vector<Tractor>& v);
	void paintEvent(QPaintEvent* ev);

public:
	GUI(Service& serv) : serv{ serv } {
		interface();
		load_data(serv.get_all());
		connect();
	
	}

};