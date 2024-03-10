#include "GUI.h"
#include <QtWidgets/QApplication>
#include "Repo.h";
#include "Service.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo repo{ "Tractoare.txt" };
    Service service{ repo };
    service.importare();
    service.sortare(service.get_all());
    service.exportare();
    GUI w { service };
    w.show();
    return a.exec();
}
