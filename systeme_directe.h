/**
 * \file systeme_directe.h
 * \brief contient les prototypes fonctions de resolution directe des systemes
 * \author Cochard Mathieu
 * \version 1.5
 * \date 21 Octobre 2016
 *
 */


#ifndef SYSTEME_DIRECTE
#define SYSTEME_DIRECTE
#include "matrice.h"




int cholesky (const Matrice* const A, const Matrice* const B, Matrice* R);
int gauss(const Matrice*  const A, const Matrice* const B, Matrice* X);
void remonter(Matrice* A, Matrice* B, Matrice* X);
void descendre(Matrice* A, Matrice* B, Matrice* X);





#endif // SYSTEME_DIRECTE
