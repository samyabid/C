#include <stdio.h>
#include <stdlib.h>

void lire_fichier(char* nom_du_fichier){
	FILE* fichier = NULL;
	int caractere_actuel = 0;
	fichier = fopen(nom_du_fichier, "r");
	if (fichier != NULL) {
		do{
			caractere_actuel = fgetc(fichier);
			printf("%c", caractere_actuel);
		}
		while(caractere_actuel != EOF);
		fclose(fichier);
	}
	else{
		printf("Votre fichier n'existe pas");


}}
void ecrire_fichier(char* nom_du_fichier, char* message){
        FILE* fichier = NULL;
	int caractere_actuel = 0;
        fichier = fopen(nom_du_fichier, "a+");
        if (fichier != NULL){
                fputs(message, fichier);
				fputs(",", fichier);
				fputs(" ", fichier);
				fclose(fichier);

	}
        else{
                printf("Votre fichier n'existe pas");
        }}




