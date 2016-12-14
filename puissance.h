#ifndef PUISSANCE
#define PUISSANCE

#include "matrice.h"
#include "math.h"

void methodepuissance(Matrice *A, Matrice *X, double precision);
void diviseComposante(Matrice *V);
double quotientRayleigh(Matrice *A, Matrice *V);




int compare(Matrice *A, Matrice *B, double precision);




#endif //PUISSANCE
