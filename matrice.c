/**
 * \file matrice.c
 * \brief contient les  fonctions de base pour implementer les matrices
 * \version 1.5
 * \date 21 Octobre 2016
 *
 */


#include "matrice.h"


/**
 * \fn void creerMatrice(Matrice* m_matrice, int largeur, int hauteur)
 * \brief Fonction pour creer une matrice et l'initialiser a 0
 *
 * \param m_matrice matrice qui va etre formate avec la bonne taille et remplie de 0
 * \param largeur entier qui represente le nombre de colonnes de la matrice
 * \param hauteur entier qui represente le nombre de lignes de la matrices
 */

void creerMatrice(Matrice* m_matrice, int largeur, int hauteur)
{

    int i = 0;

    //on commence par etablir la largeur et la hauteur de la matrice
    m_matrice->largeur = largeur;
    m_matrice->hauteur = hauteur;


    // on alloue dynamiquement le tableau de tableaux de double, au debut je prenais des float, mais avec les pc de nos jours on peut se permettre des doubles pour une bonne precision, des longs double aurait peut'etre ete trop
    m_matrice->matrice = malloc(largeur * sizeof(double*));

    // boucle pour allouer les tableaux
    for( i = 0; i < largeur; i ++)
    {
       m_matrice->matrice[i] = malloc(hauteur * sizeof(double));

    }



   /*  /!\ attention, la colonne est donné en premier pas la ligne ! de meme que l'ont commence à l'indice 0. par exemple matrice.matrice[2][4] correspond à l'indice [5][3] de la matrice ! /!\

    on initialise la matrice à 0 pour eviter les mauvaises surprises*/
    initialiserMatrice(m_matrice);

}

/**
 * \fn void libererMatrice(Matrice* matrice)
 * \brief Fonction qui desalou les tableaux qui ont etes alloues dynamiquement d'une matrice
 *
 * \param matrice la matrice a liberer

 */

void libererMatrice(Matrice* matrice)
{
    int i = 0;

    // on commence par liberer les tableaux du tableau
    for( i =0; i < matrice->largeur; i++)
    {
        free(matrice->matrice[i]);
    }

    //on libere finallement le tableau vide
    free(matrice->matrice);


}


/**
 * \fn int chargerMatrice(Matrice* matrice, char* lien)
 * \brief fonction qui permet de charger une matrice a partir d'un fichier
 *
 * \param matrice pointeur sur matrice, qui est la matrice ou sera stocke la matrice chargee
 * \param lien est un tableau de char, une chaine de caractere qui contient le lien vers le fichier matrice a charger, peut'etre dans un sous dossier par exemple matrices/A pour la matrice A du dossier matrices
 * \return renvoit un entier  qui peut'etre traite : 1 signifi que le chargement s'est bien passe, -1 qu'on a pas pu ouvrir le fichier
 */

// matrice est la matrice dans la quelle sera mis en mémoire la matrice chargé, et lien le chemin vers la matrice
int chargerMatrice(Matrice* matrice, char* lien)
{
    //declaration du flux pour lire le fichier
    FILE* fichier = NULL;
    int hauteur = 0, largeur = 0, i = 0, j = 0;

        //on ouvre le dossier du nom lien avec r, pour pouvoir juste le lire
       fichier = fopen(lien, "r");

       //si l'ouverture a reussie on peut travailler
    if( fichier  != NULL)
    {
        //petit message pour prévenir
       printf("matrice %s ouverte \n \n", lien);

       //on lit la largeur et la hauteur de la matrice qui constituent la premiere ligne du fichier
        fscanf(fichier,"%d %d", &largeur, &hauteur);

        //on appelle alors la fonction creer matrice pour dimenssionner et initialiser notre matrice
        creerMatrice(matrice, largeur, hauteur);

        //boucles imbriqués pour parcourir le fichier mot par mot puis passer à la ligne suivante
    while(j < hauteur)
    {
        i =0;
        while(i < largeur)
        {
            fscanf(fichier, "%lf", &matrice->matrice[i][j]);
            i++;
        }
        j++;
    }

        //on affiche la matrice que l'ont vient de lire ça peut toujours servir pour verifier ou autre mais peut'etre rendre cela facultatif si on travail avec des grosses matrices
        afficherMatrice(matrice);
        // on oublie pas de liberer le flux
        fclose(fichier);

        // on retourne 1 pour dire que tout s'est bien deroule
        return 1;

    }


    else
    {
        //Si le fichier n'a pas pu etre ouvert on envoit un message d'erreure et le code 0 qui peut servir a debug dans la fonction qui l'appelle
        printf(" erreure, impossible de charger la matrice %s \n", lien);
        return -1;
    }

}


