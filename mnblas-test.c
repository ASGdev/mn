/* Tests unitaires pour MNBLAS */
/* DE ARAUJO Bastien, SURIER GAROFALO Aurélien <aurelien.surier@gmail.com> */

#include <stdio.h>
#include "mncommon.h"
#define N 4

int dumpVector();
int dumpMatrix();
int testType();

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
  // Copy
  // init V1
  // copie de V1 vers V2 simple
  //V2 = mnblas_copy(V1, )

  // copie de V1 vers V2 avec incrément X=1, Y=1

  // copie de V1 vers V2 avec incrément de X tq incX > X -> doit retourner X (fallback à 1)

  float tabs[4] = {1.23,2.34,3.45,4.56};
  double tabd[4] = {1.11,2.22,3.33,4.44};
  //float tabc[4] = {1.23,2.34,3.45,4.56};
  //float tabz[4] = {1.23,2.34,3.45,4.56};
  //V1[0] = 1.1; V1[1] = 2.2; V1[2] = 3.3 ; V1[3] = 4.4;

  dumpVector(tabs, N, s);
  dumpVector(tabd, N, d);

  DCOMP V1;

  /***** Construct complex vector ****/

  V1[0].REEL = 1.0;
  V1[0].IMAG = 1.1;
  V1[1].REEL = 2.0;
  V1[1].IMAG = 2.2;
  V1[2].REEL = 3.0;
  V1[2].IMAG = 3.3;
  V1[3].REEL = 4.0;
  V1[3].IMAG = 4.4;

    dumpVector(V1, N, z);

  /***************/


  /***** Construction matrice ****/
  // M = 4;
  // N = 4;

  float M[4][4];
  M[0][0] = 0;
  M[0][1] = 0;
  M[0][2] = 0;
  M[0][3] = 0;
  M[1][0] = 1;
  M[1][1] = 1;
  M[1][2] = 1;
  M[1][3] = 1;
  M[2][0] = 2;
  M[2][1] = 2;
  M[2][2] = 2;
  M[2][3] = 2;
  M[3][0] = 3;
  M[3][1] = 3;
  M[3][2] = 3;
  M[3][3] = 3;


dumpMatrix(M, 4, s);


  /********************************/

  ////////////// BLAS 2 ////////////////


  //dumpMatrix();

  ////////////// BLAS 3 ////////////////

  //dumpMatrix();

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

int dumpMatrix(void *matrix, int l, enum Type t){
//    if (t != d || t != c || t != z || t != s){
//        printf("[ERROR] Parameter t (type) not valid !");
//        return 1;
//    }

//Matrix[M][N];
  register int i = 0;
  register int y = 0;
  if( t == c || t == z) l=l*2;
  for(int y = 0; y<l*l ; y++){
        if ((y % N) == 0){
            printf("\n");
        }
        if (t == s){
            printf(" %f ", ((float*)matrix)[y]);
        } else if(t == d){
            printf(" %f ", ((double*)matrix)[y]);
        } //else if(t == c){
//            printf(" (%f,", ((float*)matrix)[i+y]);
//            printf("%f) ", ((float*)matrix)[(++i)+y]);
//        } else {
//            printf(" (%f,", ((double*)matrix)[y+i]);
//            printf("%f) ", ((double*)matrix)[(++i) + y]);
//        }


    //printf(" ]\n");
  }
  return 0;
}

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
