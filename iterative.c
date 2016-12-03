/**
 * \file iterative.c
 * \brief contient les  fonctions de resolution iterative de systeme
 * \author Cochard Mathieu
 * \version 1.5
 * \date 21 Octobre 2016
 *
 */


#include "iterative.h"

/**
 * \fn int jacobi(const Matrice * const A, const Matrice * const B, Matrice* X, double precision, int iterationMax)
 * \brief Fonction pour resoudre un systeme lineaire du type AX = B avec la methode de jacobi
 *
 * \param A matrice A, constante ne sera pas modifie mais passe par argument pour eviter la copie et de la prise de memoire sur les grosses matrices
 * \param A matrice B, constante ne sera pas modifie mais passe par argument pour eviter la copie et de la prise de memoire sur les grosses matrices
 * \param X matrice X, pointeur sur la matrice X qui contiendra le resultat
 * \param precision nombre flotant, norme maximum du pointeur e; precision desiree pour le resultat
 * \param iterationMax nombre entier, le nombre maximum d'iteration a effectuer avant d'abondonner la recherche meme si la precision n'est pas atteinte
 * \return on renvoit un entier qui est le nombre d'iterations qu'il a fallut pour trouver la solution
 */

int jacobi(const Matrice * const A, const Matrice * const B, Matrice* X, double precision, int iterationMax)
{
    double e = precision;  // on prend qui contiendra la norme du vecteur et l'initialise avec la valeur de precision pour etre sur d'executer while une fois
    int i =0, j = 0, iteration = 0; // i et j pour parcourir les boucle tandis que iteration sert a compter le nombre d'iteration et sera retourne
    Matrice Xn, V1, V2; // des matrices locales qui servent a effectuer les calcules une fois la matrice R trouve, on aurait pu s'en passer en acceptant de modifier A et B

    creerMatrice(X, 1, B->hauteur); // si jamais X n'etait pas bien formate ou declaree on le fait


    copierMatrice(*X, &Xn);  // on creer Xn (appelle de la fonction creer Matrice dans copier Matrice)



    // on applique l'algo de de Jacobi
    while(e >= precision && iterationMax > 0)
    {
        for(i = 0; i< Xn.hauteur; i++)
        {
            Xn.matrice[0][i] = B->matrice[0][i];
            for(j = 0 ; j < Xn.hauteur ; j++)
            {
                if(j != i)
                {
                    Xn.matrice[0][i] -= A->matrice[j][i] * X->matrice[0][j];
                }
            }
            Xn.matrice[0][i] /= A->matrice[i][i];

        }

        // et puis on resoud le systeme une fois qu'on l'a decompose
        copierMatrice(Xn, X);

        produitMatrices(*A, *X, &V1);
        soustractionMatrice(V1, *B, &V2);

        e = normeVecteur(V2);

        iterationMax --;
        iteration ++;
    }

    //on libere les matrices locales
    libererMatrice(&Xn);
    libererMatrice(&V1);
    libererMatrice(&V2);

    //on renvoit finallement les iterations necessaires
     return iteration ;

}

/**
 * \fn int surrelaxion(const Matrice * const A, const Matrice * const B, Matrice* X, double precision, int iterationMax, float o)
 * \brief Fonction pour resoudre un systeme lineaire du type AX = B avec la methode de surrelaxion (ou gauss seidel pour o = 1 :p )
 *
 * \param A matrice A, constante ne sera pas modifie mais passe par argument pour eviter la copie et de la prise de memoire sur les grosses matrices
 * \param A matrice B, constante ne sera pas modifie mais passe par argument pour eviter la copie et de la prise de memoire sur les grosses matrices
 * \param X matrice X, pointeur sur la matrice X qui contiendra le resultat
 * \param precision nombre flotant, norme maximum du pointeur e; precision desiree pour le resultat
 * \param iterationMax nombre entier, le nombre maximum d'iteration a effectuer avant d'abondonner la recherche meme si la precision n'est pas atteinte
 * \param o nombre flottant, le parametre omega pour l'algorithm il est possible de mettre 1 pour faire du gauss seidel
 * \return on renvoit un entier qui est le nombre d'iterations qu'il a fallut pour trouver la solution
 */

int surrelaxion(const Matrice * const A, const Matrice * const B, Matrice* X, double precision, int iterationMax, float o)
{
    double e = precision;  // on prend qui contiendra la norme du vecteur et l'initialise avec la valeur de precision pour etre sur d'executer while une fois
    int i =0, j = 0, iteration = 0; // i et j pour parcourir les boucle tandis que iteration sert a compter le nombre d'iteration et sera retourne
    Matrice Xn, V1, V2;  // des matrices locales qui servent a effectuer les calcules une fois la matrice R trouve, on aurait pu s'en passer en acceptant de modifier A et B

    creerMatrice(X, 1, B->hauteur); // si jamais X n'etait pas bien formate ou declaree on le fait


    copierMatrice(*X, &Xn); // on creer Xn (appelle de la fonction creer Matrice dans copier Matrice)


    // on applique l'algo de la surrelaxion
    while(e >= precision && iterationMax > 0)
    {
        for(i = 0; i< Xn.hauteur; i++)
        {
            Xn.matrice[0][i] = B->matrice[0][i];
            for(j = 0 ; j < Xn.hauteur ; j++)
            {
                if(j < i)
                {
                    Xn.matrice[0][i] -= A->matrice[j][i] * Xn.matrice[0][j];
                }
                else if (j > i)
                {
                    Xn.matrice[0][i] -= A->matrice[j][i] * X->matrice[0][j];
                }
            }
            Xn.matrice[0][i] = Xn.matrice[0][i] * (o / A->matrice[i][i]) + (1 - o) * X->matrice[0][i];


        }


        //une fois qu'on a fini avec la surrelaxion on finit quand meme par resoudre le systeme c'est mieux :p
        produitMatrices(*A, *X, &V1);
        soustractionMatrice(V1, *B, &V2);

        e = normeVecteur(V2);
        copierMatrice(Xn, X);

        iterationMax --;
        iteration ++;
    }

    // on oubli pas de liberer les matrices locales
    libererMatrice(&Xn);
    libererMatrice(&V1);
    libererMatrice(&V2);

    return iteration;

}



