/**
 * \file matrice.h
 * \brief contient les prototypes des fonctions essentielles pour implementer les matrices et la structure Matrice
 * \author Cochard Mathieu
 * \version 1.5
 * \date 21 Octobre 2016
 *
 */



#ifndef MATRICE
#define MATRICE


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


/**< \struct Matrice*/
typedef struct Matrice
{
    int hauteur, largeur;
    double ** matrice;

}Matrice;

//implementation
void creerMatrice(Matrice* m_matrice, int largeur, int hauteur); //fonction qui creer une matrice avec une largeur et hauteur donner et l'initialise à 0
void libererMatrice(Matrice* matrice);  // fonction qui libere le tableau a deux dimension de matrice
void afficherMatrice(const Matrice * const matrice); // fonction pour afficher les matrices, pertinant que pour les petites matrices
int chargerMatrice(Matrice* matrice, char* lien); //fonction qui lit une matrice dans un fichier (lien) renvoie 1 si tout s'est bien passe, -1 si il y a eu un probleme, peut servir pour un test
int sauvegarderMatrice(const Matrice * const matrice, char* lien); // fonction qui sauvegarde une matrice dans un fichier (lien) renvoie 1 si tout s'est bien passe -1 si il y a eu un probleme, peut servir pour un test
void initialiserMatrice(Matrice* matrice); //fonction qui met tous les indices de la matrice a 0
void definirMatrice(Matrice* matrice); //fonction pas tres utile qui permet de creer une matrice sur la console, plus pratique de passer par une sauvegarde
void fillMatrice(Matrice* matrice, double nombre); // fonction qui remplie une matrice avec un meme nombre
void getElem(Matrice *A, int colonne, int ligne, double *element);


//calculs
int produitMatrices(Matrice m1, Matrice m2, Matrice* resultat); // fonction qui permet de faire le produit de deux matrices m1 et m2 et le stock dans la matrice resultat
int puissanceMatrice(Matrice *A, Matrice *B, int puissance); // B devient A^puissance
void produitMatriceScalaire(Matrice m1, double scalaire, Matrice* resultat); // fonction qui permet de multiplier une matrice par un scalaire et le stock dans la matrice resultat
int additionMatrice(const Matrice * const  m1, const Matrice * const m2, Matrice* resultat); // fonction qui permet d'additionner deux matrices et le stock dans la matrice resultat renvoit 1 si tout s'est bien passé sinon -1
int soustractionMatrice(Matrice m1, Matrice m2, Matrice* resultat); // fpnction qui calcule la soustraction d'une matrice par une autre et le stock dans la matrice resultat
Matrice transposeMatrice(Matrice m1); // fonction qui retourne la transposé d'une matrice
void copierMatrice(const Matrice origine, Matrice* copie); // fonction qui copie une matrice origine dans la matrice resultat
double normeVecteur(Matrice V); //calcule la norme d'un vecteur
double traceMatrice(Matrice*A);



#endif // MATRICE