/**
 * \fn void afficherMatrice(const Matrice * const matrice)
 * \brief fonction qui permet d'afficher une matrice, le changement de ligne est exprime par ||
 *
 * \param matrice matrice constante qui doit'etre affiche on prend un pointeur pour ne pas recopier la matrice
 */

void afficherMatrice(const Matrice * const matrice)
{
    //si on a quelque chose a afficher
    if(matrice->hauteur != 0 && matrice->largeur != 0)
    {
        //on affiche les caracteristiques de la matrice
        printf(" **matrice de dimension  %d de large par %d de haut** \n", matrice->largeur, matrice->hauteur);
        int i =0, j = 0;

        // on parcourt les tableaux pour afficher la matrice, avec || pour dire qu'on change de ligne si la matrice est trop large pour rentrer sur une seule ligne de console, mais ca devient vite ilisible
        for(i = 0; i < matrice->hauteur ; i++)
        {
            printf("|| ");
            for(j = 0; j < matrice->largeur ; j ++)
            {
                printf("%.4lf | ", matrice->matrice[j][i]);
            }

            printf("\n");
        }
        printf("\n");
    }
    else
    {
        printf("cette matrice est vide !");
    }
}


/**
 * \fn void initialiserMatrice(Matrice* matrice)
 * \brief fonction qui met met 0 dans tout les elements d'une matrice
 *
 * \param matrice pointeur vers la matrice a initialiser
 */

void initialiserMatrice(Matrice* matrice)
{
    int i =0, j = 0;

        //on parcourt simplement les tableaux pour initialiser les coeffitients de la matrice a 0
    for(i = 0; i < matrice->hauteur; i++)
    {

        for(j = 0; j < matrice->largeur; j++)
        {

            matrice->matrice[j][i] = (double)0;
        }
    }
}


/**
 * \fn int additionMatrice(const Matrice * const  m1, const Matrice * const m2, Matrice* resultat)
 * \brief fonction qui calcule la somme de deux matrices
 *
 * \param m1 pointeur sur la matrice du terme gauche
 * \param m2 pointeur sur la matrice du terme droit
 * \param resultat pointeur sur la matrice a retourner
 * \return renvoit un entier egal a -1 si les matrices n'ont pas la meme dimension sinon 1
 */

int additionMatrice(const Matrice * const  m1, const Matrice * const m2, Matrice* resultat)
{
    //on verifi que les matrices ont la meme dimensions
    if ( m1->hauteur != m2->hauteur || m1->largeur != m2->largeur)
    {
        //sinon on retourne 0 pour dire qu'il y a eu un probleme
        printf("erreure, ces matrices ne peuvent pas etre additionnees !");
        return -1;
    }
    //si c'est bon on commence par allouer la matrice resultat
    creerMatrice(resultat, m1->largeur, m1->hauteur);

    //enfin on se contente de parcourir la matrice resultat en mettant la somme des deux autres matrices dans celle-ci
    int i =0, j = 0;
    for( i = 0; i < m1->hauteur; i++)
    {
        for(j = 0; j < m1->largeur ; j++)
        {
            resultat->matrice[j][i] = m1->matrice[j][i] + m2->matrice[j][i];
        }
    }

        //et on renvoit 1 si tout s'est bien passe
    return 1;


}


/**
 * \fn void definirMatrice(Matrice* matrice)
 * \brief fonction qui met met 0 dans tout les elements d'une matrice
 *
 * \param matrice la matrice qui contiendra la matrice genere
 */

void definirMatrice(Matrice* matrice)
{
    int largeur =0, hauteur = 0, i =0, j =0;
    double valeur = 0;

    // on commence par demander la largeur et la hauteur de la matrice a l'utilisateur pour pouvoir l'allouer
    printf("veuillez entrer la largeur : ");
    scanf("%d", &largeur);
    printf("veuillez entrer la hauteur: ");
    scanf("%d", &hauteur);
    creerMatrice(matrice, largeur, hauteur);

    //ensuite on demande a l'utilisateur de remplir la matrice ligne par ligne (on peut faire du buffer overflow pour charger plusieurs lignes d'un coups
    printf(" **remplissage de la matrice : \n**");
    printf(" veuillez entrer les lignes indiques avec un espace entre chaque valeur \n");

    for(i =0; i <hauteur; i++)
    {
        printf(" \n remplissage de la ligne %d \n ", i);
        for(j = 0; j < largeur; j++)
        {
            scanf("%lf", &valeur);
            matrice->matrice[j][i] = valeur;
        }
    }



}


