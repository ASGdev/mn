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
  /* complex non conjugué */

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;

    float *XP = (float *) X;
    float *YP = (float *) Y;

    register float dotR = 0.0 ;
    register float dotI = 0.0;
    for (; ((i < N*2) && (j < N*2)) ; i += incX, j+=incY){
        dotR = dotR + ((XP[i]*YP[j])-(XP[i+1]*YP[j+1]));
        dotI = dotI + ((XP[i]*YP[j+1])+(XP[i+1]*YP[j]));
    }

    dcomplexe R;
    R.REEL = dotR;
    R.IMAG = dotI;
    *((dcomplexe*)dotu) = R;
    return ;
}

void   mncblas_cdotc_sub(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc){

    register unsigned int i = 0 ;
    register unsigned int j = 0 ;

    float *XP = (float *) X;
    float *YP = (float *) Y;

    register float dotR = 0.0 ;
    register float dotI = 0.0;
    for (; ((i < N*2) && (j < N*2)) ; i += incX, j+=incY){
        dotR = dotR + ((XP[i]*YP[i])-(XP[i+1]*YP[j+1]));
        dotI = dotI + ((XP[i]*YP[j+1])+(XP[i+1]*YP[i]));
    }

    dcomplexe R;
    R.REEL = dotR;
    R.IMAG = dotI;
    *((dcomplexe*)dotu) = R;
    return ;
}
  /* a completer conjugué */

    return ;
}

void   mncblas_zdotu_sub(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotu){
  /* a completer */

    return ;
}

void   mncblas_zdotc_sub(const int N, const void *X, const int incX, const void *Y, const int incY, void *dotc){
  /* a completer */

    return ;
}


int main(){
}

