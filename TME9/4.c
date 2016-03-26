#include <stdio.h>
#include <math.h>

int NombreChiffres(int n){
	if (round(n/10) == 0 ){
		return 1;
	}
	else if(round(n/10 != 0)){
		return 1 + NombreChiffres(round(n/10));
	}
	return 0;
}

float SommeDesChiffres(int n){
	if (round(n/10) == 0 ){
		return n;
	}
	else if(round(n/10 != 0)){
		return n-round(n/10)*10 +SommeDesChiffres(round(n/10));
	}
	return 0;
}

int ProduitDesChiffres(int n){
	if (round(n/10) == 0 ){
		return n;
	}
	else if(round(n/10 != 0)){
		return (n-round(n/10)*10) * ProduitDesChiffres(round(n/10));
	}
	return 0;
}

int niemeChiffre(int x, int n){
	int i=0;
	if(n>NombreChiffres(x)){
		return -1;
	}
	else{
		if (i == n ){
			return (x-round(x/10)*10);
		}
		else if(i != n){
			i++;
			return niemeChiffre((round(x/10)),n-1);
		}
	}
	return 0;
}

int renverseNombre(int n, int indice){
	int t;
	t=NombreChiffres(n);
	if(t==indice){
		return niemeChiffre(n,indice);
	}
	else{
		return niemeChiffre(n,indice+1);
	}
}

int main(){
	int n = 4663;
	printf("\a%d\n",NombreChiffres(n));
	printf("\a%.0f\n",SommeDesChiffres(n));
	printf("\a%d\n",ProduitDesChiffres(n));
	printf("\a%d\n",niemeChiffre(n,3));
	printf("\a%d\n",renverseNombre(n,0));
	return 0;
}
