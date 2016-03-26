#include <stdio.h>

int fibo_rec(int n){
	if(n>=2){
		int a=fibo_rec(n-1);
		int b=fibo_rec(n-2);
		printf("%d %d\n",a,b);
		return a+b;
	}
	else{
		return 1;
	}
}

//1 on fait beaucoup de fois la meme operation

int fibo_ite(int n){
	int i=2;
	int r2=1,r1=1,r0;
	for(i=2;i<n;i++){
		r0=r2+r1;
		r2=r1;
		r1=r0;
	}
	return r0;
}

int main(){
	printf("resultat: %d\n",fibo_rec(10-1));
	printf("resultat ite: %d\n",fibo_rec(10-1));
	return 0;
}

