#include "GUI.h"

void GUI::interfata()
{
    QHBoxLayout* main_layout = new QHBoxLayout{};
    setLayout(main_layout);

    auto left_part = new QHBoxLayout;
    tabel->setModel(model);
    main_layout->addLayout(left_part);
    auto middle_part = new QFormLayout;

    middle_part->addRow("ID", id);
    middle_part->addRow("NUME", nume);
    middle_part->addRow("TIP", tip);
    middle_part->addRow("PRET", pret);
    main_layout->addLayout(middle_part);
    auto butoane = new QHBoxLayout{};
    butoane->addWidget(tabel);
    butoane->addWidget(slider);
    slider->setRange(0,100);
    butoane->addWidget(butonAdauga);
    main_layout->addLayout(butoane);
}

void GUI::load_data(const vector<Produs>& m)
{
    model->setLista(m);
}

void GUI::connect() {
    QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
        if (tabel->selectionModel()->selectedIndexes().isEmpty()) {
            id->setText("");
            nume->setText("");
            tip->setText("");
            pret->setText("");
            return;
        }
        int selected_row = tabel->selectionModel()->selectedIndexes().at(0).row();
        auto tractor = serv.get_all()[selected_row];
        id->setText(QString::number(tractor.get_id()));
        nume->setText(QString::fromStdString(tractor.get_nume()));
        tip->setText(QString::fromStdString(tractor.get_tip()));
        pret->setText(QString::number(tractor.get_pret()));
        slider->setValue(tractor.get_pret());
        model->set_numar(slider->value());
        //repaint();
        });
    QObject::connect(butonAdauga, &QPushButton::clicked, [&]() {
        int ID = id->text().toInt();
        string NUME= nume->text().toStdString();
        string TIP = tip->text().toStdString();
        int PRET = pret->text().toDouble();
        try {
            serv.store(ID, NUME, TIP, PRET);
        }
        catch (std::exception& e) {
            QMessageBox::information(nullptr, "EROARE!", QString::fromStdString(e.what()));
        }
        serv.exportare();
        load_data(serv.get_all());
        serv.notify();

        });

    QObject::connect(slider, &QSlider::valueChanged, [&]() {
        model->set_numar(slider->value());
        });

}

void GUI::add_window()
{
    vector<string> tipuri;
    for (auto m : serv.get_all())
    {
        bool isDuplicate = false;
        for (auto tip : tipuri) {
            if (m.get_tip() == tip) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            tipuri.push_back(m.get_tip());
        }
    }
    for (auto m : tipuri)
    {
        Window* wnd = new Window(serv, m);
        wnd->show();
    }



}
