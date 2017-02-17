/* Tests pour MNBLAS */
/* DE ARAUJO Bastien, SURIER GAROFALO Aurélien <aurelien.surier@gmail.com> */

#include <gsl/gsl_cblas.h>
#include <stdio.h>
#include "mncommon.h"
#include "vars.h"
#include "mnblas.h"
#define N 4
#define VEC_SIZE 4
#define VECSIZE 4


int dumpVector();
//int //dumpMatrix();
int testType();
void fillVectors();
void generateRandom();

enum Type {s, d, c, z};
enum Type t;

int main(){
    printf("=== MNBLAS : TESTS ===\n");
    int writeFile = 1;
    FILE *fp;
    fp = fopen("mnblaslog", "w+");
    if(fp == NULL){
        printf("[ERROR] Unable to open file to write...\n");
        writeFile = 0;
    }

    ////////////// BLAS 1 ////////////////
    VFLOAT vec2 ;
    vdouble vecd3;
    printf("Vecteur de base \n");
    dumpVector(vec1, N, s);
    printf("\n");

    // COPY //
    //VFLOAT
    // copie de V1 vers V2 simple
    printf("COPY Vecteur mncblas \n");
    mncblas_scopy(4, vec1, 1, vec2, 1);
    dumpVector(vec2, N, s);
    printf("\n");

    printf("COPY Vecteur cblas \n");
    cblas_scopy(4, vec1, 1, vec2, 1);
    dumpVector(vec2, N, s);
    printf("\n");


    // copie de V1 vers V2 double
    printf("COPY Vecteur mncblas double\n");
    mncblas_dcopy(4, vecd1, 1, vecd3, 1);
    dumpVector(vecd3, N, s);
    printf("\n");

    printf("COPY Vecteur cblas double\n");
    cblas_dcopy(4, vecd1, 1, vecd3, 1);
    dumpVector(vecd3, N, s);
    printf("\n");

  // copie de V1 vers V2 avec incrément X=1, Y=1
  // copie de V1 vers V2 avec incrément de X tq incX > X -> doit retourner X (fallback à 1)
    
    // DOT //
    // simple
    printf("DOT Vecteur mncblas \n");
    float resultat = mncblas_sdot(VECSIZE, vec1, 1, vec2, 1);
    printf("%f \n", resultat);
    printf("\n");

    printf("DOT Vecteur cblas \n");
    resultat = cblas_sdot(VECSIZE, vec1, 1, vec2, 1);
    printf("%f \n", resultat);
    printf("\n");
    // double
    printf("DOT Vecteur mncblas double\n");
    resultat = mncblas_ddot(VECSIZE, vecd1, 1, vecd3, 1);
    printf("%f \n", resultat);
    printf("\n");

    printf("DOT Vecteur cblas double\n");
    resultat = cblas_ddot(VECSIZE, vecd1, 1, vecd3, 1);
    printf("%f \n", resultat);
    printf("\n");

    // SWAP //
    // simple
    printf("SWAP Vecteur mncblas \n");
    printf("initial\n");
    dumpVector(vec2, N, s);
    dumpVector(vec3, N, s);
    mncblas_sswap(VECSIZE, vec2, 1, vec3, 1);
    printf("Swapé\n");
    dumpVector(vec2, N, s);
    dumpVector(vec3, N, s);
    printf("\n");

    // double
    printf("SWAP Vecteur mnblas double\n");
    printf("initial\n");
    dumpVector(vecd3, N, s);
    dumpVector(vecd2, N, s);
    mncblas_dswap(VECSIZE, vecd3, 1, vecd2, 1);
    printf("swapé\n");
    dumpVector(vecd3, N, s);
    dumpVector(vecd2, N, s);
    printf("\n");

    // SAXPY //
    // simple
    cblas_scopy(4,vec2, 1, vec3, 1);
    printf("AXPY Vecteur mncblas \n");
    mncblas_saxpy(VECSIZE, 2, vec1, 1, vec2, 1);
    dumpVector(vec2, N, s);
    printf("\n");

    printf("AXPY Vecteur cblas \n");
    cblas_saxpy(VECSIZE, 2, vec1, 1, vec3, 1);
    dumpVector(vec3, N, s);
    printf("\n");

    // double
    cblas_dcopy(4,vecd3, 1, vecd2, 1);
    printf("AXPY Vecteur mncblas double\n");
    mncblas_daxpy(VECSIZE, 2, vecd1, 1, vecd3, 1);
    dumpVector(vecd3, N, s);
    printf("\n");

    printf("AXPY Vecteur cblas double\n");
    cblas_daxpy(VECSIZE, 2, vecd1, 1, vecd3, 1);
    dumpVector(vecd3, N, s);
    printf("\n");
    ////////////// BLAS 2 ////////////////
    VFLOAT vec3, vec4;
    
    float alpha = 1.0;
    float beta = 1.0;
    //mncblas_sgemv(101, 111, VECSIZE, VECSIZE, alpha, mat1, VECSIZE, vec1, 1, beta, vec2, 1);
    //dumpVector(vec4, N, s);

    ////////////// BLAS 3 ////////////////
    float *p1 = &mat1[0][0];
    float *p2 = &mat2[0][0];
    float *p3 = &mat3[0][0];

    float alphaa = 1.0;
    float betaa = 1.0;

    // GEMM //
    printf("GEMM Vecteur mncblas\n");
    mncblas_sgemm(101, 111, 111, VECSIZE, VECSIZE, VECSIZE, alphaa, p1, VECSIZE, p2, VECSIZE, betaa, p3, VECSIZE);
    //dumpMatrix(p3, VECSIZE, s);
    printf("\n");

    printf("GEMM Vecteur cblas\n");
    cblas_sgemm(101, 111, 111, VECSIZE, VECSIZE, VECSIZE, alphaa, p1 , VECSIZE, p2, VECSIZE, betaa, p3, VECSIZE);
    //dumpMatrix(p3, VECSIZE, s);
    printf("\n");

    // GEMV //
    // Vecteur de base
    printf("Vecteur de départ \n");
    dumpVector(vec2, N, s);
    printf("\n");
    // simple
    printf("GEMV Vecteur cblas\n");
    cblas_sgemv(101, 111, VECSIZE, VECSIZE, alphaa, p1, VECSIZE, vec1, 1, betaa, vec2, 1);
    dumpVector(vec2, N, s);
    printf("\n");
    
    printf("GEMV Vecteur mncblas\n");
    mncblas_sgemv(101, 111, VECSIZE, VECSIZE, alphaa, p1, VECSIZE, vec1, 1, betaa, vec2, 1);
    dumpVector(vec2, N, s);
    printf("\n");




    // double

    // VFLOAT vecd3, vecd4;
    
    double alphad = 1.0;
    double betad = 1.0;
    //mncblas_dgemv(101, 111, VECSIZE, VECSIZE, alpha, mat1, VECSIZE, vec1, 1, beta, vec2, 1);
    //dumpVector(vec4, N, s);

    ////////////// BLAS 3 ////////////////
    double *p1d = &matd1[0][0];
    double *p2d = &matd2[0][0];
    double *p3d = &matd3[0][0];

    double alphaad = 1.0;
    double betaad = 1.0;

    printf("Vecteur de départ double\n");
    dumpVector(vecd3, N, s);
    printf("\n");

    printf("GEMV Vecteur cblas double\n");
    cblas_dgemv(101, 111, VECSIZE, VECSIZE, alphaad, p1d, VECSIZE, vecd1, 1, betaad, vecd3, 1);
    dumpVector(vecd3, N, s);
    printf("\n");
    
    printf("GEMV Vecteur mncblas double\n");
    mncblas_dgemv(101, 111, VECSIZE, VECSIZE, alphaad, p1d, VECSIZE, vecd1, 1, betaad, vecd3, 1);
    dumpVector(vecd3, N, s);
    printf("\n");

  return 0;
}

