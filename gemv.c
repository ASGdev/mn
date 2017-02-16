 #include "mncommon.h"
 #define N 4

 int main(){
     return 0;
 }

void mncblas_sgemv (MNCBLAS_LAYOUT Layout, MNCBLAS_TRANSPOSE trans, const int m, const int n, const float alpha, const float *a, const int lda, const float *x, const int incx, const float beta, float *y, const int incy){
    //y := alpha*A*x + beta*y,
    register unsigned int i = 0 ;
    register unsigned int j = 0 ;

    float *af = (float *) a;

    if (incx == 0 || incy == 0){
        return;
    }

    // calcul de beta*y
    float by;
    for(int j = 0 ; j < n ; j+= incy){
        by = by + (beta * y[j]);
    }

    for(int j = 0; j < n; j+= incy){
        for(int i = 0 ; i < n ; i+= incx){
            *(af+j) = *(af+j) + (*(a+j*i)*y[i])*alpha;
        }
    }
};
