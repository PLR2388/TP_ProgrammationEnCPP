/********************************************************************************
** Form generated from reading UI file 'saaqgui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAAQGUI_H
#define UI_SAAQGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaaqGUIClass
{
public:
    QAction *actionCamion;
    QAction *actionV_hicule_de_Promenade;
    QAction *actionG;
    QAction *actionQUITTER;
    QAction *actionSupprimer_V_hicule;
    QAction *AjouterCamionAction;
    QAction *AjoutVehiculePromenadeAction;
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QMenu *menuMENU;
    QMenu *menuAjouter_V_hicule;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SaaqGUIClass)
    {
        if (SaaqGUIClass->objectName().isEmpty())
            SaaqGUIClass->setObjectName(QString::fromUtf8("SaaqGUIClass"));
        SaaqGUIClass->resize(800, 600);
        SaaqGUIClass->setAcceptDrops(false);
        actionCamion = new QAction(SaaqGUIClass);
        actionCamion->setObjectName(QString::fromUtf8("actionCamion"));
        actionV_hicule_de_Promenade = new QAction(SaaqGUIClass);
        actionV_hicule_de_Promenade->setObjectName(QString::fromUtf8("actionV_hicule_de_Promenade"));
        actionG = new QAction(SaaqGUIClass);
        actionG->setObjectName(QString::fromUtf8("actionG"));
        actionQUITTER = new QAction(SaaqGUIClass);
        actionQUITTER->setObjectName(QString::fromUtf8("actionQUITTER"));
        actionSupprimer_V_hicule = new QAction(SaaqGUIClass);
        actionSupprimer_V_hicule->setObjectName(QString::fromUtf8("actionSupprimer_V_hicule"));
        AjouterCamionAction = new QAction(SaaqGUIClass);
        AjouterCamionAction->setObjectName(QString::fromUtf8("AjouterCamionAction"));
        AjoutVehiculePromenadeAction = new QAction(SaaqGUIClass);
        AjoutVehiculePromenadeAction->setObjectName(QString::fromUtf8("AjoutVehiculePromenadeAction"));
        centralwidget = new QWidget(SaaqGUIClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 801, 551));
        SaaqGUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SaaqGUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuMENU = new QMenu(menubar);
        menuMENU->setObjectName(QString::fromUtf8("menuMENU"));
        menuAjouter_V_hicule = new QMenu(menuMENU);
        menuAjouter_V_hicule->setObjectName(QString::fromUtf8("menuAjouter_V_hicule"));
        SaaqGUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(SaaqGUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SaaqGUIClass->setStatusBar(statusbar);

        menubar->addAction(menuMENU->menuAction());
        menuMENU->addAction(menuAjouter_V_hicule->menuAction());
        menuMENU->addAction(actionSupprimer_V_hicule);
        menuMENU->addAction(actionQUITTER);
        menuAjouter_V_hicule->addAction(AjouterCamionAction);
        menuAjouter_V_hicule->addAction(AjoutVehiculePromenadeAction);

        retranslateUi(SaaqGUIClass);
        QObject::connect(actionSupprimer_V_hicule, SIGNAL(triggered()), SaaqGUIClass, SLOT(dialogSupprimerVehicule()));

        QMetaObject::connectSlotsByName(SaaqGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *SaaqGUIClass)
    {
        SaaqGUIClass->setWindowTitle(QApplication::translate("SaaqGUIClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCamion->setText(QApplication::translate("SaaqGUIClass", "Camion", 0, QApplication::UnicodeUTF8));
        actionV_hicule_de_Promenade->setText(QApplication::translate("SaaqGUIClass", "V\303\251hicule de Promenade", 0, QApplication::UnicodeUTF8));
        actionG->setText(QApplication::translate("SaaqGUIClass", "g", 0, QApplication::UnicodeUTF8));
        actionQUITTER->setText(QApplication::translate("SaaqGUIClass", "Quitter", 0, QApplication::UnicodeUTF8));
        actionSupprimer_V_hicule->setText(QApplication::translate("SaaqGUIClass", "Supprimer V\303\251hicule", 0, QApplication::UnicodeUTF8));
        AjouterCamionAction->setText(QApplication::translate("SaaqGUIClass", "Camion", 0, QApplication::UnicodeUTF8));
        AjoutVehiculePromenadeAction->setText(QApplication::translate("SaaqGUIClass", "V\303\251hicule de Promenade", 0, QApplication::UnicodeUTF8));
        menuMENU->setTitle(QApplication::translate("SaaqGUIClass", "MENU", 0, QApplication::UnicodeUTF8));
        menuAjouter_V_hicule->setTitle(QApplication::translate("SaaqGUIClass", "Ajouter V\303\251hicule", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SaaqGUIClass: public Ui_SaaqGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAAQGUI_H
