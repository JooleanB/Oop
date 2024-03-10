#include "GUI.h"

void GUI::interfata() {
	QVBoxLayout* main_layout = new QVBoxLayout;
	setLayout(main_layout);
	auto left_part = new QHBoxLayout;
	model= new CustomTableModel{ serv.get_all() };
	tabel= new QTableView;
	tabel->setModel(model);
	left_part->addWidget(tabel);
	
	main_layout->addLayout(left_part);
	auto butoane = new QHBoxLayout;
	butoane->addWidget(sterge);
	butoane->addWidget(imbatranire);
	butoane->addWidget(intinerire);
	butoane->addWidget(undo);
	butoane->addWidget(redo);
	main_layout->addLayout(butoane);
}


void GUI::conectare() {


}

void GUI::load_data(vector<Student>& v) {
	model->set_lista(v);
}