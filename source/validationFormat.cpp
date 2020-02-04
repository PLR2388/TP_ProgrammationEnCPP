/**
 * \file validationFormat.cpp
 * \brief Implementation des fonctions validationFormat
 * \author Paul-Louis RENARD
 * \date
 */

#include <iostream>

using namespace std;

#include "validationFormat.h"

/**
 * Contient les entiers sous formes de caractères autorisés
 */
char ENTIER[]={'0','1','2','3','4','5','6','7','8','9'};

/**
 * Contient l'alphabet en majuscule sous formes de caractères autorisés
 */
char ALPHABET[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','P','Q','R','S','T','U','V','W','X','Y','Z'}; //Alphabet sans la lettre O

/**
 * Contient la taille du tableau ALPHABET
 */
const int TAILLE_ALPHABET=25;

/**
 * Contient la taille du tableau ENTIER
 */
const int TAILLE_ENTIER=10;

namespace util
{

/**
 * \brief Vérifie si la plaque d'immatriculation d'un véhicule de promenade est valide
 * \param[in] p_immatriculation qui est un numéro d'immatriculation
 * \return un booléen indiquant si le numéro d'immatriculation est valide
 */
bool validationImmatriculationPromenade(const std::string& p_immatriculation)
{
	bool valide=false;
		int taille=p_immatriculation.length();
		if(taille>=4)
		{
			if(taille==4) //Si elle n'est que de 4 caractères, elle ne doit être constituée que de lettres
			{
				if(appartient(p_immatriculation[0],ALPHABET,TAILLE_ALPHABET) && appartient(p_immatriculation[1],ALPHABET,TAILLE_ALPHABET) && appartient(p_immatriculation[2],ALPHABET,TAILLE_ALPHABET) && appartient(p_immatriculation[3],ALPHABET,TAILLE_ALPHABET))
				{
						valide=true;
				}
			}
			else if(taille==7)
			{
				if(appartient(p_immatriculation[0],ALPHABET,TAILLE_ALPHABET))
				{	//Si la plaque commence par une lettre
					if(appartient(p_immatriculation[1],ALPHABET,TAILLE_ALPHABET))
					{	//S'il y a deux lettres au début, et qu'elle est de taille 7, il n'y a que une plaque de type ABC 000 qui est valide
						if(appartient(p_immatriculation[2],ALPHABET,TAILLE_ALPHABET) && p_immatriculation[3]==' ' && appartient(p_immatriculation[4],ENTIER,TAILLE_ENTIER) && appartient(p_immatriculation[5],ENTIER,TAILLE_ENTIER) && appartient(p_immatriculation[6],ENTIER,TAILLE_ENTIER)){
							valide=true;
						}
					}
					else if(appartient(p_immatriculation[1],ENTIER,TAILLE_ENTIER) && appartient(p_immatriculation[2],ENTIER,TAILLE_ENTIER))
					{ //Si la plaque commence par une lettre suivie de 2 chiffres, il n'y a que 2 types de plaques valides : E00 ABC et L000000
						if(p_immatriculation[3]==' ')
						{
							if(appartient(p_immatriculation[4],ALPHABET,TAILLE_ALPHABET) && appartient(p_immatriculation[5],ALPHABET,TAILLE_ALPHABET) && appartient(p_immatriculation[6],ALPHABET,TAILLE_ALPHABET))
							{
								valide=true;
							}
						}
					}
				}
				else if(appartient(p_immatriculation[0],ENTIER,TAILLE_ENTIER) && appartient(p_immatriculation[1],ENTIER,TAILLE_ENTIER) && appartient(p_immatriculation[2],ENTIER,TAILLE_ENTIER))
				{	//Si la plaque commence par 3 chiffres, il y a 2 types de plaques valides : 000 ABC et 000H000
					if(p_immatriculation[3]==' ')
					{
						if(appartient(p_immatriculation[4],ALPHABET,TAILLE_ALPHABET) && appartient(p_immatriculation[5],ALPHABET,TAILLE_ALPHABET) && appartient(p_immatriculation[6],ALPHABET,TAILLE_ALPHABET))
						{
							valide=true;
						}
					}
					else if(appartient(p_immatriculation[3],ALPHABET,TAILLE_ALPHABET))
					{
						if( appartient(p_immatriculation[4],ENTIER,TAILLE_ENTIER) && appartient(p_immatriculation[5],ENTIER,TAILLE_ENTIER) && appartient(p_immatriculation[6],ENTIER,TAILLE_ENTIER)){
							valide=true;
						}
					}
				}
			}

		}
		return valide;
}

/**
 * \brief Vérifie si la plaque d'immatriculation d'un camion est valide
 * \param[in] p_immatriculation qui est un numéro d'immatriculation
 * \return un booléen indiquant si le numéro d'immatriculation est valide
 */
bool validationImmatriculationCamion(const std::string& p_immatriculation)
{
	bool valide=false;
	int taille=p_immatriculation.length();
	if(taille==7){
		if(p_immatriculation[0]=='L')
		{
			if(appartient(p_immatriculation[1],ENTIER,TAILLE_ENTIER) && appartient(p_immatriculation[2],ENTIER,TAILLE_ENTIER) && appartient(p_immatriculation[3],ENTIER,TAILLE_ENTIER) && appartient(p_immatriculation[4],ENTIER,TAILLE_ENTIER) && appartient(p_immatriculation[5],ENTIER,TAILLE_ENTIER) && appartient(p_immatriculation[6],ENTIER,TAILLE_ENTIER))
			{
				valide=true;
			}
		}
	}
	return valide;
}

/**
 * \brief Vérifie un caractère appartient à une liste de caractère
 * \param[in] p_c qui est un caractère
 * \param[in] p_list[] qui est un tableau de caractère
 * \param[in] p_taille qui est la taille du tableau de caractère
 * \return un booléen indiquant si le caractère appartient au tableau de caractère
 */
bool appartient(char p_c,char p_list[],int p_taille)
{
	bool estDedans=false;
	int i=0;
	while(i<p_taille && !estDedans)
	{
		if(p_list[i]==p_c)
		{
			estDedans=true;
		}
		else
		{
			i++;
		}
	}
	return estDedans;
}

/**
 * \brief Vérifie si le numéro de série est valide
 * \param[in] p_niv qui est un numéro de série
 * \return un booléen indiquant si le numéro de série est valide
 */
bool validerNiv (const std::string& p_niv)
{
	int transliterating[17];
	bool valide=false;
	bool errorTransliterating=false;
	int i=0;
	int products[17];
	if(p_niv.length()==17)
	{
		while(i<17 && !errorTransliterating)
		{
			if(appartient(p_niv[i],ALPHABET,TAILLE_ALPHABET))
			{
				switch(p_niv[i]){
				case 'I': errorTransliterating=true; break;
				case 'O': errorTransliterating=true; break;
				case 'Q': errorTransliterating=true; break;
				default: transliterating[i]=translit(p_niv[i]);
				}
			}
			else if(appartient(p_niv[i],ENTIER,TAILLE_ENTIER))
			{
				transliterating[i]=charToInt(p_niv[i]);
			}
			else
			{
				errorTransliterating=true;
			}
			i++;
		}
		if(!errorTransliterating)
		{
			int somme=0;
			for(i=0;i<17;i++)
			{
				products[i]=transliterating[i]*weight(i);
				somme+=products[i];
			}
			int check_digit=somme%11;
			if(check_digit==charToInt(p_niv[8]))
			{
				valide=true;
			}
			else if(check_digit==10 && p_niv[8]=='X')
			{
				valide=true;
			}
		}

	}
	return valide;
}

/**
 * \brief Associe une lettre à un chiffre
 * \param[in] p_c qui est un caractère
 * \return un entier associé au caractère
 */
int translit(char p_c)
{
	char conversion=0;
	switch(p_c)
	{
	case 'A': conversion=1; break;
	case 'B': conversion=2; break;
	case 'C': conversion=3; break;
	case 'D': conversion=4; break;
	case 'E': conversion=5; break;
	case 'F': conversion=6; break;
	case 'G': conversion=7; break;
	case 'H': conversion=8; break;
	case 'J': conversion=1; break;
	case 'K': conversion=2; break;
	case 'L': conversion=3; break;
	case 'M': conversion=4; break;
	case 'N': conversion=5; break;
	case 'P': conversion=7; break;
	case 'R': conversion=9; break;
	case 'S': conversion=2; break;
	case 'T': conversion=3; break;
	case 'U': conversion=4; break;
	case 'V': conversion=5; break;
	case 'W': conversion=6; break;
	case 'X': conversion=7; break;
	case 'Y': conversion=8; break;
	case 'Z': conversion=9; break;
	//Il n'y a pas de cas default car il a été prévu à l'avance.
	}
	return conversion;
}

/**
 * \brief Associe un poids en fonction de la position dans le numéro de série
 * \param[in] p_position qui est la position dans le numéro de série
 * \return un entier correspond au poids
 */
int weight(int p_position)
{
	int valeur=0;
	switch(p_position)
	{
	case 0: valeur=8; break;
	case 1: valeur=7; break;
	case 2: valeur=6; break;
	case 3: valeur=5; break;
	case 4: valeur=4; break;
	case 5: valeur=3; break;
	case 6: valeur=2; break;
	case 7: valeur=10; break;
	case 8: valeur=0; break;
	case 9: valeur=9; break;
	case 10: valeur=8; break;
	case 11: valeur=7; break;
	case 12: valeur=6; break;
	case 13: valeur=5; break;
	case 14: valeur=4; break;
	case 15: valeur=3; break;
	case 16: valeur=2; break;
	}
	return valeur;
}





/**
 * \brief Convertis un caractère entier en entier
 * \param[in] p_c un caractère
 * \return un entier
 */
int charToInt(char p_c)
{
	int valeur;
	switch(p_c)
	{
	case '0': valeur=0; break;
	case '1': valeur=1; break;
	case '2': valeur=2; break;
	case '3': valeur=3; break;
	case '4': valeur=4; break;
	case '5': valeur=5; break;
	case '6': valeur=6; break;
	case '7': valeur=7; break;
	case '8': valeur=8; break;
	case '9': valeur=9; break;
	default: valeur=-1; break;
	}
	return valeur;
}



}  // namespace util
