/**
 * \file main.c
 * \brief contient la fonction main et la fonction erreure pour tester la lib
 * \author Cochard Mathieu
 * \version 1.5
 * \date 21 Octobre 2016
 *
 */



#include "matrice.h"
#include "systeme_directe.h"
#include "iterative.h"
#include "puissance.h"
#include "leverrier.h"



int main()
{


    Matrice A, B;
    int a = 0 ;
    double e;
    srand(time(NULL));


    chargerMatrice(&A, "A");
    LeverrierAmelioree(&A);
    printf("%f", e);












    libererMatrice(&A);
    //libererMatrice(&B);

    scanf("%d", &a);

    return 0;
}



