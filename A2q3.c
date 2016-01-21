#include <stdio.h>
int main(void)
{
int res = Eul(123456789);
printf("%d \n", res);
return 0;
}

int Eul(int a)
{
	int count = 0;
	int i =1;
	for(i;i<a;i++){
     	    if(gcd(a,i)==1){
		count++;
		}	
	}
return count;
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
