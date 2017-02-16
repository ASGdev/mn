#include "mnblas.h"

void mncblas_scopy(const int N, const float *X, const int incX, float *Y, const int incY){
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;

  for (; ((i < N) && (j < N)) ; i += incX, j += incY){
      Y [j] = X [i] ;
    }
}

void mncblas_dcopy(const int N, const double *X, const int incX, double *Y, const int incY){
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;

	for (; ((i < N) && (j < N)) ; i += incX, j += incY){
		Y[j] = X[i] ;
	}
}

void mncblas_ccopy(const int N, const void *X, const int incX, void *Y, const int incY){
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;
	float *XP = (float *) X;
	float *YP = (float *) Y;

	for (; ((i < N) && (j < N)) ; i += incX, j += incY){
		YP[j] = XP[i] ;
		XP[i+1] =  YP[j+1];
	}
}

void mncblas_zcopy(const int N, const void *X, const int incX, void *Y, const int incY){
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;
	double *XP = (double *) X;
	double *YP = (double *) Y;

	for (; ((i < N) && (j < N)) ; i += incX, j += incY){
		YP[j] = XP[i] ;
		XP[i+1] =  YP[j+1];
	}
}

