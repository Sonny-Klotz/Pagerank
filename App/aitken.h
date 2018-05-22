#ifndef AITKEN_H
#define AITKEN_H

#include "def.h"
#include "matrice.h"

/**
 * Retourne le nombre d'itérations dans le calcul de la distribution
 * */
int aitken(Matrice *M, double *piK, double *piKmoins1, double *piKmoins2);

#endif
