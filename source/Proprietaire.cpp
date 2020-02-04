/*
 * \file Proprietaire.cpp
 * \brief Implementation de la classe Proprietaire
 * \author Paul-Louis RENARD
 */

#include "Proprietaire.h"
#include <sstream>
#include "VehiculeException.h"
#include "validationFormat.h"
using namespace std;
namespace saaq
{

/**
 * \brief Constructeur avec parametres
 * \param[in] p_nom Le nom du propriétaire
 * \param[in] p_prenom le prénom du propriétaire
 * \pre p_nom ne doit pas être vide
 * \pre p_prenom ne doit pas être vide
 * \post m_nom prend la valeur de p_nom
 * \post m_prenom prend la valeur de p_prenom
 */
Proprietaire::Proprietaire(const std::string& p_nom,
		const std::string& p_prenom): m_nom(p_nom), m_prenom(p_prenom)
{
	PRECONDITION(p_nom!="");
	PRECONDITION(p_prenom!="");

	POSTCONDITION(m_nom==p_nom);
	POSTCONDITION(m_prenom==p_prenom);

	INVARIANTS();
}

/**
 * \brief Contructeur copie de Proprietaire
 * \param[in] p_proprietaire un propriétaire valide
 * \post m_nom prend la valeur de p_proprietaire.m_nom
 * \post m_prenom prend la valeur de p_proprietaire.m_prenom
 */
Proprietaire::Proprietaire(const Proprietaire& p_proprietaire): m_nom(p_proprietaire.m_nom),m_prenom(p_proprietaire.m_prenom)
{
	vector<Vehicule*>::const_iterator it;
	for(it=p_proprietaire.m_vVehicules.begin();it<p_proprietaire.m_vVehicules.end();it++)
	{
		ajouterVehicule(**it);
	}

	POSTCONDITION(m_nom==p_proprietaire.m_nom);
	POSTCONDITION(m_prenom==p_proprietaire.m_prenom);

	INVARIANTS();
}

/**
 * \brief Destructeur de la classe Proprietaire
 */
Proprietaire::~Proprietaire()
{
	vector<Vehicule*>::iterator it;
	for(it=m_vVehicules.begin();it<m_vVehicules.end();it++)
	{
		delete *it;
	}
}

/**
 * \brief Acceseur pour le nom
 * \return m_nom Le nom
 */
const std::string& Proprietaire::reqNom() const
{
	return m_nom;
}

/**
 * \brief Acceseur pour le prenom
 * \return m_prenom Le prenom
 */
const std::string& Proprietaire::reqPrenom() const
{
	return m_prenom;
}

/**
 * \brief Retourne une chaine de caractere qui contient l'information de l'objet propriétaire
 * \return un string qui contient l'information
 */
std::string Proprietaire::reqProprietaireFormate() const
{
	ostringstream os;
	os 		<< "Proprietaire" <<endl
			<<"-------------------"<<endl
			<< "Nom      : " <<m_nom<<endl
			<< "Prenom   : " <<m_prenom<<endl
			<<"-------------------"<<endl;
	if(m_vVehicules.size()!=0)
	{
		vector<Vehicule*>::const_iterator it;
		for(it=m_vVehicules.begin();it<m_vVehicules.end()-1;it++)
		{
			os << (*it)->reqVehiculeFormate() <<"-------------------\n";
		}
		os << (*it)->reqVehiculeFormate() ;
	}
	return os.str();
}

/**
 * \brief Surchage de l'opérateur d'asignation
 * \param[in] p_proprietaire l'élément proprietaire que l'on veut assigner à this
 * \return un Proprietaire identique à p_proprietaire
 */
Proprietaire Proprietaire::operator =(const Proprietaire& p_proprietaire)
{
	if(this != &p_proprietaire){
		vector<Vehicule*>::iterator it;
		for(it=m_vVehicules.begin();it<m_vVehicules.end();it++)
		{
			delete *it;
		}
		m_vVehicules.clear();
		vector<Vehicule*> vehicules=p_proprietaire.m_vVehicules;
		vector<Vehicule*>::iterator it1;

		for(it1=vehicules.begin();it1<vehicules.end();it1++)
		{
			ajouterVehicule(*(*it1));
		}
		m_prenom=p_proprietaire.reqPrenom();
		m_nom=p_proprietaire.reqNom();
	}
	return *this;
}

/**
 * \brief Mutateur pour le vecteur de véhicule, ajoute un véhicule dans le vecteur
 * \param[in] p_nouveauVehicule un véhicule à ajouter
 */
void Proprietaire::ajouterVehicule(const Vehicule& p_nouveauVehicule)
{
	if(VehiculeEstDejaPresent(p_nouveauVehicule.reqNiv())) throw VehiculeDejaPresentException(p_nouveauVehicule.reqVehiculeFormate());
	m_vVehicules.push_back(p_nouveauVehicule.clone());
	INVARIANTS();
}

/**
 * \brief Mutateur pour le vecteur de véhicule, supprimer un véhicule dans le vecteur
 * \param[in] p_niv le niv du véhicule à supprimer
 * \post le véhicule de niv p_niv est effectivement supprimé
 */
void Proprietaire::supprimerVehicule(const std::string& p_niv)
{
	PRECONDITION(util::validerNiv(p_niv));
	bool trouve=false;
	if(!VehiculeEstDejaPresent(p_niv)) throw VehiculeAbsentException("Le vehicule est absent");
	vector<Vehicule*>::iterator it=m_vVehicules.begin();
	while(it<m_vVehicules.end() && !trouve){
		if((*it)->reqNiv()==p_niv)
		{
			trouve=true;
			delete *it;
			m_vVehicules.erase(it);
		}
		it++;
	}
	POSTCONDITION(!VehiculeEstDejaPresent(p_niv));
	INVARIANTS();
}

/**
 * \brief Implémentation pour vérifier les invariants de classe
 */
void Proprietaire::verifieInvariant() const
{
	INVARIANT(m_nom!="");
	INVARIANT(m_prenom!="");
}

/**
 * \brief Implémentation pour vérifier la présence d'un véhicule dans m_vVehicules
 * \param[in] p_niv niv du véhicule à vérifier la présence
 */
bool Proprietaire::VehiculeEstDejaPresent(const std::string& p_niv) const
{
	bool estPresent=false;
	vector<Vehicule*>::const_iterator it=m_vVehicules.begin();
	while(it<m_vVehicules.end() && !estPresent)
	{
		if((*it)->reqNiv()==p_niv)
			{
				estPresent=true;
			}
	}
	return estPresent;
}

} /* namespace saaq */


