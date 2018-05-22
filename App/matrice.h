#ifndef MATRICE_H
#define MATRICE_H

#include "def.h"

void import_matrice(FILE *web, Matrice *M);

void free_matrice(Matrice *M);

void affiche(Matrice *M);

double sigma(Matrice *M, double *piK);

void init_distrib(int n, double *a, double *b);

void init_distrib_aitken(int n, double *a, double *b, double *c);

void calcul_f(double *f, Matrice *M);

double calcul_sigma(Matrice *M, double *piK);

#endif
