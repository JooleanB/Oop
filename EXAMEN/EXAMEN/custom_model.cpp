#include "custom_model.h"
#include "Service.h"
#include <qcolor.h>

QVariant CustomTableModel::data(const QModelIndex& index, int role) const {
	int row = index.row();
	int col = index.column();
	auto& student = this->studenti.at(index.row());
	if (role == Qt::DisplayRole) {
		if (col == 0) {
			return QString::number(studenti[row].get_nrmatricol());
		}
		else if (col == 1)
			return QString::fromStdString(studenti[row].get_nume());
		else if (col == 2)
			return QString::number(studenti[row].get_varsta());
		else if (col == 3)
			return QString::fromStdString(studenti[row].get_facultate());
	}
	else if (role == Qt::BackgroundRole)
	{
		if (student.get_facultate() =="mate") {
			return QColor(Qt::red);
		}
		if (student.get_facultate() == "info") {
			return QColor(Qt::black);
		}
		if (student.get_facultate() == "mate-info") {
			return QColor(Qt::green);
		}
		if (student.get_facultate() == "ai") {
			return QColor(Qt::cyan);
		}
	}
	return QVariant();
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const {

	if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
		switch (section) {
		case 0:
			return QString("NR MATRICOL");
		case 1:
			return QString("NUME");
		case 2:
			return QString("VARSTA");
		case 3:
			return QString("FACULTATE");
		}

		return QVariant();
	}
}