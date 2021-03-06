#include "mnblas.h"

void mncblas_sswap(const int N, float *X, const int incX, float *Y, const int incY){
    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    register float save ;

    for (; ((i < N) && (j < N)) ; i += incX, j+=incY){
        save = X [i] ;
        X [i] = Y [j];
        Y [j] = save ;
    }

    return ;
}

void mncblas_dswap(const int N, double *X, const int incX, double *Y, const int incY){
    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    register double save ;

    for (; ((i < N) && (j < N)) ; i += incX, j+=incY){
        save = Y[j] ;
        Y[j] = X[i] ;
        X[i] = save ;
    }

    return ;
}

void mncblas_cswap(const int N, void *X, const int incX, void *Y, const int incY){
    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    register float save ;
    float *XP = (float *) X;
    float *YP = (float *) Y;

    for (; ((i < N) && (j < N)) ; i += incX, j+=incY){
        save = YP[j] ;
        YP[j] = XP[i] ;
        XP[i+1] = YP[j+1]; 
        XP[i] = save ;
    }

    return ;
}

void mncblas_zswap(const int N, void *X, const int incX, void *Y, const int incY){
    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    register double save ;
    double *XP = (double *) X;
    double *YP = (double *) Y;

    for (; ((i < N) && (j < N)) ; i += incX, j+=incY){
        save = YP[j] ;
        YP[j] = XP[i] ;
        XP[i+1] = YP[j+1]; 
        XP[i] = save ;
    }
    return ;
}