/*
 * Vehicule_Testeur.cpp
 * \brief Testeur de la classe Vehicule
 * \author Paul-Louis RENARD
 */

#include "Vehicule.h"
#include "gtest/gtest.h"
using namespace saaq;

/**
 * \brief Création d'une classe pour tester les méthodes de Véhicule
 */
class VehiculeDeTest: public Vehicule
{
	public:
	VehiculeDeTest(const std::string& p_niv, const std::string& p_immatriculation):Vehicule(p_niv,p_immatriculation)
	{

	}
	virtual Vehicule* clone() const
	{
		return 0;
	}
	double tarificationAnnuelle() const
	{
		return 0;
	}
	virtual std::string reqVehiculeFormate() const
	{
		return this->Vehicule::reqVehiculeFormate();
	}
	virtual void asgImmatriculation(const std::string& immatriculation)
	{
		Vehicule::asgImmatriculation(immatriculation);
	}
};

/**
 * \test Test du constructeur
 * 	   Cas valides: ConstructeurValide Création d'un objet Vehicule avec des valeurs valides
 * 	                et vérification de tous les attributs.
 *	Cas invalides: ConstructeurInvalide
 *		   NIVInvalide Le NIV n'est pas correct.
 */
TEST(Vehicule,ConstructeurValide)
{
	VehiculeDeTest vehicule("3VWFE21C04M000001","AEE 000");
	ASSERT_EQ(vehicule.reqNiv(),"3VWFE21C04M000001");
	ASSERT_EQ(vehicule.reqImmatriculation(),"AEE 000");
}

TEST(Vehicule,ConstructeurNivInvalide)
{
	ASSERT_THROW(VehiculeDeTest vehicule("3VWFE24C04M000001","AEE 000"),PreconditionException);
}

/**
 * \brief Création d'une fixture utilisé pour les tests de la classe Vehicule
 */
class VehiculeValide : public testing::Test
{
public:
	VehiculeValide():unVehicule("3VWFE21C04M000001","AEE 000")
	{

	}
	VehiculeDeTest unVehicule;
};

/**
 * \test Test de la méthode std::string& reqImmatriculation() const;
 *        Cas valides: reqImmatriculation vérifier le retour de l'immatriculation
 *        Cas invalides: aucun.
 */
TEST_F(VehiculeValide,reqImmatriculation)
{
	ASSERT_EQ(unVehicule.reqImmatriculation(),"AEE 000");
}

/**
 * \test Test de la méthode std::string& reqNiv() const;
 *        Cas valides: reqNiv vérifier le retour du NIV
 *        Cas invalides: aucun.
 */
TEST_F(VehiculeValide,reqNiv)
{
	ASSERT_EQ(unVehicule.reqNiv(),"3VWFE21C04M000001");
}

/**
 * \test Test de la méthode std::string reqVehiculeFormate();
 *        Cas valides: vérifier le retour des information sur l'objet Vehicule formaté.
 *        Cas invalides: aucun.
 */
TEST_F(VehiculeValide,reqVehiculeFormate)
{
	std::ostringstream os;
	os << "Numero de serie : " << unVehicule.reqNiv() << std::endl
	   << "Numero d'immatriculation : " << unVehicule.reqImmatriculation() << std::endl
	   << "Date d'enregistrement : " << unVehicule.reqDateEnregistrement().reqDateFormatee() << std::endl;
	ASSERT_EQ(unVehicule.reqVehiculeFormate(),os.str());
}

/**
 * \test Test de la méthode bool operator==(const Vehicule& p_vehicule) const;
 *        Cas valides: vérifier le retour des informations sur 2 objets vehicules identiques
 *        			   Verifier le retour des informations sur 2 véhicules ayant un NIV différent
 *        			   vérifier le retour des informations sur 2 véhicules ayant une immatriculation différente
 *        Cas invalides: aucun
 */
TEST_F(VehiculeValide,Egalite)
{
	ASSERT_EQ(unVehicule==unVehicule,true);
}

TEST_F(VehiculeValide,InegaliteNIV)
{
	VehiculeDeTest v("1M8GDM9AXKP042788","AEE 000");
	ASSERT_EQ(unVehicule==v,false);
}

TEST_F(VehiculeValide,InegaliteImmatriculation)
{
	VehiculeDeTest v("3VWFE21C04M000001","L123456");
	ASSERT_EQ(unVehicule==v,false);
}

