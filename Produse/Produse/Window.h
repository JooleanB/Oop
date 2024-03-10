#pragma once
#include "GUI.h"
#include <qlistwidget.h>
class Window : public QWidget, public Observer {
private:
	Service& srv;
	string str;

	QListWidget* list = new QListWidget;
	QHBoxLayout* main_layout = new QHBoxLayout;

public:
	/*constructor*/
	Window(Service& srv, string str) :srv{ srv }, str{ str } {
		this->srv.addObserver(this);
		setWindowTitle(QString::fromStdString(str));
		init_wnd();
		load_list(srv.filtrare_tip(str));
	};

	/*initializez interfata ferestrei (lista si butoane)*/
	void init_wnd();

	/*functie pentru reincarcarea listei
	v->vector<Task>: noul vector pe care vrem sa-l incarcam in lista*/
	void load_list(vector<Produs> v);

	/*cand se da notify clasa face reload la lista ei, cu noile date */
	void update();

};