/*
 * VehiculePromenade_Testeur.cpp
 * \brief Testeur de la classe VehiculePromenade
 * \author Paul-Louis RENARD
 */

#include "VehiculePromenade.h"
#include "gtest/gtest.h"
using namespace saaq;


/**
 * \test Test du constructeur
 * 	   Cas valides: ConstructeurValide Création d'un objet VehiculePromenade avec des valeurs valides
 * 	                et vérification de tous les attributs.
 *	Cas invalides: ConstructeurInvalide
 *		   NIVInvalide Le NIV n'est pas correct.
 *		   ImmatriculationInvalide L'immatriculation n'est pas valide.
 *		   NbPlacesInvalide Le nombre de place est de 0
 */
TEST(VehiculePromenade,ConstructeurValide)
{
	VehiculePromenade vehiculePromenade("3VWFE21C04M000001","AEE 000",4);
	ASSERT_EQ(vehiculePromenade.reqNiv(),"3VWFE21C04M000001");
	ASSERT_EQ(vehiculePromenade.reqImmatriculation(),"AEE 000");
	ASSERT_EQ(vehiculePromenade.reqNbPlaces(),4);
}

TEST(VehiculePromenade,ConstructeurNIVInvalide)
{
	ASSERT_THROW(VehiculePromenade vehiculePromenade("31","AEE 000",4),PreconditionException);
}

TEST(VehiculePromenade,ConstructeurImmatriculationInvalide)
{
	ASSERT_THROW(VehiculePromenade vehiculePromenade("3VWFE21C04M000001","000",4),PreconditionException);
}

TEST(VehiculePromenade,ConstructeurNbPlacesInvalide)
{
	ASSERT_THROW(VehiculePromenade vehiculePromenade("3VWFE21C04M000001","AEE 000",0),PreconditionException);
}

/**
 * \brief Création d'une fixture utilisé pour les tests de la classe VehiculePromenade
 */
class VehiculePromenadeValide: public testing::Test
{
public:
	VehiculePromenadeValide():unVehiculePromenade("3VWFE21C04M000001","AEE 000",4)
	{

	}
	VehiculePromenade unVehiculePromenade;
};

/**
 * \brief Test de la méthode Vehicule* clone() const;
 *        Cas valides: vérifier que la copie s'est bien réalisée
 *        Cas invalides: aucun.
 */
TEST_F(VehiculePromenadeValide,clone)
{
	Vehicule *copie=unVehiculePromenade.clone();
	VehiculePromenade* vp=(VehiculePromenade*) copie;
	ASSERT_EQ((*vp).reqNiv(),unVehiculePromenade.reqNiv());
	ASSERT_EQ((*vp).reqImmatriculation(),unVehiculePromenade.reqImmatriculation());
	ASSERT_EQ((*vp).reqDateEnregistrement(),unVehiculePromenade.reqDateEnregistrement());
	ASSERT_EQ((*vp).reqNbPlaces(),unVehiculePromenade.reqNbPlaces());
}

/**
 * \test Test de la méthode std::string reqVehiculeFormate();
 *        Cas valides: vérifier le retour des information sur l'objet VehiculePromenade formaté.
 *        Cas invalides: aucun.
 */
TEST_F(VehiculePromenadeValide,reqVehiculeFormate)
{
	std::ostringstream os;
	os << "Numero de serie : 3VWFE21C04M000001" << std::endl
	   << "Numero d'immatriculation : AEE 000" << std::endl
	   << "Date d'enregistrement : " << unVehiculePromenade.reqDateEnregistrement().reqDateFormatee() << std::endl
	   << "nombre de places : 4"<<std::endl
	   << "tarif : 224.04$"<<std::endl;
	ASSERT_EQ(unVehiculePromenade.reqVehiculeFormate(),os.str());
}

/**
 * \test Test de la méthode int reqNbPlaces() const;
 *        Cas valides: reqNbPlaces vérifier le retour du nombre de places
 *        Cas invalides: aucun.
 */
TEST_F(VehiculePromenadeValide,reqNbPlaces)
{
	ASSERT_EQ(unVehiculePromenade.reqNbPlaces(),4);
}

/**
 * \test Assigner une nouvelle immatriculation
 * 		  Cas valide : asgImmatriculationValide assigner une immatriculation valide d'un vehicule de promenade
 * 		  Cas invalide : asgImmatriculationInvalide assigner une immatriculation valide pour un camion
 */
TEST_F(VehiculePromenadeValide,asgImmatriculationValide)
{
	unVehiculePromenade.asgImmatriculation("000H000");
	ASSERT_EQ(unVehiculePromenade.reqImmatriculation(),"000H000");
}

TEST_F(VehiculePromenadeValide,asgImmatriculationInvalide)
{
	ASSERT_THROW(unVehiculePromenade.asgImmatriculation("L000000"),PreconditionException);
}

/**
 * \test Test de la méthode double tarificationAnnuelle() const;
 *        Cas valides: vérifier le retour de la tarification annuelle
 *        Cas invalides: aucun.
 */
TEST_F(VehiculePromenadeValide,tarificationAnnuelle)
{
	ASSERT_EQ(unVehiculePromenade.tarificationAnnuelle(),224.04);
}


