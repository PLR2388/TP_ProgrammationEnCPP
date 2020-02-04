/********************************************************************************
** Form generated from reading UI file 'confirmationsuppression.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMATIONSUPPRESSION_H
#define UI_CONFIRMATIONSUPPRESSION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfirmationSuppressionClass
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *NoButton;
    QPushButton *YesButton;

    void setupUi(QDialog *ConfirmationSuppressionClass)
    {
        if (ConfirmationSuppressionClass->objectName().isEmpty())
            ConfirmationSuppressionClass->setObjectName(QString::fromUtf8("ConfirmationSuppressionClass"));
        ConfirmationSuppressionClass->resize(400, 130);
        verticalLayoutWidget = new QWidget(ConfirmationSuppressionClass);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 401, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        formLayoutWidget = new QWidget(ConfirmationSuppressionClass);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 100, 401, 81));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        NoButton = new QPushButton(formLayoutWidget);
        NoButton->setObjectName(QString::fromUtf8("NoButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, NoButton);

        YesButton = new QPushButton(formLayoutWidget);
        YesButton->setObjectName(QString::fromUtf8("YesButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, YesButton);


        retranslateUi(ConfirmationSuppressionClass);
        QObject::connect(NoButton, SIGNAL(clicked()), ConfirmationSuppressionClass, SLOT(close()));

        QMetaObject::connectSlotsByName(ConfirmationSuppressionClass);
    } // setupUi

    void retranslateUi(QDialog *ConfirmationSuppressionClass)
    {
        ConfirmationSuppressionClass->setWindowTitle(QApplication::translate("ConfirmationSuppressionClass", "ConfirmationSuppression", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConfirmationSuppressionClass", "Voulez-vous vraiment supprimer ce vehicule?", 0, QApplication::UnicodeUTF8));
        NoButton->setText(QApplication::translate("ConfirmationSuppressionClass", "Non", 0, QApplication::UnicodeUTF8));
        YesButton->setText(QApplication::translate("ConfirmationSuppressionClass", "Oui", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfirmationSuppressionClass: public Ui_ConfirmationSuppressionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMATIONSUPPRESSION_H
