#pragma once
#pragma once
#include <QAbstractTableModel>
#include <vector>
#include "Produs.h"
using namespace std;

class CustomTableModel : public QAbstractTableModel {
private:
	vector <Produs> produse;
	int numar;
public:

	CustomTableModel(const vector<Produs>& m) : produse{ m } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return int(produse.size());
	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 5;
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

	QVariant data(const QModelIndex& index, int role) const override;


	void setLista(const vector<Produs>& new_list) {
		produse = new_list;
		auto topLeft = createIndex(0, 0);
		auto bottomRight = createIndex(rowCount(), columnCount());
		emit layoutChanged();
		//emit dataChanged(topLeft, bottomRight);
	}
	void set_numar(int nr) {
		numar = nr;
		emit layoutChanged();
	}

};