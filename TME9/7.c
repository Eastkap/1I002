#include <stdio.h>
#define L1 'a'
#define L2 'b'

int verifTabEgaux(char tab1[], char tab2[],int taille){
	if(tab1[taille-1]==tab2[taille-1]){
		if(taille-1==0){
			return 1;
		}
		else{
			return verifTabEgaux(tab1,tab2,taille-1);
		}
	}
	else{
		return 0;
	}
}

int plusDeLettres1(char tab[],int taille, int l1,int l2){
	if(taille==0){
		if(l1>=l2){
			return 1;
		}
		return 0;
	}
	if(tab[taille-1]==L1){
		return plusDeLettres1(tab,taille-1,l1+1,l2);
	}
	else if(tab[taille-1]==L2){
		return plusDeLettres1(tab,taille-1,l1,l2+1);
	}
	return plusDeLettres1(tab,taille-1,l1,l2);
}

int palindrome(char tab1[],int taille, int indice){
	if(tab1[taille-1]=='\0'){
		return palindrome(tab1,taille-1,indice);
	}
	if(indice==taille-1){
		return 1;
	}
	if(tab1[indice]==tab1[taille-1]){
		return palindrome(tab1,taille-1,indice+1);
	}
	return 0;
}

int afficheTab(char tab[],int taille,int indice){
	if(indice==taille){
		return 0;
	}
	printf("%c",tab[indice]);
	return afficheTab(tab,taille,indice+1);
}

int mirroir(char tab[],int taille, int indice){
	if(taille-1==indice){
		return 1;
	}
	if(taille<=-1){
		return 1;
	}
	char temp=tab[taille-1];
	tab[taille-1]=tab[indice];
	tab[indice]=temp;
	return mirroir(tab,taille-2,indice+2);
}

int produitScalaire(int tab1[],int tab2[],int taille){
	if(taille==0){
		return 0;
	}
	else{
		return tab1[taille-1]*tab2[taille-1]+produitScalaire(tab1,tab2,taille-1);
	}
}


int main(){
	char tab1[]="abc";
	char tab2[]="abc";
	printf("%d\n",verifTabEgaux(tab1,tab2,4));
	printf("%d\n",plusDeLettres1(tab1,4,0,0));
	printf("%d\n",palindrome(tab1,4,0));
	afficheTab(tab1,4,0);
	printf("\n");
	mirroir(tab1,4,0);
	afficheTab(tab1,4,0);
	printf("\n");
	int t1[]={1,2,3};
	int t2[]={1,2,3};
	printf("%d\n",produitScalaire(t1,t2,3));
	return 0;
}
