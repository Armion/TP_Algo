/**
 * \file echantillon.h
 * \brief contient les prototypes fonctions pour creer les matrices de test
 * \author Cochard Mathieu
 * \version 1.5
 * \date 21 Octobre 2016
 *
 */


#ifndef ECHANTILLON
#define ECHANTILLON

#include "matrice.h"

void creerMatriceBordCarre(Matrice* matrice, int n);
void creerMatriceDingDong(Matrice * matrice, int n);
void creerMatriceCreuse(Matrice* matrice, int n);
void creerMatriceFranc(Matrice* matrice, int n);
int creerMatriceKMS(Matrice* matrice, int n, float p);
void creerMatriceHilbert(Matrice* matrice, int n);
void creerMatriceLehmer(Matrice* matrice, int n);
void creerMatriceLotkin(Matrice* matrice, int n);
void creerMatriceMoler(Matrice* matrice, int n);






#endif // ECHANTILLON
