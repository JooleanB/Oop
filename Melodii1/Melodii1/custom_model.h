#pragma once
#include <QAbstractTableModel>
#include <vector>
#include "Melodii.h"
using namespace std;

class CustomTableModel : public QAbstractTableModel {
private:
	vector <Melodii> melodii;

public:

	CustomTableModel(const vector<Melodii>& m) : melodii{ m } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return int(melodii.size());
	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 5;
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	void setLista(const vector<Melodii>& new_list) {
		melodii = new_list;
		auto topLeft = createIndex(0, 0);
		auto bottomRight = createIndex(rowCount(), columnCount());
		emit layoutChanged();
		//emit dataChanged(topLeft, bottomRight);
	}
};