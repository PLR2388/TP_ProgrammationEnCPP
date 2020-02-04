/********************************************************************************
** Form generated from reading UI file 'suppressioninterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRESSIONINTERFACE_H
#define UI_SUPPRESSIONINTERFACE_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SuppressionInterfaceClass
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *niv;
    QPushButton *CancelButton;
    QPushButton *ValiderButton;

    void setupUi(QDialog *SuppressionInterfaceClass)
    {
        if (SuppressionInterfaceClass->objectName().isEmpty())
            SuppressionInterfaceClass->setObjectName(QString::fromUtf8("SuppressionInterfaceClass"));
        SuppressionInterfaceClass->resize(400, 300);
        formLayoutWidget = new QWidget(SuppressionInterfaceClass);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 421, 301));
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

        CancelButton = new QPushButton(formLayoutWidget);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        formLayout->setWidget(1, QFormLayout::LabelRole, CancelButton);

        ValiderButton = new QPushButton(formLayoutWidget);
        ValiderButton->setObjectName(QString::fromUtf8("ValiderButton"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ValiderButton);


        retranslateUi(SuppressionInterfaceClass);
        QObject::connect(CancelButton, SIGNAL(clicked()), SuppressionInterfaceClass, SLOT(close()));

        QMetaObject::connectSlotsByName(SuppressionInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *SuppressionInterfaceClass)
    {
        SuppressionInterfaceClass->setWindowTitle(QApplication::translate("SuppressionInterfaceClass", "SuppressionInterface", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SuppressionInterfaceClass", "Entrez un niv : ", 0, QApplication::UnicodeUTF8));
        CancelButton->setText(QApplication::translate("SuppressionInterfaceClass", "Retour", 0, QApplication::UnicodeUTF8));
        ValiderButton->setText(QApplication::translate("SuppressionInterfaceClass", "Valider", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SuppressionInterfaceClass: public Ui_SuppressionInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRESSIONINTERFACE_H
