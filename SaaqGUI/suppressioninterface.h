#ifndef SUPPRESSIONINTERFACE_H
#define SUPPRESSIONINTERFACE_H

#include <QtGui/QDialog>
#include "ui_suppressioninterface.h"

class SuppressionInterface : public QDialog
{
    Q_OBJECT

public:
    SuppressionInterface(QWidget *parent = 0);
    ~SuppressionInterface();
    QString reqNiv() const;
private slots:
    void validerEnregistrement();
private:
    Ui::SuppressionInterfaceClass ui;
};

#endif // SUPPRESSIONINTERFACE_H
