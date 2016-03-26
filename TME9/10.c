#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MIN 0
#define MAX 20
#define TAILLE 10

void init(int tab[], int taille){
	int i;
	srand(time(NULL));
	for(i=0;i<taille;i++){
		tab[i]=MIN+rand()%(MAX+1);
		printf("%d - ", tab[i]);
	}
}

int presence_el(int el,int tab[],int n){
	if(n==0){
		return 0;
	}
	else if(el==tab[n-1]){
		return 1;
	}
	return presence_el(el,tab,n-1);
}

int main(){
	int tab[TAILLE];
	init(tab,TAILLE);
	printf("\n%d\n",presence_el(7,tab,TAILLE));
	return 0;
}
