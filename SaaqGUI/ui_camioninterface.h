/********************************************************************************
** Form generated from reading UI file 'camioninterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMIONINTERFACE_H
#define UI_CAMIONINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CamionInterfaceClass
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *niv;
    QLabel *label_2;
    QLineEdit *immatriculation;
    QLabel *label_3;
    QDoubleSpinBox *poids;
    QLabel *label_4;
    QSpinBox *nbEssieux;
    QPushButton *cancelButton;
    QPushButton *okButton_2;

    void setupUi(QDialog *CamionInterfaceClass)
    {
        if (CamionInterfaceClass->objectName().isEmpty())
            CamionInterfaceClass->setObjectName(QString::fromUtf8("CamionInterfaceClass"));
        CamionInterfaceClass->resize(400, 300);
        formLayoutWidget = new QWidget(CamionInterfaceClass);
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

        poids = new QDoubleSpinBox(formLayoutWidget);
        poids->setObjectName(QString::fromUtf8("poids"));
        poids->setMinimum(3001);
        poids->setMaximum(1e+09);

        formLayout->setWidget(2, QFormLayout::FieldRole, poids);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        nbEssieux = new QSpinBox(formLayoutWidget);
        nbEssieux->setObjectName(QString::fromUtf8("nbEssieux"));
        nbEssieux->setMinimum(2);

        formLayout->setWidget(3, QFormLayout::FieldRole, nbEssieux);

        cancelButton = new QPushButton(formLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        formLayout->setWidget(4, QFormLayout::LabelRole, cancelButton);

        okButton_2 = new QPushButton(formLayoutWidget);
        okButton_2->setObjectName(QString::fromUtf8("okButton_2"));

        formLayout->setWidget(4, QFormLayout::FieldRole, okButton_2);


        retranslateUi(CamionInterfaceClass);

        QMetaObject::connectSlotsByName(CamionInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *CamionInterfaceClass)
    {
        CamionInterfaceClass->setWindowTitle(QApplication::translate("CamionInterfaceClass", "CamionInterface", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CamionInterfaceClass", "Entrez un niv : ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CamionInterfaceClass", "Entrez une immattriculation : ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CamionInterfaceClass", "Entrez un poids :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CamionInterfaceClass", "Entrez un nombre d'essieux : ", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("CamionInterfaceClass", "Retour", 0, QApplication::UnicodeUTF8));
        okButton_2->setText(QApplication::translate("CamionInterfaceClass", "Valider", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CamionInterfaceClass: public Ui_CamionInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMIONINTERFACE_H
