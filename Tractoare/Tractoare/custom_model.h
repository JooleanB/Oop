#pragma once
#include <QAbstractTableModel>
#include <vector>
#include "Tractor.h"
using namespace std;

class CustomTableModel : public QAbstractTableModel {
private:
	vector <Tractor> tractoare;
	string tip;
public:

	CustomTableModel(const vector<Tractor>& m) : tractoare{ m } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return int(tractoare.size());
	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 5;
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

	QVariant data(const QModelIndex& index, int role) const override;


	void setLista(const vector<Tractor>& new_list) {
		tractoare = new_list;
		auto topLeft = createIndex(0, 0);
		auto bottomRight = createIndex(rowCount(), columnCount());
		emit layoutChanged();
		//emit dataChanged(topLeft, bottomRight);
	}
	void set_tip(string tip) {
		this->tip = tip;
		emit layoutChanged();
		//emit dataChanged(topLeft, bottomRight);
	}
};
