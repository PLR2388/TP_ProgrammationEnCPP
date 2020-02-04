# Introduction

L'objectif de ce projet était de former une interface graphique pour la SAAQ (Société de l'assurance automobile du Québec) qui permet d'affecter des véhicules avec des plaques d'immatriculations et un NIV ( Numéro d’identification d'un véhicule) valide à un propriétaire.

Ce projet n'a pas été fourni à la SAAQ puisqu'il s'agissait juste d'un contexte pour pouvoir appliquer les différents contextes en C++. 

Le projet s'étalait sur toute la session d'Automne 2019 (Septembre à Décembre) et était découpé en 4 travaux pratiques. Chaque travail pratique nous faisait avancer dans les fonctionnalités.

Le premier TP nous a fait développé 2 fonctions : une pour valider les plaques d'immatriculations des véhicules de promenades et des camions, l'autre pour valider un NIV.

Le deuxième TP nous a fait développé la classe Véhicule (dossier source), documenté le code présent avec DOXYGEN et utilisé les namespaces. 

Le troisième TP nous a fait développé la hiérarchie de classes suivante, ainsi que l'implémentation de test avec GoogleTest et de la théorie du contrat.

![Hiérarchie de classes](https://i.ibb.co/y8BQ3nL/image.png)

Le dernier TP (qui était le seul en binôme) nous a fait développé une interface Qt et la gestion des exceptions.

# Description de la structure
 
Il contient :
  - Un dossier source qui est une librairie statique où se trouve les classes métiers
  - Un dossier SaaqGUi qui contient les fichiers générant l'interface graphique Qt
  - Un dossier tp4_Testeur qui contient les tests GoogleTest des classes
  
# Librairies

Ce projet a été compilé avec l'IDE Eclipse. Il nécessite :

* Qt
* GoogleTest
* faire le lien avec la librairie statique source
