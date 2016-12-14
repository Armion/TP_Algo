#include "matrice.h"

double traceMatrice(Matrice*A)
{
    int i;
    double trace = 0;

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

}
