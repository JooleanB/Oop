#include "custom_model.h"
#include "Service.h"

QVariant CustomTableModel::data(const QModelIndex& index, int role) const {
	int row = index.row();
	int col = index.column();

	if (role == Qt::DisplayRole) {
		if (col == 0)
			return QString::number(melodii[row].get_id());
		else if (col == 1)
			return QString::fromStdString(melodii[row].get_nume());
		else if (col == 2)
			return QString::fromStdString(melodii[row].get_artist());
		else if (col == 3)
			return QString::number(melodii[row].get_rank());
		else if (col == 4)
		{
			int numar = 0;
			int rank = melodii[row].get_rank();
			for (auto melodie : melodii)
			{
				if (melodie.get_rank() == rank)
					numar++;
			}
			return QString::number(numar);
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
			return QString("NUME");
		case 2:
			return QString("ARTIST");
		case 3:
			return QString("RANK");
		case 4:
			return QString("NR MELODII");
		}
	}

	return QVariant();
}