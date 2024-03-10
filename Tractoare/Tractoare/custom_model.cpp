#include "custom_model.h"
#include "Service.h"
#include <qcolor.h>

QVariant CustomTableModel::data(const QModelIndex& index, int role) const {
	int row = index.row();
	int col = index.column();
	auto& tractor = this->tractoare.at(index.row());
	if (role == Qt::DisplayRole) {
		if (col == 0) {
			return QString::number(tractoare[row].get_id());
		}
		else if (col == 1)
			return QString::fromStdString(tractoare[row].get_denumire());
		else if (col == 2)
			return QString::fromStdString(tractoare[row].get_tip());
		else if (col == 3)
			return QString::number(tractoare[row].get_roti());
		else if (col == 4)
		{
			int numar = 0;
			string tip = tractoare[row].get_tip();
			for (auto melodie : tractoare)
			{
				if (melodie.get_tip() == tip)
					numar++;
			}
			return QString::number(numar);
		}
	}
	else if (role == Qt::BackgroundRole) {
		if (tractor.get_tip()==tip) {
			return QColor(Qt::red);
		}
	}
	return QVariant();
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const {

	if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
		switch (section) {
		case 0:
			return QString("ID");
		case 1:
			return QString("DENUMIRE");
		case 2:
			return QString("TIP");
		case 3:
			return QString("NR ROTI");
		case 4:
			return QString("NR TRACTOARE");
		}
	}

	return QVariant();
}