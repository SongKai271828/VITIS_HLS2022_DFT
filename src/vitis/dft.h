#include<math.h>

typedef double DTYPE;
typedef double IN_TYPE;
typedef double TEMP_TYPE;
#define SIZE 1024 		/* SIZE OF DFT */
#define N 1024 		/* SIZE OF DFT */
void dct2d_wrap(DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE],DTYPE real_op[SIZE],DTYPE imag_op[SIZE]);
void dft(DTYPE sample_real[SIZE], DTYPE sample_imag[SIZE], DTYPE real_op[SIZE], DTYPE imag_op[SIZE], const DTYPE c_group[SIZE], const DTYPE s_group[SIZE]);
void dft0(DTYPE real_sample[1024], DTYPE imag_sample[1024],DTYPE real_op[1024], DTYPE imag_op[1024]);
