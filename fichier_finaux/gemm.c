#include "mnblas.h"



void mncblas_sgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const float alpha, const float *A,
                 const int lda, const float *B, const int ldb,
                 const float beta, float *C, const int ldc){

	register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    register unsigned int k = 0 ;
    float *gemm;

    for(; i<N; i++){
    	gemm[i] = 0;
    }

    i = 0;

    for(;k < N; k++){
	    for(; j < N; j++){
		    for(; (i < N); i++){
		    	// gemm[j+k*N] =  gemm[j+k*N] + alpha * A[i] * B[i*N+j];
		    }
	    }
    }
	
	for(; i < N*N; i++){
	// 	gemm[i] = gemm[i] + beta * C[i];
	}

	// *C = *gemm;
}

void mncblas_dgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const double alpha, const double *A,
                 const int lda, const double *B, const int ldb,
                 const double beta, double *C, const int ldc){

	register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    register unsigned int k = 0 ;
    double *gemm;

    for(;k < N; k++){
	    for(; j < N; j++){
		    for(; (i < N); i++){
		    	gemm[j+k*N] =  gemm[j+k*N] + alpha * A[i] * B[i*N+j];
		    }
	    }
    }
	
	for(; i < N*N; i++){
		gemm[i] = gemm[i] + beta * C[i];
	}

	*C = *gemm;
}

void mncblas_cgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const void *alpha, const void *A,
                 const int lda, const void *B, const int ldb,
                 const void *beta, void *C, const int ldc){

	register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    register unsigned int k = 0 ;

    float *alp = (float *) alpha;
    float *bet = (float *) beta;
    float *b = (float *) B;
    float *c = (float *) C;
    float *a = (float *) A;

    float *re;
    float *im;

    for(;k < N; k++){
	    for(; j < N; j++){
		    for(; (i < N); i++){
		    	if (j%2 == 0){
		    		if(k%2==0){
		    			re[j+k*N] =  re[j+k*N] + *alp * a[i] * b[i*N+j];
		    		}else{
		    			re[j+k*N] =  re[j+k*N] + *alp * a[i] * b[i*N+j];
		    		}
		    	}else{
		    		if (i%2 == 0){
		    			re[j+k*N] =  re[j+k*N] + *alp * a[i] * b[i*N+j];
		    		}else{
		    			re[j+k*N] =  re[j+k*N] - *alp * a[i] * b[i*N+j];
		    		}
		    	}
		    }
	    }
    }
	
	for(; i < N*N; i++){
		if (i%2 == 0){
			re[i] = re[i] + *bet * c[i];
		}else{
			im[i] = im[i] + *bet * c[i];
		}
	}

	i, j = 0;
	for (; i < N; i++){
		for(;j < N; j++){
			if (i%2 == 0){
				c[i] = re[i/2];
			}else{
				c[i] = im[(i+1)/2];
			}
		}
	}

	// *c = *gemm;
}

void mncblas_zgemm(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
                 MNCBLAS_TRANSPOSE TransB, const int M, const int N,
                 const int K, const void *alpha, const void *A,
                 const int lda, const void *B, const int ldb,
                 const void *beta, void *C, const int ldc){

	register unsigned int i = 0 ;
    register unsigned int j = 0 ;
    register unsigned int k = 0 ;

    double *alp = (double *) alpha;
    double *bet = (double *) beta;
    double *b = (double *) B;
    double *c = (double *) C;
    double *a = (double *) A;

    double *re;
    double *im;

    for(;k < N; k++){
	    for(; j < N; j++){
		    for(; (i < N); i++){
		    	if (j%2 == 0){
		    		if(k%2==0){
		    			re[j+k*N] =  re[j+k*N] + *alp * a[i] * b[i*N+j];
		    		}else{
		    			re[j+k*N] =  re[j+k*N] + *alp * a[i] * b[i*N+j];
		    		}
		    	}else{
		    		if (i%2 == 0){
		    			re[j+k*N] =  re[j+k*N] + *alp * a[i] * b[i*N+j];
		    		}else{
		    			re[j+k*N] =  re[j+k*N] - *alp * a[i] * b[i*N+j];
		    		}
		    	}
		    }
	    }
    }
	
	i, j = 0;
	for (; i < N; i++){
		for(;j < N; j++){
			if (i%2 == 0){
				c[i] = re[i/2];
			}else{
				c[i] = im[(i+1)/2];
			}
		}
	}

	// *c = *gemm;
}