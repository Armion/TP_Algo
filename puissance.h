/**
 * \file puissance.h
 * \brief contient juste les prototypes des fonctions pour calculer le vecteur des valeur propres et la plus grandes valeurs propre
 * \author Cochard Mathieu
 * \version 0.9
 * \date 15 decembre 2016
 *
 */
#ifndef PUISSANCE
#define PUISSANCE

#include "matrice.h"
#include "math.h"

void methodepuissance(Matrice *A, Matrice *X, double precision); //fonction qui calcule le vecteur propre avec la methode des puissances
void diviseComposante(Matrice *V); //fonction qui sert dans la methode des puissances
double quotientRayleigh(Matrice *A, Matrice *V); //fonction pour obtenir la plus grande valeur propre avec le quotient de Rayleigh









#endif //PUISSANCE
