#include "matrice.h"

int traceMatrice(Matrice*A)
{
    int i;
    int trace = 0;
    for (i=0; i<A->hauteur; i++)
    {
        trace += A->matrice[i][i];
    }
    return trace;
}
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
}


double traceMatrice2(Matrice*A)
{
    int i;
    double trace = 0;
    for (i=0; i<A->hauteur; i++)
    {
        trace += A->matrice[i][i];
    }
    return trace;
}
void LeverrierAmelioree(Matrice *A)
{
    Matrice B;
    Matrice I;
    Matrice C;
    int i;
    creerMatrice(&B,A->hauteur,A->largeur);
    creerMatrice(&I,A->hauteur,A->largeur);
    creerMatrice(&C,A->hauteur,A->largeur);
    initialiserMatrice(&I);
    for(i=0; i<A->hauteur;i++)
    {
        I.matrice[i][i] = 1;
    }
    double tab[A->hauteur+1];
    for(i=0;i<=A->hauteur;i++)
    {
        if (i==0)
        {
            if (A->hauteur % 2 == 0)
            {
                tab[i] = 1;
            }
            else
            {
               tab[i] = -1;
            }
        }
        else
        {
            tab[i] = ((-tab[0])/(i+1))* traceMatrice2(A);
            produitMatriceScalaire(I,tab[i],&C);
            soustractionMatrice((*A),C,&B);
            produitMatrices((*A),B,A);
        }
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

}

