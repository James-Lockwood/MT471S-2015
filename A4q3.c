/*
Calculate the integral sin(y)/y dy over the limit 0 to 2.0 
*/
#include <stdio.h>
#include <math.h>
double f(double y);
int main(void){
	//Make all of our variables
	double y,h;
	int steps,i;
	double simp,x;
	simp=0;	
	steps=1000;
	
	for(x=0;x<2.1;x+=0.1){
		//a,x are the lower and upper limits respectivly, as x = 0 we can just use x
		h=x/steps;	 
		simp=-f(0);
		y=0;
		for(i=0;i<steps ; i+=2 ){
			simp+=2.0*(f(y))+4.0*f(y+h);
			y+=2*h;
		}
		simp+=f(x);
		simp*=h/3.0;
		printf("F(x)= %lf for x =%lf \n",simp,x);
	}
	return 0;
}
double f(double y){
	if(y!=0){
		return sin(y)/y;
	}
	else{
	return 1;
	}
}
