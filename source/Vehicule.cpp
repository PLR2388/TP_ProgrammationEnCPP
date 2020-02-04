/**
 * \file Vehicule.cpp
 * \brief Implementation de la classe Vehicule
 * \author Paul-Louis RENARD
 */

#include "Vehicule.h"
#include <sstream>
#include "validationFormat.h"
using namespace std;

namespace saaq
{

/**
 * \brief Constructeur avec parametres
 * \param[in] p_niv Le numéro de série
 * \param[in] p_immatriculation Le numéro d'immatriculation
 * \pre p_niv doit être valide
 * \post m_niv prend la valeur de p_niv
 * \post m_immatriculation prend la valeur de p_immatriculation
 */
Vehicule::Vehicule(const string& p_niv,const  string& p_immatriculation) : m_niv(p_niv),m_immatriculation(p_immatriculation),m_dateEnregistrement()
{
	PRECONDITION(util::validerNiv(p_niv))

	POSTCONDITION(m_niv==p_niv);
	POSTCONDITION(m_immatriculation==p_immatriculation);

	INVARIANTS();
}


/**
 * \brief Acceseur pour la date d'enregistrement
 * \return m_dateEnregistrement La date d'enregistrement
 */
const util::Date& Vehicule::reqDateEnregistrement() const
{
	return m_dateEnregistrement;
}

/**
 * \brief Acceseur pour le numéro d'immatriculation
 * \return m_immatriculation Le numéro d'immatriculation
 */
const string& Vehicule::reqImmatriculation() const
{
	return m_immatriculation;
}

/**
 * \brief Acceseur pour le numéro de série
 * \return m_niv Le numéro de série
 */
const string& Vehicule::reqNiv() const
{
	return m_niv;
}

/**
 * \brief Retourne une chaine de caractere qui contient l'information de l'objet vehicule
 * \return un string qui contient l'information
 */
string Vehicule::reqVehiculeFormate() const
{
	ostringstream os;
	os << "Numero de serie : " << m_niv << endl
	   << "Numero d'immatriculation : " << m_immatriculation << endl
	   << "Date d'enregistrement : " << m_dateEnregistrement.reqDateFormatee() << endl;
	return os.str();
}

/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_vehicule qui est un véhicule valide
 * \return un booléen indiquant si les deux véhicules sont égals ou pas
 */
bool Vehicule::operator==(const Vehicule& p_vehicule) const
{
	return m_niv==p_vehicule.reqNiv() && m_immatriculation==p_vehicule.reqImmatriculation() && m_dateEnregistrement==p_vehicule.reqDateEnregistrement();

}

/**
 * \brief Mutateur pour le numéro d'immatriculation, modifie le numéro d'immatriculation
 * \param[in] p_immatriculation Le numéro d'immatriculation
 * \post m_immatriculation prend la valeur de p_immatriculation
 */
void Vehicule::asgImmatriculation(const string& p_immatriculation)
{
		m_immatriculation = p_immatriculation;
		POSTCONDITION(m_immatriculation==p_immatriculation);
		INVARIANTS();
}

/**
 * \brief Implémentation pour vérifier les invariants de classe
 */
void Vehicule::verifieInvariant() const
{
	INVARIANT(util::validerNiv(m_niv));
}

} /* namespace saaq */



