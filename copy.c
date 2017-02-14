#include "mnblas.h"

void mncblas_scopy(const int N, const float *X, const int incX, float *Y, const int incY){
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;

  for (; ((i < N) && (j < N)) ; i += incX, j += incY){
      Y [j] = X [i] ;
    }

  return ;
}

void mncblas_dcopy(const int N, const double *X, const int incX, double *Y, const int incY){
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;

	for (; ((i < N) && (j < N)) ; i += incX, j += incY){
		Y[j] = X[i] ;
	}

	return ;
}

void mncblas_ccopy(const int N, const void *X, const int incX, void *Y, const int incY){
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;
	float *XP = (float *) X;
	float *YP = (float *) Y;

	for (; ((i < N) && (j < N)) ; i += incX, j += incY){
		Y[j] = X[i] ;
		X[i+1] =  Y[j+1];
	}

	return ;
}

void mncblas_zcopy(const int N, const void *X, const int incX, void *Y, const int incY){
	register unsigned int i = 0 ;
	register unsigned int j = 0 ;
	double *XP = (double *) X;
	double *YP = (double *) Y;

	for (; ((i < N) && (j < N)) ; i += incX, j += incY){
		Y[j] = X[i] ;
		X[i+1] =  Y[j+1];
	}

	return ;
}

