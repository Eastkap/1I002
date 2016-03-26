#include <stdio.h>

#define MAXCOMPTES 15

void afficheTab(float tab[], int taille) {
   int i;

   for (i = 0; i < taille; i++) {
      printf("%f  ", tab[i]);
   }
   printf("\n");
}

/* DEFINIR ICI LES FONCTIONS */
float moyenne(float comptes[MAXCOMPTES], int nbCl){
	int i;
	float moyenne=0;
	for(i=0;i<nbCl;i++){
		moyenne+=comptes[i];
	}
	moyenne=moyenne/nbCl;
	return moyenne;
}

int minPos(float comptes[MAXCOMPTES],int nbCl){
	int posmin=0, i=0;
	float min;
	do{
		min=comptes[i];
		i++;
	}while(min<0 && i<nbCl);
	if(i==nbCl-1){
		return -1;
	}
	for(i=i;i<nbCl;i++){
		if(comptes[i]>=0 && comptes[i]<min){
			posmin=i;
			min=comptes[i];
		}
	}
	return posmin;
}
	
int creerCompte(float comptes[MAXCOMPTES],int nbCl,int* nbClp, float m){
	if(nbCl<MAXCOMPTES-1){
		comptes[nbCl]=m;
	}
	else{
		return -1;
	}
	*nbClp+=1;
	return 0;
}

void remunere(float* comptes,int nbCl){
	int i=0;
	for(i=0;i<nbCl;i++){
		if(comptes[i]>0){
			comptes[i]=comptes[i]*1.05;
		}
	}
}

void consulte(float comptes[MAXCOMPTES], int i){
	printf("\n %f",comptes[i]);
}

void depotOuRetrait(int m, float* comptes, int i, int t, int autoris[MAXCOMPTES]){
	if(t==1){
		comptes[i]+=m;
	}
	else{
		if(comptes[i]-m<0){
			if(autoris[i]==1){
				comptes[i]=comptes[i]-m;
			}
		}
		else{
			comptes[i]=comptes[i]-m;
		}
	}
}
int depotOuRetrait2(int m, float* comptes, int i, int t, int autoris[MAXCOMPTES]){
	if(t==1){
		comptes[i]+=m;
		return 1;
	}
	else{
		if(comptes[i]-m<0){
			if(autoris[i]==1){
				comptes[i]=comptes[i]-m;
				return 1;
			}
			return 0;
		}
		else{
			comptes[i]=comptes[i]-m;
			return 1;
		}
	}
}

int main() {

   float comptes[MAXCOMPTES]={150.5, 160, 12, 1200, 655};
   int autoris[MAXCOMPTES]={1, 0, 1, 1, 0};
   int nbCl = 5;
   int choix, numC, saisieB;
   float saisie;
   int imin;
   int b;

   do {

      /* affichage du menu */
      printf("\n\t 0 : Quitter\n\n");
      printf("Operations sur les comptes : \n");
      printf("\t 1 : Moyenne des montants\n");
      printf("\t 2 : Minimum solde positif\n");
      printf("\t 3 : Creation d'un compte\n");
      printf("\t 4 : Remuneration des comptes\n\n");
      printf("Operations sur UN compte\n");
      printf("\t 5 : Consultation du solde\n");
      printf("\t 6 : Depot ou retrait\n");
      
      scanf("%d", &choix);

      if (choix !=0) { 
         /* affichage des comptes */
         afficheTab(comptes, nbCl);
         
         /* Il faut effectuer l'operation */
         switch (choix) {

            case 1 :
               /* affichage de la moyenne des montants */
               printf("Moyenne des comptes : %f\n", moyenne(comptes,nbCl));
               break;

            case 2 :
               /* affichage du numero du client ayant le plus petit solde positif 
                  et solde de son compte */
               imin = minPos(comptes,nbCl);
               if (comptes[imin]<0) {
                  printf("Tous les comptes sont a decouvert\n");  
               }
               else {
                  printf("Le client ayant le solde positif minimum est %d", imin);
                  printf(", il dispose de %f euros\n", comptes[imin]);
               }
               break;

            case 3 :
               /* Saisie d'un nouveau compte client */
               printf("Veuillez saisir le montant du nouveau compte : \n");
               scanf("%f", &saisie);
               
               /* ajout de ce compte */
               int a=creerCompte(comptes,nbCl,&nbCl,saisie);

               if (a == -1) {
                  printf("erreur, trop de comptes");
               }
               else {
                  printf("Comptes apres creation : \n");
                  afficheTab(comptes, nbCl);
               }
               break;

            case 4 :
               /* Remuneration des comptes */
               remunere(comptes,nbCl);
               afficheTab(comptes, nbCl);
               break;

            case 5 :
               /* Consultation du solde */
               printf("Veuillez saisir votre numero de compte : \n");
               scanf("%d", &numC);

               if (numC < nbCl) { /* le numero de compte doit etre valide */
                  printf("vous disposez de %f euros\n", comptes[numC]);
               }
               break;

            case 6 :
               /* Realisation d'un virement ou d'un retrait */
               printf("Veuillez saisir votre numero de compte : \n");
               scanf("%d", &numC);
               
               printf("veuillez saisir le montant : \n");
               scanf("%f", &saisie);
               
               printf("1 : depot\n2 : retrait\n");
               scanf("%d", &saisieB);


               if (numC < nbCl) { /* le numero de compte doit etre valide */
                  b = depotOuRetrait2(saisie,comptes,numC,saisieB,autoris);
                  if (b) {
                     printf("L'operation a ete correctement effectuee\n");
                  } 
                  else {
                     printf("L'operation a echoue");
                  }
               }
               afficheTab(comptes, nbCl);
               break;
         }
      }
      
   } while (choix !=0);
   
   printf("Au revoir\n");
   return 0;
}
