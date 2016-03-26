#include <stdio.h>

int compteLettres(char tab[],int indice){
	if(tab[indice]=='\0'){
		return 0;
	}
	else{
		return 1+compteLettres(tab,indice+1);
	}
}

int verifChainesEgales(char tab1[],char tab2[],int indice){
	if(indice==compteLettres(tab1,0)){
		return 1;
	}
	else if(tab1[indice]==tab2[indice]){
		return verifChainesEgales(tab1,tab2,indice+1);
	}
	else{
		return 0;
	}
}

int main(){
	char tab[]="abcd";
	char tab1[]="test";
	printf("%d\n",compteLettres(tab,0));
	printf("%d\n",verifChainesEgales(tab,tab1,0));
	return 0;
}
