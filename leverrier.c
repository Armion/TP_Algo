/**
 * \file leverrier.c
 * \brief contient les fonctions de leverrier et leverrier amelioré
 * \author Palisson Corentin
 * \version 0.9
 * \date 21 Octobre 2016
 *
 */

#include "matrice.h"

/**
 * \fn void Leverrier(Matrice*A)
 * \brief Fonction pour calculer le polynome caracteristique
 *
 * \param Matrice *A matrice dont on veut calculer le polynome caracterique
 */
void Leverrier(Matrice*A)
{
    Matrice B;
    creerMatrice(&B,A->hauteur,A->largeur);
    int tab[2][A->hauteur+1];//On créer un tableau à deux dimensions, une pour mettre les traces des puissances de A
    // Une autre pour les coefficients.

    int i;
    int k;
    for(i=0;i<A->hauteur+1;i++)
    {
        puissanceMatrice(A, &B, i);//On met A à la puissance i dans B
        tab[1][i] = traceMatrice(&B);//On fait la trace de la matrice A^i et on la met dans le tableau
        if (i==0)
        {
            //Ensuite on met le premier coefficient égal à (-1)^n
            if (A->hauteur % 2 == 0)
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
            //On applique la formule de Leverrier tel que : pa(p) = -(S(p)*a(0)+S(p-1)*a(1)+...+S(1)*a(p-1))

            tab[2][i] = 0;
            for(k=0; k<i; k++)
            {
                //Et ceci en lisant les deux dimensions dans un sens différent...
                tab[2][i] -= tab[2][k]*tab[1][i-k];
            }
            // On trouve a(p) en faisant en divisant par p.
            tab[2][i] = (tab[2][i])/i;
        }
    }
    printf("Le polynome caracteristique de la matrice est : P(X)=  \n");
    //On relie la deuxième dimension pour pouvoir afficher le polynome.
    for(i=0;i<A->hauteur+1;i++)
    {
        if (i == 0 || tab[2][i]<0)
            printf("%d X^%d",tab[2][i],A->hauteur-i);
        else if (tab[2][i]>=0)
            printf(" + %d X^%d",tab[2][i],A->hauteur-i);
    }
    printf("\n \n");

    libererMatrice(&B); // On libère la matrice
}


/**
 * \fn void LeverrierAmelioree(Matrice *A)
 * \brief Fonction pour calculer le polynome caracteristique mais plus rapide que leverrier classique
 *
 * \param Matrice *A matrice dont on veut calculer le polynome caracterique
 */
void LeverrierAmelioree(Matrice *A)
{
    Matrice B;
    Matrice I;
    Matrice C;
    Matrice D;

    int i,p;
    double tab[A->hauteur+1];// On déclare le tableau dans lesquelles se trouveront les coefficients formant le polynome


    creerMatrice(&B,A->hauteur,A->largeur);
    creerMatrice(&I,A->hauteur,A->largeur);
    creerMatrice(&C,A->hauteur,A->largeur);
    initialiserMatrice(&I);
    copierMatrice(*A, &D);

    /* On déclare 4 matrices et on leurs alloue la mémoire
     Dans A, il y aura la matrice A indexée selon le niveau de résolution
     Dans B, il y a la matrice B indexée selon le niveau de résolution définie dans l'algorithme
     Dans C, on met la matrice -a(i)*(-1)^(n+1)*I, elle sert donc de matrice temporaire
     Dans D, on garde la matrice de départ qui sert à la définition de A
    */




    for(i=0; i< A->hauteur ; i++)
    {
        I.matrice[i][i] = 1;//On fait de I la matrice identitée ayant la taille de A
    }

    if (A->hauteur % 2 == 0)//On met (-1)^n en tant que premier coefficient

        {
            tab[0] = 1;
        }
    else
        {
            tab[0] = -1;
        }


    p = tab[0]*(-1); // Ceci correspond à (-1)^(n+1)



    for(i = 1; i <= A->hauteur;i++) //ici on a l'algorithme donné:
    {
            tab[i] = p * traceMatrice(A) / i;
            produitMatriceScalaire(I,tab[i]*p,&C);
            soustractionMatrice(*A,C,&B);
            produitMatrices(D,B,A);


    }



    printf("Le polynome caracteristique de la matrice est : P(X)=  \n"); // On affiche ensuite le polynome.

    for(i=0;i<A->hauteur+1;i++)
    {
        if (i == 0 || tab[i]<0)
            printf("%f X^%d",tab[i],A->hauteur-i);
        else if (tab[i]>=0)
            printf(" + %f X^%d",tab[i],A->hauteur-i);
    }
    printf("\n \n");

    libererMatrice(&B);
    libererMatrice(&C);
    libererMatrice(&D);
    // On libère les matrices
}
