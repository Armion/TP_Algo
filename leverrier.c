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
void Leverrier(Matrice*A, int n)
{
    Matrice B;
    creerMatrice(&B,n,n);
    int tab[2][n+1];
    int i;
    int k;
    for(i=0;i<n+1;i++)
    {
        puissanceMatrice(&A, &B, i);
        tab[1][i] = traceMatrice(&B,n);
        if (i==0)
        {
            if (n % 2 == 0)
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
    for(i=0;i<n+1;i++)
    {
        printf("%d Lambda^%d +",tab[2][i],n-i);
    }
}
