#include "camioninterface.h"
#include "validationFormat.h"
#include "qmessagebox.h"
#include <iostream>

using namespace std;
CamionInterface::CamionInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	QObject::connect(ui.okButton_2,SIGNAL(clicked()),this,SLOT(validerEnregistrement()));
}

CamionInterface::~CamionInterface()
{

}

QString CamionInterface::reqNiv() const{
	return ui.niv->text();

}
QString CamionInterface::reqImmatriculation() const{
	return ui.immatriculation->text();

}
double CamionInterface::reqPoids() const{
	return ui.poids->value();

}
int CamionInterface::reqNbEssieux() const{
	return ui.nbEssieux->value();


}

void CamionInterface::validerEnregistrement(){
	cout << (string)reqNiv().toStdString();
	if (!util::validationImmatriculationCamion((string)reqImmatriculation().toStdString())){
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
