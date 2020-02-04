/**
 * \file VehiculeException.cpp
 * \brief Implantation de la classe VehiculeException et de ses héritiers
 * \author Equipe60
 * \date 30 Novembre 2019
 * \version révisée balises Doxygen C++ normes H2014
 */
#include "VehiculeException.h"
#include <sstream>

using namespace std;
namespace saaq
{
/**
 * \brief Constructeur de la classe de base VehiculeException
 */
VehiculeException::VehiculeException(const std::string& p_raison):
		std::runtime_error(p_raison)
		{
			
		}

/**
 * \brief Constructeur de la classe VehiculeDejaPresentException \n
 *    	Le constructeur public AssertionException(...)initialise
 *     	sa classe de base VehiculeException. 
 *		La classe représente l'erreur d'un véhicule ayant déja été affecté à un propriétaire.
 */

 VehiculeDejaPresentException::VehiculeDejaPresentException(const std::string& p_raison):
		VehiculeException(p_raison)
		{
			
		}

 /**
  * \brief Constructeur de la classe VehiculeAbsentException en initialisant la classe de base VehiculeException.
  * 		 La classe représente l'erreur d'un véhicule n'appartenant pas au propriétaire.
  */
 VehiculeAbsentException::VehiculeAbsentException(const std::string& p_raison):
		VehiculeException(p_raison)
		{
			
		}
}
