/**
 * \file iterative.h
 * \brief contient les prototypes des fonctions de resolution des systemes par methode iterative
 * \author Cochard Mathieu
 * \version 1.5
 * \date 21 Octobre 2016
 *
 */


#include "matrice.h"

int jacobi(const Matrice * const A, const Matrice * const B, Matrice* X, double precision, int iterationMax);
int surrelaxion(const Matrice * const A, const Matrice * const B, Matrice* X, double precision, int iterationMax, float o);
