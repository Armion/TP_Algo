/**
 * \file leverrier.c
 * \brief contient les fonctions de leverrier et leverrier amelioré
 * \author Palisson Corentin
 * \version 0.9
 * \date 21 Octobre 2016
 *
 */

#include "matrice.h"

/**
 * \fn void Leverrier(Matrice*A)
 * \brief Fonction pour calculer le polynome caracteristique
 *
 * \param Matrice *A matrice dont on veut calculer le polynome caracterique
 */
void Leverrier(Matrice*A)
{
    Matrice B;
    creerMatrice(&B,A->hauteur,A->largeur);
    int tab[2][A->hauteur+1];
    int i;
    int k;
    for(i=0;i<A->hauteur+1;i++)
    {
        puissanceMatrice(A, &B, i);
        tab[1][i] = traceMatrice(&B);
        if (i==0)
        {
            if (A->hauteur % 2 == 0)
            {
                tab[2][i] = 1;
            }
            else
            {
               tab[2][i] = -1;
            }
        }

        else
        {
            tab[2][i] = 0;
            for(k=0; k<i; k++)
            {
                tab[2][i] -= tab[2][k]*tab[1][i-k];
            }
            tab[2][i] = (tab[2][i])/i;
        }
    }
    printf("Le polynome caracteristique de la matrice est : P(Lambda)=  \n");
    for(i=0;i<A->hauteur+1;i++)
    {
        if (i == 0 || tab[2][i]<0)
            printf("%d Lambda^%d",tab[2][i],A->hauteur-i);
        else if (tab[2][i]>=0)
            printf(" + %d Lambda^%d",tab[2][i],A->hauteur-i);
    }
    printf("\n \n");

    libererMatrice(&B);
}


/**
 * \fn void LeverrierAmelioree(Matrice *A)
 * \brief Fonction pour calculer le polynome caracteristique mais plus rapide que leverrier classique
 *
 * \param Matrice *A matrice dont on veut calculer le polynome caracterique
 */
void LeverrierAmelioree(Matrice *A)
{
    Matrice B;
    Matrice I;
    Matrice C;
    Matrice D;

    int i,p;
    double tab[A->hauteur+1];


    creerMatrice(&B,A->hauteur,A->largeur);
    creerMatrice(&I,A->hauteur,A->largeur);
    creerMatrice(&C,A->hauteur,A->largeur);
    initialiserMatrice(&I);
    copierMatrice(*A, &D);


    for(i=0; i< A->hauteur ; i++)
    {
        I.matrice[i][i] = 1;
    }

    if (A->hauteur % 2 == 0)
        {
            tab[0] = 1;
        }
    else
        {
            tab[0] = -1;
        }


    p = tab[0]*(-1);



    for(i = 1; i <= A->hauteur;i++)
    {
            tab[i] = p * traceMatrice(A) / i;
            produitMatriceScalaire(I,tab[i]*p,&C);
            soustractionMatrice(*A,C,&B);
            produitMatrices(D,B,A);


    }



    printf("Le polynome caracteristique de la matrice est : P(Lambda)=  \n");

    for(i=0;i<A->hauteur+1;i++)
    {
        if (i == 0 || tab[i]<0)
            printf("%f Lambda^%d",tab[i],A->hauteur-i);
        else if (tab[i]>=0)
            printf(" + %f Lambda^%d",tab[i],A->hauteur-i);
    }
    printf("\n \n");

    libererMatrice(&B);
    libererMatrice(&C);
    libererMatrice(&D);
}
