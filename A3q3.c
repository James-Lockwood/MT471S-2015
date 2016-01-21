#include <stdio.h>
#define DIM 4
int main(void) {
	double A[DIM][DIM];
	double B[DIM][DIM];
	double C[DIM][DIM];
	double D[DIM][DIM];
	
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


	/*
	 * Calculate (A)^2 and put into B.
	 */
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			B[i][j] = 0.0;
			for (k = 0; k < DIM; k++){
				B[i][j] += A[i][k]*A[k][j];
			}
		}
	}	
	/*
	 * Calculate (A)^3 (ie. B*A) and put into C.
	 */
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			C[i][j] = 0.0;
			for (k = 0; k < DIM; k++){
				C[i][j] += B[i][k]*A[k][j];
			}
		}
	}
	/*
	 * Calculate (A)^6 (ie. C^2) and put into D.
	 */
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			D[i][j] = 0.0;
			for (k = 0; k < DIM; k++){
				D[i][j] += C[i][k]*C[k][j];
			}
		}
	}	
	int high = 0;
	int vertex = -1;
	//checks along the diagonal of the matrix
	for (i = 0; i < DIM; i++) {
			//if we find a vertex with more paths of length 6 then replace high value and record which vertex it's at
			if(D[i][i] > high) {
				high = D[i][i];
				vertex = i;
			}
			
		}
		//Print paths of length n from vertex with most
		printf("There are %d paths from vertex %d \n", high, vertex);
	
return 0;
}
