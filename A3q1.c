/*
 * Example of squaring a matrix of size DIM x DIM.
 */
#include <stdio.h>
#define DIM 3
int main(void) {
	double A[DIM][DIM];
	double B[DIM][DIM];
	double C[DIM][DIM];
	double D[DIM][DIM];
	double E[DIM][DIM];
	double F[DIM][DIM];
	int i, j ,k;
	/*
	 * Read in the matrix A.
	 */
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			printf("Please enter a number \n");
			if (scanf("%lf", &A[i][j]) != 1) {
				printf("Couldn’t read element %d, %d\n", i, j);
				return 1;
			}
		}
	}

	printf("2nd matrix \n");
	/*
	 * Read in the matrix B.
	 */
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			printf("Please enter a number\n");
			if (scanf("%lf", &B[i][j]) != 1) {
				printf("Couldn’t read element %d, %d\n", i, j);
				return 1;
			}
		}
	}

	/*
	 * Calculate AB and put into C.
	 */
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			C[i][j]=0.0;
			for(k=0;k<DIM;k++) {
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}


	/*
	 * Calculate (AB)^2 (ie. C^2) and put into D.
	 */
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			D[i][j] = 0.0;
			for (k = 0; k < DIM; k++){
				D[i][j] += C[i][k]*C[k][j];
			}
		}
	}	

	/*
	 * Calculate (A^T) an put it into E
	 */
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			E[i][j] = 0.0;
			for (k = 0; k < DIM; k++){
				E[i][j] = A[j][i];
			}
		}
	}
	/*
	 * Calculate (A^T)*B and put it into F
	 */
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			F[i][j]=0.0;
			for(k=0;k<DIM;k++) {
				F[i][j] += E[i][k]*B[k][j];
			}
		}
	}
	/*
	 * Print out the results.
	 */
	printf("This is the matrix A \n");
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			printf("%lf ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("This is the matrix B\n");
		for (i = 0; i < DIM; i++) {
			for (j = 0; j < DIM; j++) {
				printf("%lf ", B[i][j]);
			}
		printf("\n");
	}

	printf("\n");
	printf("This is the matrix C = AB \n");
		for (i = 0; i < DIM; i++) {
			for (j = 0; j < DIM; j++) {
				printf("%lf ", C[i][j]);
			}
		printf("\n");
	}

	printf("\n");
	printf("This is the matrix D = (AB)^2\n");
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			printf("%lf ", D[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("This is the matrix F = (A^T)B\n");
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			printf("%lf ", F[i][j]);
		}
		printf("\n");
	}

	return 0;
}
