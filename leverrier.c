#include "matrice.h"

int traceMatrice(Matrice*A,int n)
{
    int i, trace = 0;
    for (i=0; i<n; i++)
    {
        trace += A->matrice[i][i];
    }
    return trace;
}
int Leverrier(Matrice*A, int n)
{
    Matrice*B = NULL;
    creerMatrice(B,n,n);
    int tab[2][n];
    int i;
    int k;
    int resultat;
    for(i=0;i<n;i++)
    {
        puissanceMatrice(&A, &B, n);
        tab[1][i] = traceMatrice(&B,n);
        tab[2][i] = tab[1][i];
        for(k=0; k<i-1; k++)
        {
            tab[2][i] -= tab[1][k]*tab[2][i-1-k];
        }

    }
}
