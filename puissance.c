#include "puissance.h"
#include "math.h"


void methodepuissance(Matrice *A)
{
	Matrice *X1 = NULL;
	Matrice *X2 = NULL;
    creerMatrice(X1,1, A->hauteur);
    creerMatrice(X2,1, A->hauteur);
    fillMatrice(X1,1);
    //do {
        copierMatrice(*X2,X1);
        produitMatrices(*A,*X1,X2);

    //} while(!(compare(X1,X2)));


}



int compare(Matrice*A, Matrice*B)
{

    if((A->hauteur == B->hauteur) && (A->largeur == B->largeur))
    {
        int i, j;

        for(i=0; i< A->hauteur; i++)
        {
            for(j=0;j< A->largeur;j++)
            {

                if((fabs(A->matrice[j][i] - B->matrice[j][i])) > 0.5)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    else
        return 0;
}

