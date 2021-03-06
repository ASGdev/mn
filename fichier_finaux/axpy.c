#include "mnblas.h"

void mncblas_saxpy (const int N, const float A, const float *X, const int incX, float *Y, const int incY){

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    register float axpy = 0.0 ;

    for (; ((i < N) && (j < N)) ; i += incX, j+=incY){
        Y[j] = (A * X[i] + Y[j]) ;
    }
}

void mncblas_daxpy (const int N, const double A, const double *X, const int incX, double *Y, const int incY){
    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    register double axpy = 0.0 ;
    for (; ((i < N) && (j < N)) ; i += incX, j+=incY){
        Y[j] = (A * X[i] + Y[j]) ;
    }
}

void mncblas_caxpy (const int N, const void *A, const void *X, const int incX, void *Y, const int incY){

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    float *XP = (float *) X;
    float *YP = (float *) Y;
    float *AP = (float *) A;
    register float reel;
    register float imag;

    for (; ((i < N) && (j < N)) ; i += incX, j+=incY){
        if((i+j)%2==0){
            if(i%2==1)
                reel = reel + (AP[0] * XP[i] + YP[j]);
            else
                reel = reel - (AP[0] * XP[i] + YP[j]);
            }
        else{
          imag = imag + (AP[1] * XP[i] + YP[j]);
        }
    }
}

void mncblas_zaxpy (const int N, const void *A, const void *X, const int incX, void *Y, const int incY){

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    double *XP = (double *) X;
    double *YP = (double *) Y;
    float *AP = (float *) A;
    register double reel;
    register double imag;

    for (; ((i < N) && (j < N)) ; i += incX, j+=incY){
        if((i+j)%2==0){
            if(i%2==1)
                reel = reel + (AP[0] * XP[i] + YP[j]);
            else
                reel = reel - (AP[0] * XP[i] + YP[j]);
            }
        else{
          imag = imag + (AP[1] * XP[i] + YP[j]);
        }
    }

}
