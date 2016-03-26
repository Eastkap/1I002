#include <stdio.h>
#include <cini.h>
#include <math.h>
#define FENETRE 400
#define TAILLE 15
#define V 3

void affiche_tab(int tab[], int taille){
	int i;
	for(i=0;i<taille;i++){
		printf("%d\t",tab[i]);
	}
	printf("\n");
}

int  init_tab(int tab[], int taille){
	int i,val=0,c=0;
	for(i=0;i<taille;i++){
		printf("Veuillez saisir une valeur ");
		scanf("%d",&val);
		if(val<0){
			i=taille+1;
		}else{
		tab[i] = val;
		c++;
		}
	}
	affiche_tab(tab,c);
	return c;
}

int compte(int tab[], int taille, int v){
	int i,cpt = 0;
	for( i=0;i<TAILLE;i++){
		if(tab[i]==v){
			cpt++;
		}
	}
	return cpt;
}

int max_notes(int tab[], int taille){
	int i,max =0;
	if(taille == 0){
		return -1;
	}else{
		for(i=0; i<taille;i++){
			if(tab[i]>=max){
				max=tab[i];
			}
		}
	}
	return max;
}	

void histogramme(int tab[], int h[], int taille){
	int i,j,c=0;
	for( i=0; i<taille; i++){
		for( j=0; j<taille; j++){
			if(tab[i] == tab[j]){
				c++;
			}
		}
		h[i] = c;
		c=0;
	}
	affiche_tab(h,taille);
}

void dessiner_baton(int point[],int largeur, int hauteur, char couleur []){
	
	CINI_fill_rect(point[0],point[1]-hauteur,largeur,hauteur,couleur);
	CINI_loop();
}

void dessiner_histogramme(int tab[],int h[], int point[], int taille, int largeur, int hauteur, char couleur[]){
	int i,d=0, aux[2];
	aux[0] = point[0];
	aux[1] = point[1];
	for(i=aux[0];i<taille;i++){ 
		dessiner_baton(point,20,h[i]*20,couleur);
		aux[0] = point[0];
		point[0] = aux[0]+20;
		d++;
	}
}


int main(){
	int c;
	int tab[TAILLE];
	int h[TAILLE];
	int point[2];
	point[0] = 0;
	point[1] = 400;
	printf("Initialisation de tab :\n");
	c = init_tab(tab, TAILLE);
	printf("La valeur %d est presente %d fois.\n",V,compte(tab,c,V));
	printf("La valeur maximale est : %d\n",max_notes(tab,c));
	printf("\nTableau d'occurences :\n");
	histogramme(tab,h,c);
	CINI_open_window(FENETRE,FENETRE,"fenetre");
	CINI_fill_window("white");
	/*dessiner_baton(point,50,100,"red"); */
	printf("Dessiner histogramme\n:");
	dessiner_histogramme(tab,h,point,c,20,100,"red");
	return 0;
}
