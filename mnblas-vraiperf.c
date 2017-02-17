/* Tests unitaires pour MNBLAS */
/* DE ARAUJO Bastien, SURIER GAROFALO Aurélien <aurelien.surier@gmail.com> */
#include "mnblas.h"
#include <gsl/gsl_cblas.h>
#include <stdio.h>
#include "mncommon.h"
#include "vars.h"

#include <x86intrin.h>
#define VECSIZE 1024
#define PROC_CORE_NUMBER 2
#define PROC_FREQ 2200000000
#define FLOPperCycle 4
#define incy 1
#define incx 1

void vector_init_perf (vdouble V, double x);
void matrix_init_perf (void *V, double x);

int main(){
    printf("=== MNBLAS : PERFORMANCES ===\n");
    int writeFile = 1;
    FILE *fp;
    fp = fopen("mnblasperf", "w+");
    if(fp == NULL){
        printf("[ERROR] Unable to open file to write...\n");
        writeFile = 0;
    }

    unsigned long long start, end, mnblasValue, cblasValue;
    unsigned long long residu ;
    double mnblasDebit, cblasDebit;

    /********* Génération de vecteurs et matrices *********/

    vdouble v1, v2, v3, v4;
    vector_init_perf(v1, 1.0);
    vector_init_perf(v2, 1.0);
    vector_init_perf(v3, 1.0);
    vector_init_perf(v4, 1.0);

    mdouble m1, m2, m3;
    double *matr1 = &m1[0][0];
    double *matr2 = &m2[0][0];
    double *matr3 = &m3[0][0];

    // matrix_init_perf(m1, 1.0);
    // matrix_init_perf(m2, 1.0);
    // matrix_init_perf(m3, 1.0);


    /********* calcul du résidu *********/
    start = _rdtsc () ;
    end = _rdtsc () ;
    residu = end - start ;


    /********* Perf de BLAS1 *********/
    printf("---- copy ----\n");
    start = _rdtsc () ;
        cblas_dcopy (VECSIZE, v1, 1, v2, 1) ;
    end = _rdtsc () ;
    printf ("Nombre de cycles cblas pour dcopy: %Ld \n", end-start-residu);
    // cblasDebit = (((VECSIZE*sizeof(double))/((end-start-residu)/1000000000))/(1/1000000000));
    printf("Débit : %Ld \n", cblasDebit);
    cblasValue = end-start-residu;

    start = _rdtsc () ;
        mncblas_dcopy (VECSIZE, v1, 1, v2, 1) ;
    end = _rdtsc () ;
    mnblasValue = end - start - residu;
    // mnblasDebit = (((VECSIZE*sizeof(double))/((end-start-residu)/1000000000))/(1/1000000000));

    printf ("Nombre de cycles mnblas pour dcopy: %Ld \n", end-start-residu);
    printf("Débit : %Ld \n", mnblasDebit);
    printf ("===== Diff =====\n");
    printf ("Diff : %Ld (c) contre %Ld (mn) \n", cblasValue, mnblasValue);


    printf("---- swap ----\n");
    start = _rdtsc () ;
        cblas_dswap(VECSIZE, v1, 1, v2, 1) ;
    end = _rdtsc () ;
    printf ("Nombre de cycles cblas pour dswap: %Ld \n", end-start-residu);
    // cblasDebit = (((VECSIZE*sizeof(double))/((end-start-residu)/1000000000))/(1/1000000000));
    printf("Débit : %Ld \n", cblasDebit);
    cblasValue = end-start-residu;

    start = _rdtsc () ;
        mncblas_dswap (VECSIZE, v1, 1, v2, 1) ;
    end = _rdtsc () ;
    mnblasValue = end - start - residu;
    // mnblasDebit = (((VECSIZE*sizeof(double))/((end-start-residu)/1000000000))/(1/1000000000));

    printf ("Nombre de cycles mnblas pour dswap: %Ld \n", end-start-residu);
    printf("Débit : %Ld \n", mnblasDebit);
    printf ("===== Diff =====\n");
    printf ("Diff : %Ld (c) contre %Ld (mn) \n", cblasValue, mnblasValue);


    printf("---- dot ----\n");
    start = _rdtsc () ;
        cblas_ddot(VECSIZE, v1, 1, v2, 1) ;
    end = _rdtsc () ;
    printf ("Nombre de cycles cblas pour dswap: %Ld \n", end-start-residu);
    cblasValue = end-start-residu;

    start = _rdtsc () ;
        mncblas_ddot (VECSIZE, v1, 1, v2, 1) ;
    end = _rdtsc () ;
    mnblasValue = end - start - residu;

    printf ("Nombre de cycles mnblas pour ddot: %Ld \n", end-start-residu);
    printf ("===== Diff =====\n");
    printf ("Diff : %Ld (c) contre %Ld (mn) \n", cblasValue, mnblasValue);


    printf("---- axpy ----\n");
    start = _rdtsc () ;
        cblas_daxpy (VECSIZE, 2, v1, 1, v2, 1) ;
    end = _rdtsc () ;
    printf ("Nombre de cycles cblas pour dswap: %Ld \n", end-start-residu);
    cblasValue = end-start-residu;

    start = _rdtsc () ;
        mncblas_daxpy (VECSIZE, 2, v1, 1, v2, 1) ;
    end = _rdtsc () ;
    mnblasValue = end - start - residu;

    printf ("Nombre de cycles mnblas pour ddot: %Ld \n", end-start-residu);
    printf ("===== Diff =====\n");
    printf ("Diff : %Ld (c) contre %Ld (mn) \n", cblasValue, mnblasValue);


    /********* Perf de BLAS2 *********/

    // printf("---- gemv ----\n");
    // start = _rdtsc () ;
    //     mncblas_dgemv (101, 111, VECSIZE, VECSIZE, 1, matr1, VECSIZE, v1, 1, 1, matr2, 1);
    // end = _rdtsc () ;
    // printf ("Nombre de cycles cblas pour dswap: %Ld \n", end-start-residu);
    // cblasValue = end-start-residu;

    // start = _rdtsc () ;
    //     mncblas_dgemv (101, 111, VECSIZE, VECSIZE, 1, matr1, VECSIZE, v1, 1, 1, matr2, 1);
    // end = _rdtsc () ;
    // mnblasValue = end - start - residu;

    // printf ("Nombre de cycles mnblas pour ddot: %Ld \n", end-start-residu);
    // printf ("===== Diff =====\n");
    // printf ("Diff : %Ld (c) contre %Ld (mn) \n", cblasValue, mnblasValue);


    /********* Perf de BLAS3 *********/

    // ne fonctionne pas encore !
}

void vector_init_perf (vdouble V, double x)
{
  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    V [i] = x ;

  return ;
}

void matrix_init_perf(void *a, double x){
    double *af = (double *) a;
    register int i = 0;
    register int j = 0;
    for(int j = 0; j < VECSIZE; j++){
        for(int i = 0 ; i < VECSIZE ; i++){
            *(af+j*i) = x;
        }
    }

}

double compute_flops(unsigned long long c){

}