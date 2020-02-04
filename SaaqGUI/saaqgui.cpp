#include "saaqgui.h"
#include "camioninterface.h"
#include "vehiculepromenadeinterface.h"
#include "suppressioninterface.h"
#include "VehiculeException.h"
#include "qmessagebox.h"
#include "confirmationsuppression.h"
using namespace saaq;

SaaqGUI::SaaqGUI(QWidget *parent)
    : QMainWindow(parent), m_proprietaire("De Funes","Louis")
{
	ui.setupUi(this);
	setWindowTitle(tr("Saaq"));
	ui.textBrowser->setText(m_proprietaire.reqProprietaireFormate().c_str());
	QObject::connect(ui.actionQUITTER,SIGNAL(triggered()),this,SLOT(close()));
	QObject::connect(ui.AjouterCamionAction,SIGNAL(triggered()),this,SLOT(dialogAjouterCamion()));
	QObject::connect(ui.AjoutVehiculePromenadeAction,SIGNAL(triggered()),this,SLOT(dialogAjouterVehiculePromenade()));
}

SaaqGUI::~SaaqGUI()
{

}

void SaaqGUI::dialogAjouterCamion(){
CamionInterface SaisiCamion(this);
if(SaisiCamion.exec()){
	ajouterCamion((std::string)SaisiCamion.reqNiv().toStdString(),(std::string)SaisiCamion.reqImmatriculation().toStdString(),SaisiCamion.reqPoids(),SaisiCamion.reqNbEssieux());
}
}

void SaaqGUI::dialogAjouterVehiculePromenade(){
VehiculePromenadeInterface SaisiVehicule(this);
if(SaisiVehicule.exec()){
	ajouterVehiculePromenade((std::string)SaisiVehicule.reqNiv().toStdString(),(std::string)SaisiVehicule.reqImmatriculation().toStdString(),SaisiVehicule.reqNbPlaces());
}
}

void SaaqGUI::dialogSupprimerVehicule(){
	SuppressionInterface supprimVehiculeInterface(this);
	if(supprimVehiculeInterface.exec()){
		ConfirmationSuppression confirmationInterface(this);
		if(confirmationInterface.exec()){
			supprimerVehicule((std::string)supprimVehiculeInterface.reqNiv().toStdString());
		}

	}
}

void SaaqGUI::ajouterCamion(const std::string& p_niv, const std::string& p_immatriculation,double p_poids,int p_nbEssieux){
	try
	{
		Camion camion(p_niv,p_immatriculation,p_poids,p_nbEssieux);
		m_proprietaire.ajouterVehicule(camion);
		majTextProprietaire();
	}
	catch(VehiculeDejaPresentException& e)
	{
		QString message = (e.what());
		QMessageBox::information(this, "ERREUR", message);
	}

}
void SaaqGUI::ajouterVehiculePromenade(const std::string& p_niv,const std::string& p_immatriculation,int p_nbPlaces){
	try
	{
		VehiculePromenade vehiculePromenade(p_niv,p_immatriculation,p_nbPlaces);
		m_proprietaire.ajouterVehicule(vehiculePromenade);
		majTextProprietaire();
	}
	catch(VehiculeDejaPresentException& e)
	{
		QString message = (e.what());
		QMessageBox::information(this, "ERREUR", message);
	}

}
void SaaqGUI::supprimerVehicule(const std::string& p_niv)
{
	try
	{
		m_proprietaire.supprimerVehicule(p_niv);
		majTextProprietaire();
	}
	catch(VehiculeAbsentException& e){
		QString message = (e.what());
		QMessageBox::information(this, "ERREUR", message);
	}
}

void SaaqGUI::majTextProprietaire(){
	ui.textBrowser->setText(m_proprietaire.reqProprietaireFormate().c_str());
}

