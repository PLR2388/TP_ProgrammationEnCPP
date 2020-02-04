/********************************************************************************
** Form generated from reading UI file 'vehiculepromenadeinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEHICULEPROMENADEINTERFACE_H
#define UI_VEHICULEPROMENADEINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VehiculePromenadeInterfaceClass
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *niv;
    QLabel *label_2;
    QLineEdit *immatriculation;
    QLabel *label_3;
    QSpinBox *nbPlaces;
    QPushButton *ValideButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *VehiculePromenadeInterfaceClass)
    {
        if (VehiculePromenadeInterfaceClass->objectName().isEmpty())
            VehiculePromenadeInterfaceClass->setObjectName(QString::fromUtf8("VehiculePromenadeInterfaceClass"));
        VehiculePromenadeInterfaceClass->resize(400, 300);
        formLayoutWidget = new QWidget(VehiculePromenadeInterfaceClass);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 401, 301));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        niv = new QLineEdit(formLayoutWidget);
        niv->setObjectName(QString::fromUtf8("niv"));

        formLayout->setWidget(0, QFormLayout::FieldRole, niv);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        immatriculation = new QLineEdit(formLayoutWidget);
        immatriculation->setObjectName(QString::fromUtf8("immatriculation"));

        formLayout->setWidget(1, QFormLayout::FieldRole, immatriculation);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        nbPlaces = new QSpinBox(formLayoutWidget);
        nbPlaces->setObjectName(QString::fromUtf8("nbPlaces"));
        nbPlaces->setMinimum(1);

        formLayout->setWidget(2, QFormLayout::FieldRole, nbPlaces);

        ValideButton = new QPushButton(formLayoutWidget);
        ValideButton->setObjectName(QString::fromUtf8("ValideButton"));

        formLayout->setWidget(3, QFormLayout::FieldRole, ValideButton);

        CancelButton = new QPushButton(formLayoutWidget);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        formLayout->setWidget(3, QFormLayout::LabelRole, CancelButton);


        retranslateUi(VehiculePromenadeInterfaceClass);

        QMetaObject::connectSlotsByName(VehiculePromenadeInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *VehiculePromenadeInterfaceClass)
    {
        VehiculePromenadeInterfaceClass->setWindowTitle(QApplication::translate("VehiculePromenadeInterfaceClass", "VehiculePromenadeInterface", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("VehiculePromenadeInterfaceClass", "Entrez un niv :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("VehiculePromenadeInterfaceClass", "Entrez une immatriculation : ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("VehiculePromenadeInterfaceClass", "Entrez un nombre de places :", 0, QApplication::UnicodeUTF8));
        ValideButton->setText(QApplication::translate("VehiculePromenadeInterfaceClass", "Valider", 0, QApplication::UnicodeUTF8));
        CancelButton->setText(QApplication::translate("VehiculePromenadeInterfaceClass", "Retour", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VehiculePromenadeInterfaceClass: public Ui_VehiculePromenadeInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEHICULEPROMENADEINTERFACE_H
