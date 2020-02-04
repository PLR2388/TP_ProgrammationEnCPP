/**
 * \file   VehiculeException.h
 * \brief  Fichier contenant la déclaration de la classe VehiculeException et de ses héritiers
 * \author Equipe 60
 * \date 30 Novembre 2019
 */

#ifndef VEHICULEEXCEPTION_H_
#define VEHICULEEXCEPTION_H_

#include <string>
#include <stdexcept>
namespace saaq
{
/**
 * \class VehiculeException
 * \brief Classe de base des exceptions de vehicule.
 */
class VehiculeException: public std::runtime_error
{
public:
	VehiculeException(const std::string& p_raison);
};
/**
 * \class VehiculeDejaPresentException
 * \brief Classe pour la gestion des erreurs des vehicules déja présents.
 */

class VehiculeDejaPresentException: public VehiculeException
{
public:
	VehiculeDejaPresentException (const std::string& p_raison);
};
/**
 * \class VehiculeAbsentException
 * \brief Classe pour la gestion des erreurs des véhicules absents.
 */

class VehiculeAbsentException: public VehiculeException
{
public:
	VehiculeAbsentException (const std::string& p_raison);
};
}
#endif  // VEHICULEEXCEPTION_H_


