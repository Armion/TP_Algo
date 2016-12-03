#include "puissance.h"


/*
void methodepuissance(Matrice *A)
{
	int i;
	Matrice *X1 = NULL;
	Matrice *X2 = NULL;
    creerMatrice(X1,1, A->hauteur);
    creerMatrice(X2,1, A->hauteur);
    fillMatrice(X1,1);
    do {
        copierMatrice(*X2,X1);
        produitMatrices(*A,*X1,X2);

    } while(!(compare(X1,X2)));


}
*/

/*
int compare(Matrice*A, Matrice*B)
{
    int i, j;
    if((A->hauteur == B->hauteur) && (A->largeur == B->largeur))
    {
        for(i=0, i<hauteur, i++)
        {
            for(j=0,j<largeur,j++)
            {
                if(((*A)[i][j]-(*B)[i][j])>Epsilon)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    else
        return 0;
<<<<<<< Updated upstream:puissance.c
}*/
=======
}


int traceMatrice(matrice*A,int n)
{
    int i, trace = 0;
    for (i=0; i<n; i++)
    {
        trace += (*A)[i][i];
    }
    return trace;
}
int Leverrier(matrice*A, int n)
{
    matrice*B NULL;
    creerMatrice(*B,n,n);
    int tab[2][n];
    int i;
    int k;
    int resultat;
    for(i=0;i<n:i++)
    {
        puissance(&A, &B, n);
        tab[1][n] = traceMatrice(&B,n);
        tab[2][n] = tab[1][n]
        for(k=0; k<i-1; k++)
        {

        }
    }
}
>>>>>>> Stashed changes:TP4.c
