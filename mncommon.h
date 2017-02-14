#define VEC_SIZE 4

typedef float VFLOAT [VEC_SIZE] ;

typedef struct {
	float REEL;
	float IMAG;
}vcomplexe;

typedef vcomplexe VCOMP [VEC_SIZE] ;

typedef struct {
	double REEL;
	double IMAG;
}dcomplexe;

typedef dcomplexe DCOMP [VEC_SIZE] ;

enum MNCBLAS_LAYOUT {CblasColMajor, CblasRowMajor};


