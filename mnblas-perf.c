/* Tests unitaires pour MNBLAS */
/* DE ARAUJO Bastien, SURIER GAROFALO Aurélien <aurelien.surier@gmail.com> */

#include <stdio.h>
#include "mncommon.h"
#include "vars.h"
#include <x86intrin.h>
#define N 4
#define VECSIZE    1000
#PROC_CORE_NUMBER 2
#PROC_FREQ 2200000000

enum Type {s, d, c, z};
enum Type t;

int main(){
  printf("=== MNBLAS : PERFORMANCES ===\n");
  int writeFile = 1;
  FILE *fp;
  fp = fopen("mnblasperf", "w+");
  if(fp == NULL){
    printf("[ERROR] Unable to open file to write...\n");
    writeFile = 0;
  }

    unsigned long long start, end, mnblasValue, cblasValue;
    unsigned long long residu ;
    double mnblasDebit, cblasDebit;

    /********* Génération de vecteurs et matrices *********/

    vdouble v1, v2, v3, v4;
    vector_init_perf(v1, 1.0);

    mdouble m1, m2, m3;
    matrix_init_perf(m1, 1.0);


    /********* calcul du résidu *********/
    start = _rdtsc () ;
    end = _rdtsc () ;
    residu = end - start ;


    /********* Perf de BLAS1 *********/
    start = _rdtsc () ;
        cblas_dcopy (VECSIZE, vec1, 1, vec2, 1) ;
    end = _rdtsc () ;
    printf ("Nombre de cycles cblas pour scopy: %Ld \n", end-start-residu)
    printf("Débit : ", debit);
    cblasValue = end-start-residu;

    start = _rdtsc () ;
        mnblas_dcopy (VECSIZE, vec1, 1, vec2, 1) ;
    end = _rdtsc () ;
    mnblasValue = end - start - residu;

    printf ("Nombre de cycles mnblas pour scopy: %Ld \n", end-start-residu)
    printd("Débit : ", cBlas)
    printf ("===== Diff =====\n");
    printf ("Diff : %Ld (c) contre %Ld (mn) \n", cblasValue, mnblasValue);
    printf '
}

void vector_init_perf (VDOUBLE V, float x)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    V [i] = x ;

  return ;
}

void matrix_init_perf(VDOUBLE V, float x){
}

double compute_flops(unsigned long long c){

}
