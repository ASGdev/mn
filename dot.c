//#include "mnblas.h"
#include "mncommon.h"

float mncblas_sdot(const int N, const float *X, const int incX, const float *Y, const int incY){
    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    register float dot = 0.0 ;

    for (; ((i < N) && (j < N)) ; i += incX, j+=incY){
        dot = dot + X [i] * Y [j] ;
    }

    return dot ;
}

double mncblas_ddot(const int N, const double *X, const int incX, const double *Y, const int incY){
    register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    register double dot = 0.0 ;
    for (; ((i < N) && (j < N)) ; i += incX, j+=incY){
        dot = dot + X [i] * Y [j] ;

    }
    return dot;
}

void mncblas_cdotu_sub(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotu){
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  float *XP = (float *)X;
  float *YP = (float *)Y;
  register float re;
  register float im;

  for (; ((i < N) && (j < N)) ; i += incX, j+=incY){
    if((i+j)%2==1){
      if(i%2==0)
        re = re + (XP[i] * YP[j]);
      else
        re = re - (XP[i] * YP[j]);
      }
    else{
      im = im + XP[i] * YP[j]; 
    }
  }
}

void  mncblas_cdotc_sub(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc){
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  float *XP = (float *)X;
  float *YP = (float *)Y;
  register float re;
  register float im;

  for (; ((i < N) && (j < N)) ; i += incX, j+=incY){
    if((i+j)%2==1){
      re = re + (XP[i] * YP[j]);
    }
    else{
      if(i%2==0)
        im = im + (XP[i] * YP[j]);
      else
        im = im - XP[i] * YP[j];
    }
  }
}

void  mncblas_zdotu_sub(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotu){
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  double *XP = (double *)X;
  double *YP = (double *)Y;
  register double re;
  register double im;

  for (; ((i < N) && (j < N)) ; i += incX, j+=incY)
  {
    if((i+j)%2==1){
      if(i%2==0)
        re = re + (XP[i] * YP[j]);
      else
        re = re - XP[i] * YP[j];
    }
    else{
      im = im + XP[i] * YP[j]; 
    }
  }
}
  
void   mncblas_zdotc_sub(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc){
  register unsigned int i = 0 ;
  register unsigned int j = 0 ;
  double *XP = (double *)X;
  double *YP = (double *)Y;
  register double re;
  register double im;

  for (; ((i < N) && (j < N)) ; i += incX, j+=incY){
    if((i+j)%2==1){
      re = re + (XP[i] * YP[j]);
    }
    else{
      if(i%2==0)
        im = im + (XP[i] * YP[j]);
      else
        im = im - XP[i] * YP[j];
    }
  }
}




