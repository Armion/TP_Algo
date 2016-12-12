#include "puissance.h"
#include "math.h"


void methodepuissance(Matrice *A, Matrice *X, double precision)
{
	Matrice *X2 = NULL;
	X2 = malloc(sizeof(Matrice));
    creerMatrice(X,1, A->hauteur);
    creerMatrice(X2,1, A->hauteur);

    fillMatrice(X2,1);
    do
    {
        copierMatrice(*X2,X);
        produitMatrices(*A,*X,X2);

        diviseComposante(X2);


      } while(!(compare(X,X2, precision)));



    copierMatrice(*X2, X);


    libererMatrice(X2);

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

double quotientRayleigh(Matrice *A, Matrice *V)
{
    Matrice *temp;
    temp = malloc(sizeof(Matrice));
    double resultat ;

    produitMatrices(*A,*V, temp);
    produitMatrices(transposeMatrice(*V), *temp, temp);

    resultat = temp->matrice[0][0];

     produitMatrices(transposeMatrice(*V), *V, temp);

     if(temp->matrice[0][0] != 0)
     {
         resultat /= temp->matrice[0][0];
     }
     else
     {
         printf(" \n division par 0, impossible de calculer la plus grande valeur propre ! \n");
     }





    libererMatrice(temp);

    return resultat;
}
