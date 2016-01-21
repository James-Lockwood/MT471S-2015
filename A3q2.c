#include <stdio.h>
#define DIM 5
int main(void) {
	int A[DIM][DIM];
	int B[DIM][DIM];
	int C[DIM][DIM];
	int i, j ,k, total;
	/*
	 * Read in the matrix A.
	 */
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			printf("Please enter a number \n");
			if (scanf("%d", &A[i][j]) != 1) {
				printf("Couldn’t read element %d, %d\n", i, j);
				return 1;
			}
		}
	}

	/*
	 * Calculate A^2 and put into B.
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
	 * Calculate A^3 (ie B*A) and put into C.
	 */
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			C[i][j] = 0.0;
			for (k = 0; k < DIM; k++){
				C[i][j] += B[i][k]*A[k][j];
			}	
		}
	}
	//Prints out the original matrix just to show the user it's what they meant to input
	printf("This is the matrix A \n");
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	total = 0;
	//Prints the number of triangles each vertex is part of
	for(i=0;i<DIM;i++) {
		printf("Vertix %d is part of %d triangles.\n", i+1, C[i][i]/2);
		if(C[i][i]/2 > total) {
			total = C[i][i]/2;
		}
	}
	//Prints max triangles
	printf("Total of %d triangles.", total);
	return 0;
}
