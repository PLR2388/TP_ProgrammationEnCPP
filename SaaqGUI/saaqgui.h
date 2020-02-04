#ifndef SAAQGUI_H
#define SAAQGUI_H

#include <QtGui/QMainWindow>
#include "ui_saaqgui.h"
#include "Proprietaire.h"

class SaaqGUI : public QMainWindow
{
    Q_OBJECT

public:
    SaaqGUI(QWidget *parent = 0);
    ~SaaqGUI();

    private slots:
	void dialogAjouterCamion();
	void dialogAjouterVehiculePromenade();
	void dialogSupprimerVehicule();


private:
    Ui::SaaqGUIClass ui;
    saaq::Proprietaire m_proprietaire;
    void ajouterCamion(const std::string& p_niv, const std::string& p_immatriculation,double p_poids,int p_nbEssieux);
    void ajouterVehiculePromenade(const std::string& p_niv,const std::string& p_immatriculation,int p_nbPlaces);
    void supprimerVehicule(const std::string& p_niv);
    void majTextProprietaire();
};

#endif // SAAQGUI_H
