/*
 * \file Proprietaire.h
 * \brief Prototype de la classe Proprietaire
 * \author Paul-Louis RENARD
 */

#ifndef PROPRIETAIRE_H_
#define PROPRIETAIRE_H_
#include "Vehicule.h"
#include "Camion.h"
#include "VehiculePromenade.h"
#include <vector>
/**
 * \namespace saaq
 * \brief Cet espace de nom contient l'ensemble des éléments pour gérer les services du saaq
 */
namespace saaq
{

/**
 * \class Proprietaire
 * \brief Cette classe sert à représenter un propriétaire
 *             Attributs:   std::string m_nom					Le nom du propriétaire
 *             				std::string m_prenom				Le prénom du propriétaire
 *             				std::vector<Vehicule*> m_vVehicules Les véhicules appartenant au propriétaire
 */
class Proprietaire
{
public:
	Proprietaire(const std::string& p_nom,const std::string& p_prenom);
	Proprietaire(const Proprietaire& p_proprietaire);
	~Proprietaire();
	const std::string& reqNom() const;
	const std::string& reqPrenom() const;
	std::string reqProprietaireFormate() const;

	Proprietaire operator=(const Proprietaire& p_proprietaire);

	void ajouterVehicule (const Vehicule& p_nouveauVehicule);
	void supprimerVehicule(const std::string& p_niv);

private:
	void verifieInvariant() const;

	bool VehiculeEstDejaPresent(const std::string& p_niv) const;

	std::string m_nom;
	std::string m_prenom;
	std::vector<Vehicule*> m_vVehicules;
};

} /* namespace saaq */

#endif /* PROPRIETAIRE_H_ */
