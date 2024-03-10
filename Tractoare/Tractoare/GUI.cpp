#include "GUI.h"

void GUI::interface()
{
    QHBoxLayout* main_layout = new QHBoxLayout{};
    setLayout(main_layout);

    auto left_part = new QHBoxLayout;
    tabel->setModel(model);
    main_layout->addLayout(left_part);
    auto middle_part = new QFormLayout;

    middle_part->addRow("ID",id);
    middle_part->addRow("DENUMIRE",denumire);
    middle_part->addRow("TIP",tip);
    middle_part->addRow("ROTI",roti);
    main_layout->addLayout(middle_part);
    auto butoane = new QHBoxLayout{};
    butoane->addWidget(tabel);
    butoane->addWidget(combo);
    combo->setCurrentIndex(0);
    
    butoane->addWidget(butonAdauga);
    main_layout->addLayout(butoane);
}

void GUI::paintEvent(QPaintEvent* ev) {
    QPainter g(this);
	g.setPen(Qt::red);
    if (!tabel->selectionModel()->selectedIndexes().isEmpty())
    {
        int selected_row = tabel->selectionModel()->selectedIndexes().at(0).row();
        auto tractor = serv.get_all()[selected_row];
        int nr_roti = tractor.get_roti();
        int x = 10;
        int y=190;
        for (int i = 0; i < nr_roti; i++)
        {
			g.drawEllipse(x, y, 15, 15);
			x += 20;
		}
    }
}

void GUI::load_data(const vector<Tractor>& m)
{
    vector<string> tipuri;
    for (auto m : serv.get_all()) {
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
        combo->addItem(QString::fromStdString(m));
    model->set_tip(tipuri[0]);
    model->setLista(m);
}
/// <summary>
/// 
/// </summary>
void GUI::connect() {
    QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
        if (tabel->selectionModel()->selectedIndexes().isEmpty()) {
            id->setText("");
            denumire->setText("");
            tip->setText("");
            roti->setText("");
            return;
        }
        int selected_row = tabel->selectionModel()->selectedIndexes().at(0).row();
        auto tractor = serv.get_all()[selected_row];
        id->setText(QString::number(tractor.get_id()));
        denumire->setText(QString::fromStdString(tractor.get_denumire()));
        tip->setText(QString::fromStdString(tractor.get_tip()));
        roti->setText(QString::number(tractor.get_roti()));
        repaint();
        });
    QObject::connect(butonAdauga, &QPushButton::clicked, [&]() {
        int ID = id->text().toInt();
        string DENUMIRE = denumire->text().toStdString();
        string TIP = tip->text().toStdString();
        int ROTI = roti->text().toInt();
        try {
            serv.store(ID, DENUMIRE, TIP, ROTI);
        }
        catch (std::exception& e) {
            QMessageBox::information(nullptr,"EROARE!",QString::fromStdString(e.what()));
        }
        id->setText("");
        denumire->setText("");
        tip->setText("");
        roti->setText("");
        serv.exportare();
        load_data(serv.get_all());

        });
    QObject::connect(combo, QOverload<int>::of(&QComboBox::currentIndexChanged), [&](int index) {
      
        string selectedItem = combo->currentText().toStdString();
        model->set_tip(selectedItem);
           
        });
}
