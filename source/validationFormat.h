/**
 * \file validationFormat.h
 * \brief Prototypes des fonctions validationFormat
 * \author Paul-Louis RENARD
 * \date
 */
namespace util
{
bool validationImmatriculationPromenade(const std::string& p_immatriculation);
bool validationImmatriculationCamion(const std::string& p_immatriculation);
bool appartient(char p_c,char p_list[],int p_taille);
bool validerNiv (const std::string& p_niv);
int translit(char p_c);
int weight(int p_position);
int charToInt(char p_c);
}

