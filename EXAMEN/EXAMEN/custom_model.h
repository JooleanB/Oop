#pragma once
#include <QAbstractTableModel>
#include <vector>
#include "Student.h"
using namespace std;

class CustomTableModel : public QAbstractTableModel {
private:
	vector<Student> studenti;
public:
	CustomTableModel( vector<Student>& m) : studenti{ m } {}
	int rowCount(const QModelIndex& parent = QModelIndex())const override {
		return studenti.size();
	}
	int columnCount(const QModelIndex& parent = QModelIndex())const override {
		return 4;
	}
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	void set_lista(vector<Student>& new_list){
		studenti = new_list;
		auto topLeft = createIndex(0, 0);
		auto bottomRight = createIndex(rowCount(), columnCount());
		emit layoutChanged();
	}
};
