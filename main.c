/**
 * \file main.c
 * \brief contient la fonction main et la fonction erreure pour tester la lib
 * \author Cochard Mathieu
 * \version 1.5
 * \date 21 Octobre 2016
 *
 */



#include "matrice.h"
#include "echantillon.h"
#include "systeme_directe.h"
#include "iterative.h"
#include "test.h"



int main()
{


    Matrice A, B, X;
    int a = 0 ;
    srand(time(NULL));

    chargerMatrice(&A, "A");
    chargerMatrice(&B, "B");
    gauss(&A, &B, &X);
    afficherMatrice(&X);








    libererMatrice(&A);
    libererMatrice(&B);
    libererMatrice(&X);

    scanf("%d", &a);

    return 0;
}



