#pragma once
#include <Qwidget>
#include <qwidget.h>
#include <QtWidgets/qpushbutton.h>
#include<QtWidgets/qlineedit.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qtablewidget.h>
#include <QtWidgets/qmessagebox.h>
#include <qtableview.h>
#include "custom_model.h"
#include "Service.h"

class GUI : public QWidget {
private:
	Service& service;
	QTableView* tabel = new QTableView;
	QLineEdit* id = new QLineEdit;
	QLineEdit* titlu = new QLineEdit;
	QLineEdit* artist = new QLineEdit;
	QLineEdit* gen = new QLineEdit;
	QPushButton* add = new QPushButton{ "&Add" };
	QPushButton* del = new QPushButton{ "&Delete" };
	CustomTableModel* model = new CustomTableModel{ service.getAll() };

	void interface();
	void connect();
	void load_data(vector<Melodii>& v);
	void add_melodie();
	void delete_melodie();
	void update();
	void paintEvent(QPaintEvent* ev);

public:
	GUI(Service& s) : service{ s } {
		interface();
		load_data(service.getAll());
		connect();
	}
};