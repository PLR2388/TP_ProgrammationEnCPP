/*
 * \file Camion.h
 * \brief Prototype de la classe Camion
 * \author Paul-Louis RENARD
 */

#ifndef CAMION_H_
#define CAMION_H_

#include "Vehicule.h"
#include <string>

/**
 * \namespace saaq
 * \brief Cet espace de nom contient l'ensemble des éléments pour gérer les services du saaq
 */
namespace saaq
{

/**
 * \class Camion
 * \brief Cette classe sert à représenter un camion
 *             Attributs:   std::string m_niv					Le numéro de série du camion
 *             				std::string m_immatriculation		Le numéro d'immatriculation du camion
 *             				util::Date m_dateEnregistrement		La date d'enregistrement du camion
 *             				double m_poids						Le poids du camion
 *             				int m_nbEssieux						Le nombre d'essieux du camion
 */
class Camion: public Vehicule
{
public:
	Camion(const std::string& p_niv, const std::string& p_immatriculation,double p_poids,int p_nbEssieux);
	~Camion(){};

	double reqPoids() const;
	int reqNbEssieux() const;
	std::string reqVehiculeFormate() const;

	virtual void asgImmatriculation(const std::string& p_immatriculation);

	virtual double tarificationAnnuelle() const;
	virtual Vehicule* clone() const;

private:
	void verifieInvariant() const;
	double m_poids;
	int m_nbEssieux;
};
}
#endif /* CAMION_H_ */
