#include "puissance.h"
#include "math.h"


void methodepuissance(Matrice *A)
{
	Matrice *X1 = NULL;
	Matrice *X2 = NULL;
    creerMatrice(X1,1, A->hauteur);
    creerMatrice(X2,1, A->hauteur);
    fillMatrice(X1,1);
    do {
        copierMatrice(*X2,X1);
        produitMatrices(*A,*X1,X2);

      } while(!(compare(X1,X2, 0.2)));


}


void diviseComposante(Matrice *V)
{
    int i =0;

    for(i =0; i < V->hauteur; i++)
    {
        V->matrice[0][i] = V->matrice[0][i] / V->matrice[0][V->hauteur-1];
    }

}



int compare(Matrice*A, Matrice*B, double precision)
{

    if((A->hauteur == B->hauteur) && (A->largeur == B->largeur))
    {
        int i, j;

        for(i=0; i< A->hauteur; i++)
        {
            for(j=0;j< A->largeur;j++)
            {

                if((fabs(A->matrice[j][i] - B->matrice[j][i])) > precision)
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

