#include "GUI.h"
#include "Service.h"
#include "Repo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo repo;
    Service service{ repo };
    service.importare();
    service.sortare(service.get_all());
    service.exportare();
    GUI w {service};
    w.show();
    return a.exec();
}
