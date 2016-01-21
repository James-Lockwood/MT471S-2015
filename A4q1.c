#include <math.h>
#include <stdio.h>
double f(double x, double z, double a, double b);
int main(void) {
	int i, steps;
	double a, b, h, x,z;
	b=0.0;
	z=0.0;
	a =0.0;
	double trap, trap_old, sum;
	/*
	 * Going to integrate pow(pow(x,2) + 1,z)*exp(-x).
	 * Read in the two limits a and b and also z.
	 */
	 printf("Please enter a, b and z:");
	 scanf("%lf %lf %lf", &a,&b,&z);

	steps = 1;
	h = (b - a)/steps;
	trap = h*(f(a,z,a,b)/2.0 + f(b,z,a,b)/2.0);
	/*
	 * Now, keep doubling the number of steps until things look good.
	 */
	do {
		trap_old = trap;
		steps *= 2;
		h /= 2.0;
		x = a + h;
		sum = 0.0;
		for (i = 1; i < steps; i += 2.0) {
			sum += f(x,z,a,b);
			x += 2.0*h;
		}
		trap = trap_old * 0.5 + sum*h;
	} while (fabs(trap_old - trap) > 0.000001);
	/*
	 * Print out the answer.
	 */
	printf("steps=%d trap=%lf", steps, trap);
	return 0;
}
//This is our function for the equation
double f(double x, double z, double a, double b) {
	if(x<=a||x>=b)
	{
		return 0.0;
	}
	return pow(pow(x,2) + 1,z)*exp(-x);
}
