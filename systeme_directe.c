/**
 * \file systeme_directe.c
 * \brief contient les  fonctions de resolution directe de systemes
 * \author Cochard Mathieu
 * \version 1.5
 * \date 21 Octobre 2016
 *
 */


#include "systeme_directe.h"


/**
 * \fn int gauss(const Matrice*  const A, const Matrice* const B, Matrice* X)
 * \brief Fonction pour resoudre un systeme AX = B avec la methode de gauss
 *
 * \param A pointeur constant vers la matrice A, on utilise un pointeur pour optimiser la memoire
 * \param B pointeur constant vers la matrice B, on utilise un pointeur pour optimiser la memoire
 * \param X pointeur vers la matrice X qui contiendra le resultat du systeme d'equation
 * \return renvoie -1 si on trouve un pivot nul sinon 1
 */

int gauss(const Matrice*  const A, const Matrice* const B, Matrice* X)
{

    int i = 0, j = 0, k = 0;
    double pivot = 0;
    Matrice a, b;

    //vu qu'on utilise des constantes on doit recreer des matrices, mais au moin ca evite de modifier les matrices de l'utilisateur
    copierMatrice(*A, &a);
    copierMatrice(*B, &b);



    for(i = 0; i < a.hauteur ; i++)
    {

        for(j = i + 1 ; j < a.hauteur ; j++)
        {
            //on verifi qu'il n'y aura pas de division par 0
            if (a.matrice[i][i] == 0)
            {
                printf("erreure, pivot nul impossible de poursuivre gauss !");
                afficherMatrice(A);

                return - 1;
            }

            //on calcule le pivot pour la ligne j
            pivot = a.matrice[i][j] / a.matrice[i][i];

            for(k = 0; k < a.largeur ; k++)
            {
                //on fait l'elimination de gauss sur la ligne j en la parcourant avec k

                a.matrice[k][j] = a.matrice[k][j] - pivot * a.matrice[k][i];
            }

            //on oubli pas la matrice b
            b.matrice[0][j] = b.matrice[0][j] - pivot * b.matrice[0][i];

        }
    }

    // il n'y a plus qu'a resoudre ce systeme facile
    remonter(&a, &b, X);

         return 1;

         libererMatrice(&a);
         libererMatrice(&b);



}


/**
 * \fn int cholesky (const Matrice* const A, const Matrice* const B, Matrice* R)
 * \brief Fonction pour resoudre un systeme AX = B avec la methode de gauss
 *
 * \param A pointeur constant vers la matrice A, on utilise un pointeur pour optimiser la memoire
 * \param B pointeur constant vers la matrice B, on utilise un pointeur pour optimiser la memoire
 * \param X pointeur vers la matrice X qui contiendra le resultat du systeme d'equation
 * \return renvoie -1 si la matrice n'est pas definie positive sinon 1
 */

int cholesky (const Matrice* const A, const Matrice* const B, Matrice* R)
{
    float s =0;
    int i = 0, j =0, k =0 ;
    Matrice Y, RT, b;


    creerMatrice(R, A->largeur, A->hauteur);
    copierMatrice(*B, &b);

    //on applique l'algo de cholesky
    for( i = 0; i < R->hauteur; i++)
    {
        s = A->matrice[i][i];

        for(j = 0; j <= i -1 ; j++)
        {
            s -= pow(R->matrice[i][j], 2);
        }

        if( s < 0)
        {
            printf("erreure la matrice n'est pas définie positive !");
            return  -1;

        }

        R->matrice[i][i] = sqrt(s);
        for( j = i +1; j < R->largeur; j++)
        {
            R->matrice[j][i] = A->matrice[j][i];

                for(k = 0; k <=  i - 1 ; k++)
                {
                    R->matrice[j][i] -= R->matrice[i][k] * R->matrice[j][k];
                }
                R->matrice[j][i] /= R->matrice[i][i];

        }


    }

    //apres avoir R on résoud les systemes

        RT = transposeMatrice(*R);
        descendre(&RT, &b, &Y);
        remonter(R, &Y, &RT);
        copierMatrice(RT, R);

        libererMatrice(&b);

        return 1;
}


/**
 * \fn remonter(Matrice* A, Matrice* B, Matrice* X)
 * \brief Fonction pour resoudre un systeme AX = B avec A matrice echelonnee, logiquement l'utilisateur ne s'en sert pas
 *
 * \param A pointeur  vers la matrice A, on utilise un pointeur puisque cette fonction est cense etre utilisee avec des variables locales aux fonctions de resolution directe
 * \param B pointeur  vers la matrice B, on utilise un pointeur puisque cette fonction est cense etre utilisee avec des variables locales aux fonctions de resolution directe
 * \param X pointeur vers la matrice X qui contiendra le resultat du systeme d'equation
 */

void remonter(Matrice* A, Matrice* B, Matrice* X)
{
    int i = 0, j = 0;

    creerMatrice(X, 1, A->hauteur);


    for(i = A->hauteur - 1; i >= 0; i--)
    {
        for(j = A->largeur  - 1; j > i ; j--)
        {
            B->matrice[0][i] -= A->matrice[j][i] * X->matrice[0][j];
        }
        if (A->matrice[j][i] != 0)
        {
            X->matrice[0][i] = B->matrice[0][i] / A->matrice[j][i];
        }
    }
}

/**
 * \fn remonter(Matrice* A, Matrice* B, Matrice* X)
 * \brief Fonction pour resoudre un systeme AX = B avec A matrice echelonnee, logiquement l'utilisateur ne s'en sert pas
 *
 * \param A pointeur  vers la matrice A, on utilise un pointeur puisque cette fonction est cense etre utilisee avec des variables locales aux fonctions de resolution directe
 * \param B pointeur  vers la matrice B, on utilise un pointeur puisque cette fonction est cense etre utilisee avec des variables locales aux fonctions de resolution directe
 * \param X pointeur vers la matrice X qui contiendra le resultat du systeme d'equation
 */

void descendre(Matrice* A, Matrice* B, Matrice* X)
{
    int i = 0, j = 0;

    creerMatrice(X, 1, A->hauteur);


    for(i = 0; i < A->hauteur; i++)
    {
        for(j = 0; j < i; j++)
        {
            B->matrice[0][i] -= A->matrice[j][i] * X->matrice[0][j];
        }
        if (A->matrice[i][i] != 0)
        {
            X->matrice[0][i] = B->matrice[0][i] / A->matrice[i][i];
        }
    }
}
