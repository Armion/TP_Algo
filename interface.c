/**
 * \file interface.c
 * \brief fonction pour avoir une interface
 * \version 0.9
 * \date 16 décembre 2016
 *
 */
#include "interface.h"



/**
 * \fn void principal()
 * \brief interface console, il permet de choisir les calcules à effectuer sur une matrice
 *
 */
void principal()
{

    char fichier[50];
    int choix = 0;
    Matrice A, X;
    double precision;


    //boucle principale
    while(choix != -1)
    {
        //on enumere les choix
        printf(" \n \n*************************************************");
        printf(" \n menu principal : \n \n");
        printf(" pour calculer le vecteur propre tappez 1 \n ");
        printf(" pour obtenir la plus grande valeur propre tappez 2 \n ");
        printf(" pour calculer le vecteur caracteristique avec leverrier tappez 3 \n ");
        printf(" pour calculer le vecteur caracteristique avec leverrier ameliore tappez 4 \n ");
        printf(" pour quitter -1 \n ");

        scanf("%d", &choix);
        //si l'utilisateur n'a pas mit n'importe quoi on charge la matrice et effectu l'operation demandé
        if(choix != -1 && choix >0 && choix < 6)
        {
            printf(" \n veuillez entrer le chemin relatif vers le fichier de la matrice \n");
            scanf("%s", fichier);
        //on verifi qu'on a bien chargé la matrice
            if(chargerMatrice(&A, fichier) == 1)
            {
                switch (choix)
                {
                case 1:

                    printf("veuillez entrer la precision \n");
                    scanf("%lf", &precision);

                    methodepuissance(&A, &X, precision);
                    afficherMatrice(&X);
                break;

                case 2:

                    printf("veuillez entrer la precision \n");
                    scanf("%lf", &precision);
                    methodepuissance(&A, &X, precision);
                    printf("%f \n",quotientRayleigh(&A, &X));
                break;

                case 3:

                Leverrier(&A);
                break;

                case 4:
                    LeverrierAmelioree(&A);
                break;
                }
            }


        }




    }



    libererMatrice(&A); //si on quitte le programme sans avoir fait la moindre operation ça fait une erreure de segmentation car on a pas allouer la matrice

}
