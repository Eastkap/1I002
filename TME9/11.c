#include <stdio.h>

int affiche_inverse(char tabCar[]){
	if(tabCar[0]!='\0'){
		printf("%c",tabCar[0]);
		return affiche_inverse(tabCar);
	}
	return 0;
}

int main(){
	char tab[]="abc";
	affiche_inverse(tab);
	return 0;
}
