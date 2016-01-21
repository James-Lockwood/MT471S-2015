#include<stdio.h>
#include<math.h>
float f(float x)
{
    return ((x*x*x*x*x) + 3*(x*x*x*x) + 6*(x*x*x) + 3*(x*x) + 6*x + 1);
}

int main ()
{
    
    float x, a, b, x1;
    printf("\nEnter the values of a, b:\n");
    scanf("%f %f", &a, &b);
    x=(a+b)/2;
    while(abs(x1-x)>0.000001)
    {
        if (f(a)*f(x) < 0)
	{
            b=x;
	}	
        else
	{
            a=x;
	}
        x1=(a+b)/2;
        if (fabs(x1-x)< 0.000001)
        {
            printf(" root = %f\n",  x1);
            return 0;
        }
        x=x1;
    
   
	  }
 
            
    printf("The solution does not converge or iterations are not sufficient \n");
    return 1;
}
