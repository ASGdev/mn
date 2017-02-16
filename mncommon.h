#define VEC_SIZE 4

typedef float VFLOAT [VEC_SIZE] ;
typedef float MFLOAT [VEC_SIZE][VEC_SIZE] ;

typedef double vdouble [VEC_SIZE];
typedef double vdouble [VEC_SIZE];

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

/*enum _MNCBLAS_LAYOUT {CblasColMajor, CblasRowMajor};
typedef enum _MNCBLAS_LAYOUT MNCBLAS_LAYOUT;

enum _MNCBLAS_TRANSPOSE {true, false};
typedef enum _MNCBLAS_TRANSPOSE MNCBLAS_TRANSPOSE;*/
