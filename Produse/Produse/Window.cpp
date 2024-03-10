#include "Window.h"
void Window::init_wnd() {
	this->setLayout(main_layout);
	main_layout->addWidget(list);
}

/*functie pentru reincarcarea listei
v->vector<Task>: noul vector pe care vrem sa-l incarcam in lista*/
void Window::load_list(vector<Produs> v) {
	this->list->clear();

	for (auto& el : v) {
		list->addItem(QString::fromStdString(std::to_string(el.get_id()) + " " + el.get_nume() + " " + el.get_tip()+ " " + std::to_string(el.get_pret())));
	}
}

/*cand se da notify clasa face reload la lista ei, cu noile date */
void Window::update() {
	load_list(srv.filtrare_tip(str));
}