int dumpVector(void *vectr, int l, enum Type t){
    printf("[");
    if( t == c || t == z) l=l*2;
    for(int i=0; i<l; i++){
        if (t == s){
            printf(" %f ", ((float*)vectr)[i]);
        } else if(t == d){
            printf(" %f ", ((double*)vectr)[i]);
        } else if(t == c){
            printf(" (%f,", ((float*)vectr)[i]);
            printf("%f) ", ((float*)vectr)[++i]);
        } else {
            printf(" (%f,", ((double*)vectr)[i]);
            printf("%f) ", ((double*)vectr)[++i]);
        }
    }
    printf("]\n");
  return 0;
}

// int //dumpMatrix(void *matrix, int l, enum Type t){
// //    if (t != d || t != c || t != z || t != s){
// //        printf("[ERROR] Parameter t (type) not valid !");
// //        return 1;
// //    }

// //Matrix[M][N];
//   register int i = 0;
//   register int y = 0;
//   if( t == c || t == z) l=l*2;
//   for(int y = 0; y<l*l ; y++){
//         if ((y % N) == 0){
//             printf("\n");
//         }
//         if (t == s){
//             printf(" %f ", ((float*)matrix)[y]);
//         } else if(t == d){
//             printf(" %f ", ((double*)matrix)[y]);
//         } //else if(t == c){
// //            printf(" (%f,", ((float*)matrix)[i+y]);
// //            printf("%f) ", ((float*)matrix)[(++i)+y]);
// //        } else {
// //            printf(" (%f,", ((double*)matrix)[y+i]);
// //            printf("%f) ", ((double*)matrix)[(++i) + y]);
// //        }


//     //printf(" ]\n");
//   }
//   return 0;
// }

int testType(enum Type t){
    if(t == s){

        printf("type is s");
    } else if(t == d){
      printf("type is d");
  } else if(t == c){
      printf("type is c");
  } else if(t == z){
    printf("type is z");
  } else {
    printf("type is no");
  }
}

void fillVectors(){
    vecteurCF1[0].REEL = 1.0; vecteurCF1[0].IMAG = 1.1;
  vecteurCF1[1].REEL = 2.0;  vecteurCF1[1].IMAG = 2.2;
  vecteurCF1[2].REEL = 3.0;vecteurCF1[2].IMAG = 3.3;
  vecteurCF1[3].REEL = 4.0;vecteurCF1[3].IMAG = 4.4;

  vecteurCD1[0].REEL = 1.0;vecteurCD1[0].IMAG = 1.1;
  vecteurCD1[1].REEL = 2.0;vecteurCD1[1].IMAG = 2.2;
  vecteurCD1[2].REEL = 3.0;vecteurCD1[2].IMAG = 3.3;
  vecteurCD1[3].REEL = 4.0;vecteurCD1[3].IMAG = 4.4;
}

void vector_init (VFLOAT V, float x){

  register unsigned int i ;

  for (i = 0; i < VECSIZE; i++)
    V [i] = x ;

  return ;
}

// void matrixInit(MFLOAT V, float x){
//     register unsigned int i ;
//     register unsigned int j;

//   for (i = 0; i < VECSIZE; i++){
//     for (j = 0; j < VECSIZE; j++){
//         V[i][j] = x ;
//     }
//   }
// }

//void generateRandom(void* container, type t, int h){
//    srand ( time ( NULL));
//    random_value = (double)rand();
//}
