 #include "mncommon.h"

 int main(){
     return 0;
 }

void mncblas_sgemv (MNCBLAS_LAYOUT Layout, MNCBLAS_TRANSPOSE trans, const int m, const int n, const float alpha, const float *a, const int lda, const float *x, const int incx, const float beta, float *y, const int incy){
    //y := alpha*A*x + beta*y,
    if (incX == 0 || incY == 0){
        return 0;
    }
    for (; ((i < N) && (j < N)) ; i += incX, j += incY){
		Y[j] = X[i] ;
	}


};