/**
 * \fn int sauvegarderMatrice(const Matrice * const matrice, char* lien)
 * \brief fonction qui permet de charger une matrice a partir d'un fichier
 *
 * \param matrice matrice qui sera sauvegardee
 * \param lien est un tableau de char, une chaine de caractere qui contient le lien vers le fichier ou la matrice sera sauvegardee, peut'etre dans un sous dossier par exemple matrices/A pour la matrice A du dossier matrices
 * \return renvoit un entier  qui peut'etre traite : 1 signifi que le chargement s'est bien passe, -1 qu'on a pas pu ouvrir le fichier
 */

int sauvegarderMatrice(const Matrice * const matrice, char* lien)
{
    FILE* fichier = NULL;
    int i =0, j =0;

    //on ouvre le fichier en w+ pour creer celui-ci si il n'existait pas avant
    fichier = fopen(lien, "w+");

    //si on a pu ouvrir le fichier alors on le reecrit
    if (fichier != NULL)
    {
        printf("fichier %s ouvert avec succes ! \n", lien);


        // la premiere lligne contient les caracteristiques de la matrice
        fprintf(fichier, "%d %d \n", matrice->largeur, matrice->hauteur);

        //on utilise des boucles imbriquees pour parcourir la matrice et ecrire les indices de celle-ci
        for(i = 0; i< matrice->hauteur; i++)
        {
            for(j = 0; j < matrice->largeur; j++)
            {
                fprintf(fichier, "%lf ", matrice->matrice[j][i]);
            }
            fprintf(fichier, "\n");
        }

        printf("sauvegarde de la matrice %s terminee \n", lien);


        fclose(fichier);

        return 1;
    }
    else
    {
        //sinon on ecrit un message et on renvoit 0 pour dire qu'on n'a pas pu sauvegarder la matrice
        printf("impossible de sauvegarder la matrice dans %s", lien);

        return -1 ;
    }

}


/**
 * \fn int produitMatrices(Matrice m1, Matrice m2, Matrice* resultat)
 * \brief fonction qui permet de multiplier deux matrices
 *
 * \param m1 matrice gauche a multiplier
 * \param m2 matrice droite a multiplier
 * \param resultat pointeur vers la matrice qui contient le resultat de la multiplication
 * \return renvoit un entier  qui peut'etre traite : 1 si les dimensions permettent la multiplication des matrices, sinon -1
 */
int produitMatrices(Matrice m1, Matrice m2, Matrice* resultat)
{

    if(m1.largeur == m2.hauteur)
    {
        int i = 0, j = 0, k =0;
        creerMatrice(resultat, m2.largeur, m1.hauteur);

    // pour chaque element ij de la matrice resultat on met la somme du produit des elements A[i]*B[j]
        for(i = 0; i < m1.hauteur; i++)
        {
            for(j = 0; j < m2.largeur; j++)
            {
                for(k = 0; k < m2.hauteur; k++)
                {
                   resultat->matrice[j][i] += m1.matrice[k][i] * m2.matrice[j][k];
                }
            }
        }
    }
    else
    {
     printf("impossible de multiplier ces matrices !");
     return -1;
    }

    return 1;

}


/**
 * \fn void produitMatriceScalaire(Matrice m1, double scalaire, Matrice* resultat)
 * \brief fonction qui permet de multiplier une matrice par un scalaire
 *
 * \param m1 matrice gauche a multiplier
 * \param scalaire nombre flottant qui multipli la matrice
 * \param resultat pointeur vers la matrice qui contient le resultat de la multiplication
 */

void produitMatriceScalaire(Matrice m1, double scalaire, Matrice* resultat)
{

    int i =0, j = 0;
    creerMatrice(resultat, m1.largeur, m1.hauteur);

        //boucles imbriquees pour multiplier les elements de la matrice avec le scalaire
    for(i =0; i < m1.largeur; i++)
    {
        for(j = 0; j < m1.hauteur; j ++)
        {

            resultat->matrice[i][j] = m1.matrice[i][j] * scalaire;
        }
    }


}

/**
 * \fn Matrice transposeMatrice(Matrice m1)
 * \brief fonction qui permet de multiplier une matrice par un scalaire
 *
 * \param m1 matrice a transposer
 * \return renvoit la transpose de la matrice
 */


