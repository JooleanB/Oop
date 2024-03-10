#pragma once
#include <qwidget.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/qtableview.h>
#include <QtWidgets/qtablewidget.h>
#include "Service.h"
#include <QtWidgets/qpushbutton.h>
#include "custom_model.h"
#include <qboxlayout.h>
#include <qformlayout.h>
#include <QtWidgets/qslider.h>
#include <QtWidgets/qlineedit.h>
#include <qmessagebox.h>
#include <iostream>
#include <qpainter.h>
using namespace std;
class GUI : public QWidget {
private:
	Service& serv;
	QTableView* tabel = new QTableView;
	//QTableWidget* lista_melodii = new QTableWidget{ 10, 5 };
	QPushButton* butonModifica = new QPushButton{ "&Modifica" };
	QPushButton* butonSterge = new QPushButton{ "&Sterge" };
	CustomTableModel* model = new CustomTableModel{ serv.get_all() };


	//QWidget* unde_desenez = new QWidget(this);


	QLineEdit* linie = new QLineEdit;
	QSlider* slider = new QSlider;
	
	void create_interface();
	void load_data(const vector<Melodii>& m);
	void connect();
	void paintEvent(QPaintEvent* event);
	void update();
public:
	
	GUI(Service& serv) : serv{ serv }
	{
		create_interface();
		//cout << serv.get_all().size();
		load_data(serv.get_all());
		connect();
	}
};


