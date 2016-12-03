/**
 * \file echantillon.c
 * \brief contient les fonctions de creation des matrices de test
 * \author Cochard Mathieu
 * \version 1.5
 * \date 21 octobre 2016
 *
 */


#include "echantillon.h"


/**
 * \fn void creerMatriceBordCarre(Matrice* matrice, int n)
 * \brief Fonction pour creer la matrice de test Bord Carre
 *
 * \param matrice necessite un pointeur sur une matrice pour stocker la matrice generee
 * \param n la taille de la matrice (note il s'agit d'une matrice carre n*n)
 */

 //pas grand chose a dire on applique l'algorithm donne
void creerMatriceBordCarre(Matrice* matrice, int n)
{
    int i =0, j = 0;
    creerMatrice(matrice, n, n);


    for(i = 0; i < n ; i++)
    {
        for( j = 0; j < n ; j++)
        {
            if( i == j)
            {
                matrice->matrice[i][j] = 1;
            }
            else if( i == 0)
            {
                matrice->matrice[j][0] = matrice->matrice[0][j] = pow(2, 1 -(j+1));
            }

        }
    }


}

/**
 * \fn void creerMatriceDingDong(Matrice * matrice, int n)
 * \brief Fonction pour creer la matrice de test Ding Dong
 *
 * \param matrice necessite un pointeur sur une matrice pour stocker la matrice generee
 * \param n la taille de la matrice (note il s'agit d'une matrice carre n*n)
 */

 // la meme chose ici
void creerMatriceDingDong(Matrice * matrice, int n)
{
    int i = 0, j = 0;

    creerMatrice(matrice, n, n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            matrice->matrice[j][i] = 1.0 / (double)(2*(n - (i+1) - (j + 1) + 1.5));
        }

    }


}


/**
 * \fn void creerMatriceCreuse(Matrice* matrice, int n)
 * \brief Fonction pour creer la matrice de test creuse, (note j'imagine qu'il y a une facon de le faire sans appelle recursif avec des probas ou des states mais je n'ai pas le temps de chercher)
 *
 * \param matrice necessite un pointeur sur une matrice pour stocker la matrice generee
 * \param n la taille de la matrice (note il s'agit d'une matrice carre n*n)
 */
void creerMatriceCreuse(Matrice* matrice, int n)
{
    creerMatrice(matrice, n, n);

    int i = 0, j =0, alea =0, compteur = 0;


        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                alea = rand() % 100;
                if(alea <= 70)
                {
                    matrice->matrice[j][i] = 0.0;
                    compteur ++;
                }
                else
                {
                    alea = rand() % 100;
                    matrice->matrice[j][i] = (double)alea;
                }
            }
        }
        printf(" ** %d ** \n", compteur);

        if(compteur *100 / (n* n) < 70)
        {
            creerMatriceCreuse(matrice, n);
        }

}


/**
 * \fn void creerMatriceFranc(Matrice* matrice, int n)
 * \brief Fonction pour creer la matrice de test de Franc
 *
 * \param matrice necessite un pointeur sur une matrice pour stocker la matrice generee
 * \param n la taille de la matrice (note il s'agit d'une matrice carre n*n)
 */

void creerMatriceFranc(Matrice* matrice, int n)
{
    int i = 0, j = 0;

    creerMatrice(matrice, n, n);

    for(i = 0; i < n; i ++)
    {
        for(j =0 ; j < n ; j++)
        {
            if( i >= j + 2)
            {
                matrice->matrice[j][i] = (double)0;
            }
            else if (i < j)
            {
                matrice->matrice[j][i] = (double)i+1;

            }
            else
            {
                matrice->matrice[j][i] = (double)j + 1;
            }
        }
    }
}


/**
 * \fn int creerMatriceKMS(Matrice* matrice, int n, float p)
 * \brief Fonction pour creer la matrice de test KMS
 *
 * \param matrice necessite un pointeur sur une matrice pour stocker la matrice generee
 * \param n la taille de la matrice (note il s'agit d'une matrice carre n*n)
 * \param p le parametre p entre 0 et 1
 */
int creerMatriceKMS(Matrice* matrice, int n, float p)
{
    int i = 0, j = 0 ;
    creerMatrice(matrice, n, n);


        if (p > 0 && p < 1)
        {
            for( i = 0; i < n ; i++)
            {
                for( j = 0 ; j < n ; j++)
                {
                    matrice->matrice[j][i] = (double)pow(2, (i+1) - (j +1));
                }
            }

            return 1;

        }
        else
        {
            return -1;
        }


}

/**
 * \fn void creerMatriceHilbert(Matrice* matrice, int n)
 * \brief Fonction pour creer la matrice de test d'Hilbert
 *
 * \param matrice necessite un pointeur sur une matrice pour stocker la matrice generee
 * \param n la taille de la matrice (note il s'agit d'une matrice carre n*n)
 */

void creerMatriceHilbert(Matrice* matrice, int n)
{
    int i = 0, j = 0;

    creerMatrice(matrice, n, n);

    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n ; j++)
        {
            matrice->matrice[j][i] = 1.0/(double)(i+j+1);
        }
    }

}

/**
 * \fn creerMatriceLehmer(Matrice* matrice, int n)
 * \brief Fonction pour creer la matrice de test de Lehmer
 *
 * \param matrice necessite un pointeur sur une matrice pour stocker la matrice generee
 * \param n la taille de la matrice (note il s'agit d'une matrice carre n*n)
 */
void creerMatriceLehmer(Matrice* matrice, int n)
{
    int i = 0, j = 0;
    creerMatrice(matrice, n, n);

    for(i = 0; i < n; i++)
    {
        for( j = 0; j < n ; j++)
        {
            if(i < j)
            {
                matrice->matrice[j][i] = (double)(i + 1 )/(double)( j + 1) ;
            }
            else
            {
                matrice->matrice[j][i] = (double)(j + 1 )/(double)( i + 1) ;
            }

        }
    }

}

/**
 * \fn void creerMatriceLotkin(Matrice* matrice, int n)
 * \brief Fonction pour creer la matrice de test de Lotkin
 *
 * \param matrice necessite un pointeur sur une matrice pour stocker la matrice generee
 * \param n la taille de la matrice (note il s'agit d'une matrice carre n*n)
 */
void creerMatriceLotkin(Matrice* matrice, int n)
{

    int i = 0, j = 0 ;
    creerMatrice(matrice, n, n);


    for( i = 0; i < n ; i ++)
    {

        for(j = 0 ; j < n ; j++)
        {

            if(i == 0)
            {
                matrice->matrice[j][i] = 1;
            }
            else
            {
                matrice->matrice[j][i] = 1.0/(double)(i + j +1);
            }

        }
    }


}

/**
 * \fn void creerMatriceMoler(Matrice* matrice, int n)
 * \brief Fonction pour creer la matrice de test de Lotkin
 *
 * \param matrice necessite un pointeur sur une matrice pour stocker la matrice generee
 * \param n la taille de la matrice (note il s'agit d'une matrice carre n*n)
 */
void creerMatriceMoler(Matrice* matrice, int n)
{
    int i = 0, j = 0;

    creerMatrice(matrice, n, n);

    for(i = 0; i < n; i ++)
    {
        for( j = 0; j < n ; j++)
        {
            if( i == j)
            {
                matrice->matrice[j][i] = (double)(i +1) ;
            }
            else if (i < j)
            {
                matrice->matrice[j][i] = (double)(i - 1) ;

            }
            else
            {
                matrice->matrice[j][i] = (double)(j - 1);
            }
        }
    }

}
