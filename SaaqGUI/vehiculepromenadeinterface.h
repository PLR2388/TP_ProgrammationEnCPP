#ifndef VEHICULEPROMENADEINTERFACE_H
#define VEHICULEPROMENADEINTERFACE_H

#include <QtGui/QDialog>
#include "ui_vehiculepromenadeinterface.h"

class VehiculePromenadeInterface : public QDialog
{
    Q_OBJECT

public:
    VehiculePromenadeInterface(QWidget *parent = 0);
    ~VehiculePromenadeInterface();
    QString reqImmatriculation() const;
    QString reqNiv() const;
    int reqNbPlaces() const;

private slots:
	void validerEnregistrement();

private:
    Ui::VehiculePromenadeInterfaceClass ui;
};

#endif // VEHICULEPROMENADEINTERFACE_H
