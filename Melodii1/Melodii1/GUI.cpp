#include "GUI.h"

void GUI::create_interface()
{
    QHBoxLayout* main_layout = new QHBoxLayout{};
    setLayout(main_layout);

    auto left_part = new QHBoxLayout;
    //left_part->addWidget(paintingArea);
    //left_part->addWidget(list_layout);
    tabel->setModel(model);
    //left_part->addWidget(tabel);
    main_layout->addLayout(left_part);
    auto middle_part = new QFormLayout;

    middle_part->addWidget(linie);
    middle_part->addWidget(slider);
    slider->setRange(0, 10);
    main_layout->addLayout(middle_part);
    auto butoane = new QHBoxLayout{};
    butoane->addWidget(tabel);
    butoane->addWidget(butonModifica);
    butoane->addWidget(butonSterge);
    main_layout->addLayout(butoane);
}

void GUI::load_data(const vector<Melodii>& m)
{
    update();
    model->setLista(m);
}

void GUI::connect() {
    QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
        if (tabel->selectionModel()->selectedIndexes().isEmpty()) {
            linie->setText("");
            return;
        }
        int selected_row = tabel->selectionModel()->selectedIndexes().at(0).row();
        auto id_cel = tabel->model()->index(selected_row, 0);
        auto nume_cel = tabel->model()->index(selected_row, 1);
        auto rank_cel = tabel->model()->index(selected_row, 3);

        auto nume = tabel->model()->data(nume_cel, Qt::DisplayRole).toString();
        auto id = tabel->model()->data(id_cel, Qt::DisplayRole).toInt();
        auto rank = tabel->model()->data(rank_cel, Qt::DisplayRole).toInt();

        linie->setText(nume);
        slider->setValue(rank);
        });
    QObject::connect(butonSterge, &QPushButton::clicked, [&]() {
        if (!tabel->selectionModel()->selectedIndexes().isEmpty())
        {
            int selected_row = tabel->selectionModel()->selectedIndexes().at(0).row();
            auto id_cel = tabel->model()->index(selected_row, 0);
            auto id = tabel->model()->data(id_cel, Qt::DisplayRole).toInt();
            int ok = serv.sterge(id);
            if (ok == 1)
            {
                serv.sortare(serv.get_all());
                serv.exportt();
            }
            else
                QMessageBox::information(nullptr, "Eroare!", "Nu se poate sterge");
            load_data(serv.get_all());
        }
        });
    QObject::connect(butonModifica, &QPushButton::clicked, [&]() {
        if (!tabel->selectionModel()->selectedIndexes().isEmpty())
        {
            int selected_row = tabel->selectionModel()->selectedIndexes().at(0).row();
            auto id_cel = tabel->model()->index(selected_row, 0);
            auto id = tabel->model()->data(id_cel, Qt::DisplayRole).toInt();
            auto nume = linie->text().toStdString();
            auto rank = slider->value();
            cout << id<<" "<<nume<<" "<<rank<<"\n";
            serv.modifica(id, nume, rank);
            for (auto melodie : serv.get_all())
                if (melodie.get_id() == id)
                    cout << melodie.get_nume();
            load_data(serv.get_all());
        }
        });
}

void GUI::paintEvent(QPaintEvent* event) {
    QPainter g(this);
    vector<int> ranks;
    int y = height();
    ranks.resize(11);
    for (auto melodie : serv.get_all())
        ranks[melodie.get_rank()]++;
    for (int i = 0; i < 11; i++)
    {
        g.setPen(QPen(Qt::red,10));
        if (ranks[i] != 0)
            g.setPen(QPen(Qt::blue,10));
        g.drawLine(50 * (i + 1), y, 50 * (i + 1), y-100-100* ranks[i]);
    }
}


void GUI::update() {
    repaint();
}


/*void GUI::paintEvent(QPaintEvent* ev) {
    //desenez dupa rank
    QPainter p{ this };
    p.setPen(Qt::darkRed);
    int rank = 0;
    for (auto& c : srv.rank_fr()) {
        int x = (rank + 1) * 10;
        p.drawLine(x, p.device()->height() * 10, x, p.device()->height() - c * 5);
        rank++;
    }
}*/

