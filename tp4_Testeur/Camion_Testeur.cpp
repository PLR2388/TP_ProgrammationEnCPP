/*
 * \file Camion_Testeur.cpp
 * \brief Testeur de la classe Camion
 * \author Paul-Louis RENARD
 */

#include "Camion.h"
#include "gtest/gtest.h"
using namespace saaq;


/**
 * \brief Test du constructeur
 * 	   Cas valides: ConstructeurValide Création d'un objet Camion avec des valeurs valides
 * 	                et vérification de tous les attributs.
 *	Cas invalides: ConstructeurInvalide
 *		   NIVInvalide Le NIV n'est pas correct.
 *		   ImmatriculationInvalide L'immatriculation n'est pas valide.
 *		   PoidsInvalide Le poids est inférieur à 3000kg
 *		   NbEssieuxInvalide Le nombre d'essieux est inférieur à 2
 */
TEST(Camion,ConstructeurValide)
{
	Camion camion("3VWFE21C04M000001","L000000",3562,4);
	ASSERT_EQ(camion.reqNiv(),"3VWFE21C04M000001") <<"Le NIV n'est pas identique";
	ASSERT_EQ(camion.reqImmatriculation(),"L000000")<<"L'immatriculation n'est pas identique";
	ASSERT_EQ(camion.reqPoids(),3562)<<"Le poids n'est pas identique";
	ASSERT_EQ(camion.reqNbEssieux(),4)<<"Le nombre d'essieux n'est pas identique";
}

TEST(Camion,ConstructeurNIVInvalide)
{
	ASSERT_THROW(Camion camion("45","L000000",3562,4),PreconditionException);
}

TEST(Camion,ConstructeurImmatriculationInvalide)
{
	ASSERT_THROW(Camion camion("3VWFE21C04M000001","5",3562,4),PreconditionException);
}

TEST(Camion,ConstructeurPoidsInvalide)
{
	ASSERT_THROW(Camion camion("3VWFE21C04M000001","L000000",1,4),PreconditionException);
}

TEST(Camion,ConstructeurNbEssieuxInvalide)
{
	ASSERT_THROW(Camion camion("3VWFE21C04M000001","L000000",3562,1),PreconditionException);
}

/**
 * \brief Création d'une fixture utilisé pour les tests de la classe Camion
 */
class CamionValide: public testing::Test
{
public:
	CamionValide():unCamion("3VWFE21C04M000001","L000000",3562,4)
	{
	}
	Camion unCamion;
};

/**
 * \brief Test de la méthode double reqPoids() const;
 *        Cas valides: reqPoids vérifier le retour du poids
 *        Cas invalides: aucun.
 */
TEST_F(CamionValide,reqPoids)
{
	ASSERT_EQ(unCamion.reqPoids(),3562);
}

/**
 * \brief Test de la méthode int reqNbEssieux() const;
 *        Cas valides: reqNbEssieux vérifier le retour du nombre d'essieux
 *        Cas invalides: aucun.
 */
TEST_F(CamionValide,reqNbEssieux)
{
	ASSERT_EQ(unCamion.reqNbEssieux(),4);
}

/**
 * \brief Test de la méthode std::string reqVehiculeFormate();
 *        Cas valides: vérifier le retour des information sur l'objet Camion formaté.
 *        Cas invalides: aucun.
 */
TEST_F(CamionValide,reqVehiculeFormate)
{
	std::ostringstream os;
	os << "Numero de serie : 3VWFE21C04M000001" << std::endl
	   << "Numero d'immatriculation : L000000" << std::endl
	   << "Date d'enregistrement : " << unCamion.reqDateEnregistrement().reqDateFormatee() << std::endl
	   << "nombre d'essieux : 4"<<std::endl
	   << "poids : 3562 kg"<< std::endl
	   << "tarif : 2206.19$"<<std::endl;
	ASSERT_EQ(unCamion.reqVehiculeFormate(),os.str());
}

/**
 * \brief Assigner une nouvelle immatriculation
 * 		  Cas valide : asgImmatriculationValide assigner une immatriculation valide pour un camion
 * 		  Cas invalide : asgImmatriculationInvalide assigner une immatriculation invalide pour un camion
 */
TEST_F(CamionValide,asgImmatriculationValide)
{
unCamion.asgImmatriculation("L000004");
ASSERT_EQ(unCamion.reqImmatriculation(),"L000004");
}

TEST_F(CamionValide,asgImmatriculationInvalide)
{
ASSERT_THROW(unCamion.asgImmatriculation("L0000A4"),PreconditionException);
}

/**
 * \brief Test de la méthode double tarificationAnnuelle() const;
 *        Cas valides: vérifier le retour de la tarification annuelle
 *        Cas invalides: aucun.
 */
TEST_F(CamionValide,tarificationAnnuelle)
{
	ASSERT_EQ(unCamion.tarificationAnnuelle(),2206.19);
}

/**
 * \brief Test de la méthode Vehicule* clone() const;
 *        Cas valides: vérifier que la copie s'est bien réalisée
 *        Cas invalides: aucun.
 */
TEST_F(CamionValide,ConstructeurClone)
{
	Vehicule *copie=unCamion.clone();
	Camion * c=(Camion*)copie;
	ASSERT_EQ((*c).reqNiv(),unCamion.reqNiv());
	ASSERT_EQ((*c).reqImmatriculation(),unCamion.reqImmatriculation());
	ASSERT_EQ((*c).reqDateEnregistrement(),unCamion.reqDateEnregistrement());
	ASSERT_EQ((*c).reqNbEssieux(),unCamion.reqNbEssieux());
	ASSERT_EQ((*c).reqPoids(),unCamion.reqPoids());
}



