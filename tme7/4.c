#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T 6


int ajouter_tab(int tab[],int val, int* n){
	int i=0,temp=val;
	for(i=0;i<*n;i++){
		if(tab[i]>val){
			temp=tab[i];
			tab[i]=val;
			return ajouter_tab(tab, temp,n);
		}
	}
	tab[*n]=val;
	*n+=1;
	return 1;
}

void printab(int tab[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",tab[i]);
	}
	printf("\n");
}

int intab(int tab[],int v, int t){
	int i=0;
	for(i=0;i<t;i++){
		if(tab[i]==v){
			return 1;
		}
	}
	return 0;
}

void init(int tab[], int taille){
	int i,j=0,o;
	for(i=0;i<taille;i++){
		do{
			o=1+rand()%49;
		}
		while(intab(tab,o,i)==1);
		ajouter_tab(tab,o,&j);
	}
}
	
void lire_tab(int tab[],int taille){
	int i,j=0,o;
	for(i=0;i<taille;i++){
		do{
			scanf("%d",&o);
			if(o==1 && i==0){
				break;
			}
		}
		while(intab(tab,o,taille)==1 || o<1 || o>49);
		ajouter_tab(tab,o,&j);
	}
}

int compare_tab(int tab[],int tabu[],int taille){
	int i=0;
	for(i=0;i<taille;i++){
		if(tab[i]!=tabu[i]){
			return 0;
		}
	}
	return 1;
}

int main(){
	int tab[T],tabu[T];
	//int n=0;
	srand(time(NULL));
	init(tab,T);
	printf("saisir %d entiers\n",T);
	lire_tab(tabu,T);
	printf("resultat comparaison: %d\n",compare_tab(tab,tabu,T));
	printab(tab,T);
	printab(tabu,T);
	return 0;
}
