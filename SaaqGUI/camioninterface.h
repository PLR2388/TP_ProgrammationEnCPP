#ifndef CAMIONINTERFACE_H
#define CAMIONINTERFACE_H

#include <QtGui/QDialog>
#include "ui_camioninterface.h"

class CamionInterface : public QDialog
{
    Q_OBJECT

public:
    CamionInterface(QWidget *parent = 0);
    ~CamionInterface();
    QString reqNiv() const;
    QString reqImmatriculation() const;
    double reqPoids() const;
    int reqNbEssieux() const;
private slots:
    	void validerEnregistrement();
private:
    Ui::CamionInterfaceClass ui;
};

#endif // CAMIONINTERFACE_H
