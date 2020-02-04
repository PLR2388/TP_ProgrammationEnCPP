#include "vehiculepromenadeinterface.h"
#include "validationFormat.h"
#include "qmessagebox.h"

using namespace std;
VehiculePromenadeInterface::VehiculePromenadeInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.CancelButton,SIGNAL(clicked()),this,SLOT(close()));
	QObject::connect(ui.ValideButton,SIGNAL(clicked()),this,SLOT(validerEnregistrement()));
}

VehiculePromenadeInterface::~VehiculePromenadeInterface()
{

}

QString VehiculePromenadeInterface::reqImmatriculation() const{
	return ui.immatriculation->text();

}
QString VehiculePromenadeInterface::reqNiv() const{
	return ui.niv->text();

}
int VehiculePromenadeInterface::reqNbPlaces() const{
	return ui.nbPlaces->value();
}

void VehiculePromenadeInterface::validerEnregistrement(){
	if (!util::validationImmatriculationPromenade((string)reqImmatriculation().toStdString())){
   		QString message("L'immatriculation doit etre valide");
   		QMessageBox::information(this, "ERREUR", message);
   		return;
   	}
	else if(!util::validerNiv((string)reqNiv().toStdString())){
   		QString message("Le niv doit etre valide");
   		QMessageBox::information(this, "ERREUR", message);
   		return;
   	}
   	else{
   		accept();
   	}
}
