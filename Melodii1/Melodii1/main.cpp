#include <QtWidgets/QApplication>
#include "Service.h"
#include "Repo.h"
#include "GUI.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repo rep;
	rep.importt();
	Service serv{rep};

	
	serv.sortare(serv.get_all());
	rep.exportare();

	GUI interface {serv};
	
	interface.show();
    
    return a.exec();
}
