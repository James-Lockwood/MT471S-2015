#include <stdio.h>
int main(void)
{
int x,y;
printf("Insert numbers. To exit insert -1 as one of your numbers: \n");
scanf("%d %d",&x, &y);
if(x==-1)
{
return 1;
}
int res = gcd(x,y);
printf("%d \n",res);
return 0;
}

int gcd(int a, int b)
{
    int posGCD = 1;
    if(a==b){
	return a;
	}
    else if(a>b){
	int i =b;
	for(i;i>=1;i--){
	    if(a%i==0 && b%i==0){
		posGCD = i;
		break;
		}
	    }
        return posGCD;
	}
    else if(b>a){
        int j =a;
	for(j;j>=a;j--){
	    if(a%j==0 && b%j==0){
                posGCD = j;
		break;
		}
	    }
	return posGCD;
	}
}
