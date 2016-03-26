#include <stdio.h>
#include <math.h>

#define PI 3.14157
#define PRE 0.01

float piWallis(int n){
	if(n>1){
		float a=(4*n*n);
		float b=(4*n*n)-1;
		return ((a/b)*piWallis(n-1));
	}
	else{
		return (4.0/3.0);
	}
}

float piLeibniz(int n){
	if(n>0){
		float a=pow(-1,n);
		float b=(2*n)+1;
		float c=a/b;
		return c+piLeibniz(n-1);
	}
	else{
		return 1;
	}
}

int main(){
	int i=1;
	while(fabs(PI-piWallis(i)*2)>PRE){
		i++;
	}
	printf("avec piwallis: %f\n",piWallis(i)*2);
	i=0;
	while(fabs(PI-piLeibniz(i)*4)>PRE){
		i++;
	}
	printf("avec pileibniz: %f\n",piLeibniz(i)*4);
	return 0;
}
// les programmes tournent plus longtemps et convergent
