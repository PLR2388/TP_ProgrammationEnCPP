/*
 * \file VehiculePromenade.cpp
 * \brief Implantation de la classe VehiculePromenade
 * \author Paul-Louis RENARD
 */

#include "VehiculePromenade.h"
#include <sstream>
#include "validationFormat.h"
using namespace std;

namespace saaq
{

/**
 * \brief Constructeur avec parametres
 * \param[in] p_niv Le numéro de série
 * \param[in] p_immatriculation Le numéro d'immatriculation
 * \param[in] p_nbPlaces Le nombre de places
 * \pre p_nbPlaces supérieur strictement à 0
 * \post m_nbPlaces prend la valeur de p_nbPlaces
 */
VehiculePromenade::VehiculePromenade(const std::string& p_niv,
		const std::string& p_immatriculation, int p_nbPlaces) : Vehicule(p_niv,p_immatriculation),m_nbPlaces(p_nbPlaces)
{
	PRECONDITION(p_nbPlaces>0);
	PRECONDITION(util::validationImmatriculationPromenade(p_immatriculation));
	POSTCONDITION(m_nbPlaces==p_nbPlaces);
	INVARIANTS();
}

/**
 * \brief Copie de Vehicule de Promenade sur le monceau
 * \return un objet VehiculePromenade
 */
Vehicule* VehiculePromenade::clone() const
{
	return new VehiculePromenade(*this); // Appel du constructeur copie
}

/**
 * \brief Retourne une chaine de caractere qui contient l'information de l'objet vehiculePromenade
 * \return un string qui contient l'information
 */
string VehiculePromenade::reqVehiculeFormate() const
{
	string descriptionGeneral=this->Vehicule::reqVehiculeFormate();
	ostringstream os;
	os<<descriptionGeneral
	 << "nombre de places : "<< m_nbPlaces << endl
	 << "tarif : "<<this->tarificationAnnuelle() <<"$"<< endl;
	return os.str();
}

/**
 * \brief Acceseur pour le nombre de places
 * \return m_nbPlaces Le nombre de places
 */
int VehiculePromenade::reqNbPlaces() const
{
	return m_nbPlaces;
}

/**
 * \brief Mutateur pour le numéro d'immatriculation, modifie le numéro d'immatriculation
 * \param[in] p_immatriculation Le numéro d'immatriculation
 * \pre p_immatriculation doit être valide
 */
void VehiculePromenade::asgImmatriculation(const std::string& p_immatriculation)
{
	PRECONDITION(util::validationImmatriculationPromenade(p_immatriculation));
	this->Vehicule::asgImmatriculation(p_immatriculation);
	INVARIANTS();
}

/**
 * \brief Coût du renouvellement de l'immatriculation annuelle
 * \return un réel correspond à la tarification annuelle
 */
double VehiculePromenade::tarificationAnnuelle() const
{
	return 224.04;
}

/**
 * \brief Implémentation pour vérifier les invariants de classe
 */
void VehiculePromenade::verifieInvariant() const
{
	INVARIANT(util::validationImmatriculationPromenade(reqImmatriculation()));
	INVARIANT(m_nbPlaces>0);
}

}
