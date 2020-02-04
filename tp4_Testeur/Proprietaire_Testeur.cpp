/*
 * Proprietaire_Testeur.cpp
 * \brief Testeur de la classe VehiculePromenade
 * \author Paul-Louis RENARD
 */

#include "Proprietaire.h"
#include "gtest/gtest.h"
#include "Camion.h"
#include "VehiculeException.h"
using namespace saaq;

/**
 * \test Test du constructeur
 * 	   Cas valides: ConstructeurValide Création d'un objet Proprietaire avec des valeurs valides
 * 	                et vérification de tous les attributs.
 *	Cas invalides: ConstructeurInvalide
 *		   NomInvalide Le nom est vide
 *		   PrenomNomInvalide Le prénom est vide
 */
TEST(Proprietaire,ConstructeurValide)
{
Proprietaire proprietaire("Renard","Paul-Louis");
ASSERT_EQ(proprietaire.reqNom(),"Renard");
ASSERT_EQ(proprietaire.reqPrenom(),"Paul-Louis");
}

TEST(Proprietaire,ConstructeurNomInvalide
		){
	ASSERT_THROW(Proprietaire proprietaire("","Paul-Louis"),PreconditionException);
}

TEST(Proprietaire,ConstructeurPrenomNomInvalide)
{
	ASSERT_THROW(Proprietaire proprietaire("Renard",""),PreconditionException);
}

/**
 * \brief Création d'une fixture utilisé pour les tests de la classe Proprietaire
 */
class ProprietaireValide: public testing::Test
{
public:
	ProprietaireValide():unProprietaire("Renard","Paul-Louis")
	{
	}
	Proprietaire unProprietaire;
};

/**
 * \test Test de la méthode std::string reqNom() const;
 *        Cas valides: reqNom vérifier le retour du nom
 *        Cas invalides: aucun.
 */
TEST_F(ProprietaireValide,reqNom)
{
	ASSERT_EQ(unProprietaire.reqNom(),"Renard");
}

/**
 * \test Test de la méthode std::string reqPrenom() const;
 *        Cas valides: reqPrenom vérifier le retour du prénom
 *        Cas invalides: aucun.
 */
TEST_F(ProprietaireValide,reqPrenom)
{
	ASSERT_EQ(unProprietaire.reqPrenom(),"Paul-Louis");
}

/**
 * \test Test de la méthode std::string reqProprietaireFormate() const
 * 		  Cas valides: reqProprietaireFromate renvoie un string décrivant un propriétaire
 * 		  Cas invalides: aucun.
 */
TEST_F(ProprietaireValide,reqProprietaireFormate)
  {
	ASSERT_EQ(unProprietaire.reqProprietaireFormate(),"Proprietaire\n-------------------\nNom      : Renard\nPrenom   : Paul-Louis\n-------------------\n");
  }

/**
 * \test Test de la méthode void ajouterVehicule (const Vehicule& p_nouveauVehicule);
 * 		  Cas valides: ajouterVehicule ajoute un élément dans le vecteur m_vVehicules
 * 		  Cas invalides: ajouterVehiculeDejaPresent ajoute un élément déjà présent dans le vecteur m_vVehicules
 */
TEST_F(ProprietaireValide,ajouterVehicule)
{
	Camion camion("3VWFE21C04M000001","L000000",3562,4);
	unProprietaire.ajouterVehicule(camion);
	std::ostringstream os;
	os		<<"Proprietaire\n-------------------\nNom      : Renard\nPrenom   : Paul-Louis\n-------------------\nNumero de serie : 3VWFE21C04M000001\nNumero d'immatriculation : L000000\nDate d'enregistrement : "
			<<camion.reqDateEnregistrement().reqDateFormatee()
			<<"\nnombre d'essieux : 4\npoids : 3562 kg\ntarif : 2206.19$\n";
	ASSERT_EQ(unProprietaire.reqProprietaireFormate(),os.str());

}

TEST_F(ProprietaireValide,ajouterVehiculeDejaPresent)
{
	Camion camion("3VWFE21C04M000001","L000000",3562,4);
	unProprietaire.ajouterVehicule(camion);
	ASSERT_THROW(unProprietaire.ajouterVehicule(camion),VehiculeDejaPresentException);

}

/**
 * \test Test de la méthode void supprimerVehicule(const std::string& p_niv)
 * 		  Cas valides: supprimerVehicule supprime un élément dans le vecteur m_vVehicules
 * 		  Cas invalides: supprimerVehiculeNonPresent supprime un élément non présent dans le vecteur m_vVehicules
 */
TEST_F(ProprietaireValide,supprimerVehicule)
{
	Camion camion("3VWFE21C04M000001","L000000",3562,4);
	unProprietaire.ajouterVehicule(camion);
	unProprietaire.supprimerVehicule("3VWFE21C04M000001");
	std::ostringstream os;
	os		<<"Proprietaire\n-------------------\nNom      : Renard\nPrenom   : Paul-Louis\n-------------------\n";
	ASSERT_EQ(unProprietaire.reqProprietaireFormate(),os.str());
}

TEST_F(ProprietaireValide,supprimerVehiculeNonPresent)
{
	ASSERT_THROW(unProprietaire.supprimerVehicule("3VWFE21C04M000001"),VehiculeAbsentException);
}

