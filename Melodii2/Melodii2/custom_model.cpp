#include "custom_model.h"
#include "Service.h"

QVariant CustomTableModel::data(const QModelIndex& index, int role) const {
	int row = index.row();
	int col = index.column();

	if (role == Qt::DisplayRole) {
		if (col == 0)
			return QString::number(melodii[row].getId());
		else if (col == 1)
			return QString::fromStdString(melodii[row].getTitlu());
		else if (col == 2)
			return QString::fromStdString(melodii[row].getArtist());
		else if (col == 3)
			return QString::fromStdString(melodii[row].getGen());
		else if (col == 4)
		{
			int numar = 0;
			string gen = melodii[row].getGen();
			for (auto melodie : melodii)
			{
				if (melodie.getGen() == gen)
					numar++;
			}
			return QString::number(numar);
		}
		else if (col == 5) {
			int numar = 0;
			string artist = melodii[row].getArtist();
			for (auto melodie : melodii)
			{
				if (melodie.getArtist() == artist)
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
			return QString("TITLU");
		case 2:
			return QString("ARTIST");
		case 3:
			return QString("GEN");
		case 4:
			return QString("NR GEN");
		case 5:
			return QString("NR ARTIST");
		}
	}

	return QVariant();
}