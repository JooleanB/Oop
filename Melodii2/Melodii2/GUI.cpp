#include "GUI.h"
#include <qpainter.h>

void GUI::interface() {
	auto main_layout = new QHBoxLayout{};
	setLayout(main_layout);
	auto form_layout = new QFormLayout;
	auto button_layout = new QHBoxLayout;
	auto table_layout = new QHBoxLayout{};
	tabel->setModel(model);
	table_layout->addWidget(tabel);
	main_layout->addLayout(table_layout);
	form_layout->addRow("ID", id);
	form_layout->addRow("Titlu", titlu);
	form_layout->addRow("Artist", artist);
	form_layout->addRow("Gen", gen);
	main_layout->addLayout(form_layout);
	button_layout->addWidget(add);
	button_layout->addWidget(del);
	main_layout->addLayout(button_layout);
	main_layout->insertSpacing(0, 300);
}

void GUI::connect() {
	QObject::connect(add, &QPushButton::clicked, [&]() { add_melodie();});
	QObject::connect(del, &QPushButton::clicked, [&]() { delete_melodie(); });
	QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
		if (tabel->selectionModel()->selectedIndexes().isEmpty()) {
			id->setText(" ");
			titlu->setText(" ");
			artist->setText(" ");
			gen->setText(" ");
		}
		int selected_row = tabel->selectionModel()->selectedIndexes().at(0).row();
		auto melodie = service.getAll()[selected_row];
		id->setText(QString::number(melodie.getId()));
		titlu->setText(QString::fromStdString(melodie.getTitlu()));
		artist->setText(QString::fromStdString(melodie.getArtist()));
		gen->setText(QString::fromStdString(melodie.getGen()));
		});
}

void GUI::load_data(vector<Melodii>& v) {
	update();
	model->setLista(v);
}

void GUI::add_melodie() {
	int ID= id->text().toInt();
	string TITLU = titlu->text().toStdString();
	string ARTIST = artist->text().toStdString();
	string GEN = gen->text().toStdString();
	service.store(ID, TITLU, ARTIST, GEN);
	load_data(service.getAll());
}

void GUI::delete_melodie() {
	int ID = id->text().toInt();
	service.sterge(ID);
	load_data(service.getAll());
}

void GUI::paintEvent(QPaintEvent* ev) {
	QPainter g (this);
	vector<int> genuri;
	genuri.resize(4);
	for (auto& melodie : service.getAll()) {
		if (melodie.getGen() == "pop") {
			genuri[0]++;
		}
		else if (melodie.getGen() == "rock") {
			genuri[1]++;
		}
		else if (melodie.getGen() == "folk") {
			genuri[2]++;
		}
		else if (melodie.getGen() == "disco") {
			genuri[3]++;
		}
	}
	int centru_x_stanga = 30;
	int centru_y_jos = 30;
	int centru_x_dreapta = width() - 30;
	int centru_y_sus = height() - 30;
	int diametru = 10;
	int x_stanga = centru_x_stanga - diametru / 2;
	int y_jos = centru_y_jos - diametru / 2;
	int x_dreapta = centru_x_dreapta - diametru / 2;
	int y_sus = centru_y_sus - diametru / 2;
	g.setPen(QPen(Qt::black, 2));
	g.drawEllipse(x_stanga-5, y_jos-5, 10, 10);
	for (int i = 0; i < genuri[0]; i++)
	{
		int size = 20 + i * 10;
		g.drawEllipse(x_stanga-(size/2), y_jos - (size/2), size, size);
	}
	g.setPen(QPen(Qt::red, 2));
	g.drawEllipse(x_stanga-5, y_sus-5, 10, 10);
	for (int i = 0; i < genuri[1]; i++)
	{
		int size = 20 + i * 10;
		g.drawEllipse(x_stanga-(size/2), y_sus-(size/2), size, size);
	}
	g.setPen(QPen(Qt::green, 2));
	g.drawEllipse(x_dreapta-5, y_jos-5, 10, 10);
	for (int i = 0; i < genuri[2]; i++)
	{
		int size = 20 + i * 10;
		g.drawEllipse(x_dreapta-(size/2), y_jos-(size/2), size, size);
	}
	g.setPen(QPen(Qt::cyan, 2));
	g.drawEllipse(x_dreapta-5, y_sus-5, 10, 10);
	for (int i = 0; i < genuri[3]; i++)
	{
		int size = 20 + i * 10;
		g.drawEllipse(x_dreapta-(size/2), y_sus-(size/2), size, size);
	}
}

void GUI::update() {
	repaint();
}