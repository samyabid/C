#include <stdio.h>
#include <stdlib.h>
#include "_fichier.h"

char nom_du_fichier[150] = "salut.txt";
char message[150] = "mavie";
char* ptr_1 = nom_du_fichier;
char* ptr_2 = message;
int main(){
	ecrire_fichier(ptr_1,ptr_2);
	lire_fichier(ptr_1);
	


}

