#pragma once
#include <QAbstractTableModel>
#include <vector>
#include "Joc.h"
using namespace std;

class CustomTableModel : public QAbstractTableModel {
private:
	vector <Joc> jocuri;

public:
	CustomTableModel(const vector<Joc>& m) : jocuri{ m } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return int(jocuri.size());
	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 5;
	}

	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	void setLista(const vector<Joc>& new_list) {
		jocuri = new_list;
		auto topLeft = createIndex(0, 0);
		auto bottomRight = createIndex(rowCount(), columnCount());
		emit layoutChanged();
	}
};