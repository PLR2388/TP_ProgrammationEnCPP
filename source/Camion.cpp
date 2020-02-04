/*
 * \file Camion.cpp
 * \brief Implementation de la classe Camion
 * \author Paul-Louis RENARD
 */

#include "Camion.h"
using namespace std;
#include <sstream>
#include "validationFormat.h"
namespace saaq
{

/**
 * \brief Constructeur avec parametres
 * \param[in] p_niv Le numéro de série
 * \param[in] p_immatriculation Le numéro d'immatriculation
 * \param[in] p_poids Le poids
 * \param[in] p_nbEssieux le nombre d'essieux
 * \pre p_poids strictement supérieur à 3000kg
 * \pre p_nbEssieur supérieur à 2
 * \pre p_immatriculation doit être valide
 * \post m_poids prend la valeur de p_poids
 * \post m_nbEssieux prend la valeur de p_nbEssieux
 * \post m_immatriculation prend la valeur de p_immatriculation
 */
Camion::Camion(const string& p_niv, const string& p_immatriculation,double p_poids,int p_nbEssieux): Vehicule(p_niv,p_immatriculation), m_poids(p_poids), m_nbEssieux(p_nbEssieux)
{
	PRECONDITION(p_poids>3000);
	PRECONDITION(p_nbEssieux>=2);
	PRECONDITION(util::validationImmatriculationCamion(p_immatriculation));

	POSTCONDITION(m_poids==p_poids);
	POSTCONDITION(m_nbEssieux==p_nbEssieux);

	INVARIANTS();
}

/**
 * \brief Acceseur pour le poids
 * \return m_poids Le poids
 */
double Camion::reqPoids() const
{
	return m_poids;
}

/**
 * \brief Acceseur pour le nombre d'essieux
 * \return m_nbEssieux Le nombre d'essieux
 */
int Camion::reqNbEssieux() const
{
	return m_nbEssieux;
}

/**
 * \brief Retourne une chaine de caractere qui contient l'information de l'objet camion
 * \return un string qui contient l'information
 */
std::string Camion::reqVehiculeFormate() const
{
	string descriptionGeneral=this->Vehicule::reqVehiculeFormate();
	ostringstream os;
	os<<descriptionGeneral
	   << "nombre d'essieux : "<<m_nbEssieux<<endl
	   << "poids : "<<m_poids <<" kg"<< endl
	   << "tarif : "<< this->tarificationAnnuelle()<<"$"<<endl;
	return os.str();
}

/**
 * \brief Mutateur pour le numéro d'immatriculation, modifie le numéro d'immatriculation
 * \param[in] p_immatriculation Le numéro d'immatriculation
 * \pre p_immatriculation doit être valide
 */
void Camion::asgImmatriculation(const string& p_immatriculation)
{
	PRECONDITION(util::validationImmatriculationCamion(p_immatriculation));
	this->Vehicule::asgImmatriculation(p_immatriculation);
	INVARIANTS();
}

/**
 * \brief Coût du renouvellement de l'immatriculation annuelle
 * \return un réel correspond à la tarification annuelle
 */
double Camion::tarificationAnnuelle() const
{
	double montantTotal=0;
	if(m_nbEssieux>=6)
	{
		montantTotal=3729.76;
	}
	else if(m_nbEssieux==5)
	{
		montantTotal=2821.76;
	}
	else if(m_nbEssieux==4)
	{
		montantTotal=2206.19;
	}
	else if(m_nbEssieux==3)
	{
		montantTotal=1566.19;
	}
	else if(m_nbEssieux==2)
	{
		if(m_poids>=4001)
		{
			montantTotal=905.28;
		}
		else
		{
			montantTotal=570.28;
		}
	}
	return montantTotal;
}

/**
 * \brief Copie de Camion sur le monceau
 * \return un objet Camion
 */
Vehicule* Camion::clone() const
{
	return new Camion(*this);
}

/**
 * \brief Implémentation pour vérifier les invariants de classe
 */
void Camion::verifieInvariant() const
{
	INVARIANT(util::validationImmatriculationCamion(reqImmatriculation()));
	INVARIANT(m_poids>3000);
	INVARIANT(m_nbEssieux>=2);
}


}


