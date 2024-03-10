/********************************************************************************
** Form generated from reading UI file 'Oferta_1314.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OFERTA_1314_H
#define UI_OFERTA_1314_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Oferta_1314Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Oferta_1314Class)
    {
        if (Oferta_1314Class->objectName().isEmpty())
            Oferta_1314Class->setObjectName("Oferta_1314Class");
        Oferta_1314Class->resize(600, 400);
        menuBar = new QMenuBar(Oferta_1314Class);
        menuBar->setObjectName("menuBar");
        Oferta_1314Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Oferta_1314Class);
        mainToolBar->setObjectName("mainToolBar");
        Oferta_1314Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Oferta_1314Class);
        centralWidget->setObjectName("centralWidget");
        Oferta_1314Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Oferta_1314Class);
        statusBar->setObjectName("statusBar");
        Oferta_1314Class->setStatusBar(statusBar);

        retranslateUi(Oferta_1314Class);

        QMetaObject::connectSlotsByName(Oferta_1314Class);
    } // setupUi

    void retranslateUi(QMainWindow *Oferta_1314Class)
    {
        Oferta_1314Class->setWindowTitle(QCoreApplication::translate("Oferta_1314Class", "Oferta_1314", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Oferta_1314Class: public Ui_Oferta_1314Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OFERTA_1314_H
