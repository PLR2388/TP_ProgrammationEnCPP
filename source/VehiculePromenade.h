/*
 * \file VehiculePromenade.h
 * \brief  Fichier contenant la déclaration de la classe VehiculePromenade
 * \author Paul-Louis RENARD
 */

#ifndef VEHICULEPROMENADE_H_
#define VEHICULEPROMENADE_H_

#include <string>
#include "Vehicule.h"

/**
 * \namespace saaq
 * \brief Cet espace de nom contient l'ensemble des éléments pour gérer les services du saaq
 */
namespace saaq
{
/**
 * \class VehiculePromenade
 * \brief Cette classe sert à représenter un véhicule de promenade
 *             Attributs:   std::string m_niv					Le numéro de série du véhicule de promenade
 *             				std::string m_immatriculation		Le numéro d'immatriculation du véhicule de promenade
 *             				util::Date m_dateEnregistrement		La date d'enregistrement du véhicule de promenade
 *             				int m_nbPlaces						Le nombre de places du véhicule de promenade
 */
class VehiculePromenade: public Vehicule
{
public:
	VehiculePromenade(const std::string& p_niv,const std::string& p_immatriculation,int p_nbPlaces);
	~VehiculePromenade(){};
	virtual Vehicule* clone() const;

	std::string reqVehiculeFormate() const;
	int reqNbPlaces() const;

	virtual void asgImmatriculation(const std::string& p_immatriculation);
	virtual double tarificationAnnuelle() const;

private:
	void verifieInvariant() const;
	int m_nbPlaces;
};
}
#endif /* VEHICULEPROMENADE_H_ */
