#include "custom_model.h"

#include "custom_model.h"
#include "Service.h"

QVariant CustomTableModel::data(const QModelIndex& index, int role) const {
	int row = index.row();
	int col = index.column();

	if (role == Qt::DisplayRole) {
		if (col == 0)
			return QString::number(jocuri[row].get_id());
		else if (col == 1)
			return QString::number(jocuri[row].get_dim());
		else if (col == 2)
			return QString::fromStdString(jocuri[row].get_tabla());
		else if (col == 3)
			return QString::fromStdString(jocuri[row].get_jucator());
		else if (col == 4)
			return QString::fromStdString(jocuri[row].get_stare());
	}
	return QVariant();
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const {

	if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
		switch (section) {
		case 0:
			return QString("ID");
		case 1:
			return QString("DIMENSIUNE");
		case 2:
			return QString("TABELA");
		case 3:
			return QString("JUCATOR");
		case 4:
			return QString("STARE");
		}
	}

	return QVariant();
}