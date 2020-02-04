/**
 * \file Vehicule.h
 * \brief Prototype de la classe Vehicule
 * \author Paul-Louis RENARD
 */

#ifndef VEHICULE_H_
#define VEHICULE_H_

#include <string>
#include "Date.h"
/**
 * \namespace saaq
 * \brief Cet espace de nom contient l'ensemble des éléments pour gérer les services du saaq
 */
namespace saaq
{
/**
 * \class Vehicule
 * \brief Cette classe sert à représenter un véhicule
 *             Attributs:   std::string m_niv					Le numéro de série du véhicule
 *             				std::string m_immatriculation		Le numéro d'immatriculation du véhicule
 *             				util::Date m_dateEnregistrement		La date d'enregistrement du véhicule
 */
class Vehicule
{
public:
	Vehicule(const std::string& p_niv, const std::string& p_immatriculation);

	virtual ~Vehicule(){};
	virtual Vehicule* clone() const=0;
	virtual double tarificationAnnuelle() const=0;

	const util::Date& reqDateEnregistrement() const;
	const std::string& reqImmatriculation() const;
	const std::string& reqNiv() const;
	virtual std::string reqVehiculeFormate() const;

	bool operator==(const Vehicule& p_vehicule) const;
protected:
	virtual void asgImmatriculation(const std::string& immatriculation)=0;

private:
	void verifieInvariant() const;
	std::string m_niv;
	std::string m_immatriculation;
	util::Date m_dateEnregistrement;
};

} /* namespace saaq */

#endif /* VEHICULE_H_ */