Matrice transposeMatrice(Matrice m1)
{
    Matrice transpose;
    int i =0, j =0;

    creerMatrice(&transpose, m1.hauteur, m1.largeur);

    //boucles imbriquees pour mettre les elements ij dans ji
    for(i =0; i < m1.hauteur; i++)
    {
        for(j =0; j < m1.largeur; j++)
        {
            transpose.matrice[i][j] = m1.matrice[j][i];
        }
    }


    return transpose;


}


/**
 * \fn void copierMatrice(const Matrice origine, Matrice* copie)
 * \brief fonction qui permet de multiplier une matrice par un scalaire
 *
 * \param origine matrice qui doit'etre copie
 * \param copie pointeur vers la matrice qui contiendra la copie
 */


void copierMatrice(const Matrice origine, Matrice* copie)
{
    int i = 0, j = 0;

        creerMatrice(copie, origine.largeur, origine.hauteur);

        //boucles imbriquees pour copier la matrice
    for(i = 0 ; i < origine.hauteur ; i++)
    {
        for(j = 0 ; j < origine.largeur ; j++)
        {
            copie->matrice[j][i] = origine.matrice[j][i];
        }
    }
}


/**
 * \fn double normeVecteur(Matrice V)
 * \brief fonction qui permet de multiplier une matrice par un scalaire
 *
 * \param V vecteur dont la norme doit'etre calculee
 * \return renvoit la norme du vecteur, attention -1 est une erreure (on garde en tete qu'une norme est strictement positive)
 */

double normeVecteur(Matrice V)
{
    int i =0;
    double somme = 0 ;

        //si on est dans un vecteur ligne on calcule la somme de la ligne
    if(V.hauteur == 1)
    {
        for(i = 0 ; i < V.largeur; i++)
        {
            somme += V.matrice[i][0];
        }

    }
    // si on est dans un vecteur colonne on calcule la somme de la colonne
    else if (V.largeur == 1)
    {
        for(i = 0 ; i < V.hauteur; i++)
        {
            somme += pow(V.matrice[0][i], 2);
        }

    }
    // sinon on envoie un message d'erreure et retourne -1, il ne s'agit pas d'un vecteur
    else
    {
        printf("erreure il ne s'agit pas d'un vecteur !");
        return -1;
    }

    return sqrt(somme);

}

/**
 * \fn int soustractionMatrice(Matrice m1, Matrice m2, Matrice* resultat)
 * \brief fonction qui calcule la soustraction entre deux matrices
 *
 * \param m1 pointeur sur la matrice du terme gauche
 * \param m2 pointeur sur la matrice du terme droit
 * \param resultat pointeur sur la matrice a retourner
 * \return renvoit un entier egal a -1 si les matrices n'ont pas la meme dimension sinon 1
 */

int soustractionMatrice(Matrice m1, Matrice m2, Matrice* resultat)
{
    //on verifi que les matrices ont la meme dimensions
    if ( m1.hauteur != m2.hauteur || m1.largeur != m2.largeur)
    {
        //sinon on retourne 0 pour dire qu'il y a eu un probleme
        printf("erreure, ces matrices ne peuvent pas etre soustraites !");
        return 0;
    }
    //si c'est bon on commence par allouer la matrice resultat
    creerMatrice(resultat, m1.largeur, m1.hauteur);

    //enfin on se contente de parcourir la matrice resultat en mettant la somme des deux autres matrices dans celle-ci
    int i =0, j = 0;
    for( i = 0; i < m1.hauteur; i++)
    {
        for(j = 0; j < m1.largeur ; j++)
        {
            resultat->matrice[j][i] = m1.matrice[j][i] - m2.matrice[j][i];
        }
    }

        //et on revnoit 1 si tout s'est bien passe
    return 1;

}


/**
 * \fn void fillMatrice(Matrice* matrice, float nombre)
 * \brief fonction met tout les termes d'une matrice egaux au flottant nombre
 *
 * \param matrice pointeur sur la matrice a remplir
 * \param nombre nombre flottant avec le quel remplir la matrice
 */

void fillMatrice(Matrice* matrice, double nombre)
{
    int i = 0, j = 0;

    for (i = 0; i < matrice->largeur; i++)
    {
        for(j = 0; j < matrice->hauteur; j++)
        {
            matrice->matrice[i][j] = nombre;
        }
    }

}


int puissanceMatrice(Matrice *A, Matrice *B, int puissance)
{
    if(puissance > 0)
    {
        int i =1;
        Matrice copie;

        copierMatrice(*A, &copie);
        copierMatrice(*A, B);
        for(i = 1; i < puissance; i++)
        {
            produitMatrices(*B, copie, B);

        }

        return 1;


    }
    else
    {
        return 0;
    }


}
