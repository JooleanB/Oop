#include "GUI.h"

void GUI::create_interface()
{
    QHBoxLayout* main_layout = new QHBoxLayout{};
    setLayout(main_layout);

    auto left_part = new QHBoxLayout;
    //left_part->addWidget(paintingArea);
    //left_part->addWidget(list_layout);
    tabel->setModel(model);
    left_part->addWidget(tabel);
    main_layout->addLayout(left_part);
    auto middle_part = new QFormLayout;
    middle_part->addRow("ID" , id);
    middle_part->addRow("DIM",dim);
    middle_part->addRow("TABLA",tabla);
    middle_part->addRow("JUCATOR",jucator);
    middle_part->addRow("STARE",stare);
    /*auto coloana1 = new QVBoxLayout;
    for (int i = 0; i < 25; i ++)
    {
		butoane.push_back(new QPushButton{""});
	}
    for (int i = 0; i < 25; i+=5) {
        coloana1->addWidget(butoane[i]);
    }
    auto coloana2 = new QVBoxLayout;
    for (int i = 1; i < 25; i+=5) {
        coloana2->addWidget(butoane[i]);
    }
    auto coloana3 = new QVBoxLayout;
    for (int i = 2; i < 25; i+=5) {
        coloana3->addWidget(butoane[i]);
    }
    auto coloana4 = new QVBoxLayout;
    for (int i = 3; i < 25; i+=5) {
        coloana4->addWidget(butoane[i]);
    }
    auto coloana5 = new QVBoxLayout;
    for (int i = 4; i < 25; i+=5) {
        coloana5->addWidget(butoane[i]);
    }
    main_layout->addLayout(coloana1);
    main_layout->addLayout(coloana2);
    main_layout->addLayout(coloana3);
    main_layout->addLayout(coloana4);
    main_layout->addLayout(coloana5);
    */
    middle_part->addRow(butonAdauga);
    middle_part->addRow(butonModifica);
    main_layout->addLayout(middle_part);
    main_layout->addLayout(layout_butoane);
    
}

void GUI::load_data(const vector<Joc>& m)
{
    model->setLista(m);
}
void GUI::adauga() {
    int id = this->id->text().toInt();
    int dim = this->dim->text().toInt();
    string tabla;
    if(dim==3)
       tabla = "---------";
    if(dim==4)
		tabla = "----------------";
    if(dim==5)
        tabla = "-------------------------";
    string jucator = this->jucator->text().toStdString();
    string stare = "Neinceput";
    serv.adaugare(id, dim, tabla, jucator, stare);
    load_data(serv.get_all());
    serv.exportare();
}

void GUI::modifica() {
    int id = this->id->text().toInt();
    int dim = this->dim->text().toInt();
    string tabla = this->tabla->text().toStdString();
    string jucator = this->jucator->text().toStdString();
    string stare = this->stare->text().toStdString();
    if(serv.modificare(id, dim, tabla, jucator, stare)==0)
        QMessageBox::information(nullptr, "Eroare", "Nu exista jocul cu id-ul dat!");
    load_data(serv.get_all());
    serv.exportare();
}

void GUI::connect() {
    QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
        if (tabel->selectionModel()->selectedIndexes().isEmpty()) {
            id->setText("");
            dim->setText("");
            tabla->setText("");
            jucator->setText("");
            stare->setText("");
            for (auto& b : butoane)
                b->setText("");
            return;
        }
        for (auto& buton : butoane)
        {
            delete buton;
        }
        butoane.clear();

        int selected_row = tabel->selectionModel()->selectedIndexes().at(0).row();
        auto id_cel = tabel->model()->index(selected_row, 0);
        auto dim_cel = tabel->model()->index(selected_row, 1);
        auto tabla_cel = tabel->model()->index(selected_row, 2);
        auto jucator_cel = tabel->model()->index(selected_row, 3);
        auto stare_cel = tabel->model()->index(selected_row, 4);

        auto dim = tabel->model()->data(dim_cel, Qt::DisplayRole).toInt();
        auto id = tabel->model()->data(id_cel, Qt::DisplayRole).toInt();
        auto tabla = tabel->model()->data(tabla_cel, Qt::DisplayRole).toString();
        auto jucator = tabel->model()->data(jucator_cel, Qt::DisplayRole).toString();
        auto stare = tabel->model()->data(stare_cel, Qt::DisplayRole).toString();

        /*int length = tabla.length();
        for (int i = 0; i < length; i++) {
            if(length==25)
                butoane[i]->setText(tabla[i]);
            if (length == 9)
            {
                if (i < 3)
                    butoane[i]->setText(tabla[i]);
                else if (i < 6)
                    butoane[i + 2]->setText(tabla[i]);
                else
                    butoane[i+4]->setText(tabla[i]);
            }
        }*/
        int num = 0;
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                QPushButton* btn = new QPushButton{ tabla[num] };
                butoane.push_back(btn);
                layout_butoane->addWidget(btn, i, j);
                num++;
            }
        }

        for (int num = 0; num < butoane.size(); num++)
        {
            QObject::connect(butoane[num], &QPushButton::clicked, [=]() {

                for (auto& game : serv.get_all())
                {
                    if (game.get_id() == id)
                    {
                        if (tabla[num] == '-')
                        {
                            butoane[num]->setText(jucator);
                            string murim = tabla.toStdString();
                            murim[num] = jucator.toStdString()[0];
                            if (jucator == "X")
                                game.set_jucator("0");
                            else
                                game.set_jucator("X");
                            serv.modificare(game.get_id(), game.get_dim(), murim, game.get_jucator(), game.get_stare());
                            model->setLista(serv.get_all());

                        }
                        break;
                    }
                }
                });
        }
        this->id->setText(QString::number(id));
        this->dim->setText(QString::number(dim));
        this->tabla->setText(tabla);
        this->jucator->setText(jucator);
        this->stare->setText(stare);
		});
    QObject::connect(butonAdauga, &QPushButton::clicked, this, &GUI::adauga);
	QObject::connect(butonModifica, &QPushButton::clicked, this, &GUI::modifica);
}

