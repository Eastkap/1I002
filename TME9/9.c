#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MIN 0
#define MAX 99
#define TAILLE 10

void init(int tab[], int taille){
	int i;
	srand(time(NULL));
	for(i=0;i<taille;i++){
		tab[i]=MIN+rand()%(MAX+1);
		printf("%d - ", tab[i]);
	}
}

int min_tab(int tab[],int n){
	if(n==0){
			return tab[0];
	}
	else if(tab[n]<min_tab(tab,n-1)){
		return tab[n];
	}
	else{
		return min_tab(tab,n-1);
	}
}

int main(){
	int tab[TAILLE];
	init(tab,TAILLE);
	printf("\n%d\n",min_tab(tab,TAILLE-1));
	return 0;
}
