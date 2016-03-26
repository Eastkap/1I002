#include <stdio.h>

int som_carres_rec(int n){
	if(n==1){
		return 1;
	}
	else{
		return som_carres_rec(n-1)+n*n;
	}
}

int prod_rec(int n){
	if(n==1){
		return 1;
	}
	else{
		return prod_rec(n-1)*n;
	}
}

int main(){
	printf("%d\n",som_carres_rec(3));
	printf("%d",prod_rec(3));
	return 0;
}
