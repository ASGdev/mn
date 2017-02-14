#include <stdio.h>
#include <string.h>

#define VEC_SIZE   50

typedef float VFLOAT [VEC_SIZE] ;
typedef double VDOUBLE [VEC_SIZE] ;

typedef struct {
	float REEL;
	float IMAG;
}vcomplexe;

typedef struct {
	double REEL;
	double IMAG;
}dcomplexe;

typedef vcomplexe VCOMP [VEC_SIZE] ;
typedef dcomplexe DCOMP [VEC_SIZE] ;

VFLOAT V1, V2, V3 ;
VDOUBLE V4, V5, V6;
VCOMP V7, V8, V9;
DCOMP V10, V11, V12;

int main(){
	printf("%lu\n", sizeof(V1));
	printf("%lu\n", VEC_SIZE*sizeof(float));

	
	return 0;
}

void myCopyVFLOAT(VFLOAT v){
	VFLOAT nv;
	memcpy(nv, v, sizeof(v));
}

void myCopyVDBOUBLE(VDOUBLE v){
	VDOUBLE nv;
	memcpy(nv, v, sizeof(v));
}

void myCopyVCOMP(VCOMP v){
	VCOMP nv;
	memcpy(nv, v, sizeof(v));
}

void myCopyDCOMP(DCOMP v){
	DCOMP nv;
	memcpy(nv, v, sizeof(v));
}



