 /**
 * \file puissance.c
 * \brief contient les fonctions pour le calcule des valeurs propre par la methode de puissances
 * \author Cochard Mathieu
 * \version 1.5
 * \date 15 decembre 2016
 *
 */

 #include "puissance.h"


/**
 * \fn void methodepuissance(Matrice *A, Matrice *X, double precision)
 * \brief Fonction pour calculer les valeurs propres par la methode des puissances
 *
 * \param Matrice *A matrice dont on veut calculer les valeurs propres
 * \param Matrice *X vecteur qui contient les valeurs propres
 * \param double precision la precision voulue pour les valeurs propres
 */
void methodepuissance(Matrice *A, Matrice *X, double precision)
{
    //on declare une matrice (un vecteur) temporaire et initialise nos vecteurs
	Matrice *X2 = NULL;
	X2 = malloc(sizeof(Matrice));
    creerMatrice(X,1, A->hauteur);
    creerMatrice(X2,1, A->hauteur);

    fillMatrice(X2,1);

    //boucle principale de l'algorithme pour approximer le vecteur propre
    do
    {
        copierMatrice(*X2,X);
        produitMatrices(*A,*X,X2);

        diviseComposante(X2);


      } while(!(compare(X,X2, precision)));


    //une fois que c'est fait on copie X2 dans X, pour avoir la bonne précision et non l'itération qui la précède
    copierMatrice(*X2, X);


    //on oubli pas de liberer la mémoire
    libererMatrice(X2);

}


/**
 * \fn void diviseComposante(Matrice *V)
 * \brief Fonction pour diviser toutes les composantes d'un vecteur colonne par le dernier
 *
 * \param Matrice *V matrice dont on veut calculer les valeurs propres
 */
void diviseComposante(Matrice *V)
{
    int i =0;

    //on divise toutes les composantes tant qu'on est pas à la derniere
    for(i =0; i < V->hauteur; i++)
    {
        V->matrice[0][i] = V->matrice[0][i] / V->matrice[0][V->hauteur-1];
    }

}



/**
 * \fn double quotientRayleigh(Matrice *A, Matrice *V)
 * \brief Fonction pour calculer les valeurs propres par la methode des puissances
 *
 * \param Matrice *A matrice pour dont on a calculé le vecteur de valeur propre
 * \param Matrice *V le vecteur des valeurs propres
 * \return retourne un double qui est la plus grande valeur propre de la matrice
 */
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
