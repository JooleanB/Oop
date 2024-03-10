#include "custom_model.h"
#include "Service.h"
#include <qcolor.h>

QVariant CustomTableModel::data(const QModelIndex& index, int role) const {
	int row = index.row();
	int col = index.column();
	auto& tractor = this->produse.at(index.row());
	if (role == Qt::DisplayRole) {
		if (col == 0) {
			return QString::number(produse[row].get_id());
		}
		else if (col == 1)
			return QString::fromStdString(produse[row].get_nume());
		else if (col == 2)
			return QString::fromStdString(produse[row].get_tip());
		else if (col == 3)
			return QString::number(produse[row].get_pret());
		else if (col == 4)
		{
			int numar = 0;
			string nume = produse[row].get_nume();
			string vowels = "aeiouAEIOU";
			for (char l : nume) {
				if (vowels.find(l))
					numar++;
			}
			return QString::number(numar);
		}
	}
	else if(role==	Qt::BackgroundRole)
	{
		if (tractor.get_pret() < numar) {
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
			return QString("NUME");
		case 2:
			return QString("TIP");
		case 3:
			return QString("PRET");
		case 4:
			return QString("NR VOCALE");
		}
	}

	return QVariant();
}