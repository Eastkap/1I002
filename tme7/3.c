#include <stdio.h>
#define taille 50

void initSalle(int resa[]){
	int i=0;
	for(i=0;i<taille;i++){
		resa[i]=1;
	}
}

int verif_n_places(int resa[],int n){
	int i=0,p=0;
	for(i=0;i<taille;i++){
		if(resa[i]==1){
			p++;
		}
	}
	if(p>=n){
		return 1;
	}
	return 0;
	}

int test_dispo(int resa[],int nb){
	int i=0,p=0,indice,j;
	for(i=0;i<taille;i++){
		p=0;
		if(resa[i]==1){
			p++;
			indice=i;
			for(j=1;j<taille;j++){
				if(resa[i+j]!=1){
					if(p==nb){
						return indice;
					}
					j=taille;
				}
				else{
					p++;
					if(p==nb){
						return indice;
					}
				}
			}
			i=i+j; // acceleration de la grande boucle
		}
	}
	return -1;
}

int max_libres(int resa[],int nb){
	int i,o;
	for(i=nb;i>0;i++){
		o=test_dispo(resa,i);
		if(o!=-1){
			return o;
		}
	}
	return -1;
}

int reserve(int resa[],int nb){
	int i,o,aplacer=nb,j;
	while(aplacer>0){
		for(i=aplacer;i>0;i--){
			o=test_dispo(resa,i);
			if(o!=-1){
				aplacer-=i;
				for(j=o;j<o+i;j++){
					resa[j]=0;
				}
				i=0;
			}
			
		}
	}
	return 0;
}


int main(){
	int resa[taille],places;
	initSalle(resa);
	while(verif_n_places(resa,1)){
		printf("places a reserver: ");
		scanf("%d",&places);
		reserve(resa,places);
	}
	return 0;
}
