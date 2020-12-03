#include <stdio.h>
#include<string.h>
#include "_fichier.h"
int main(){
 int i,j;
 char nom_du_fichier[150] = "test1.txt";
 for(i=0;i<2;i++){
     for(j=0;j<5;j++){

         if (j == 0){
             char prenom[150];
             char* ptr0 = prenom;
             printf("Saisir un prenom \t"); 
             gets(prenom);
             ecrire_fichier(nom_du_fichier, prenom);
             }
        if (j == 1){
             char nom[150];
             char* ptr1 = nom;
             printf("Saisir un nom \t"); 
             gets(nom);
             ecrire_fichier(nom_du_fichier, ptr1);

             }
        if (j == 2){
             char adresse[150];
             char* ptr2 = adresse;
             printf("Saisir une adresse \t"); 
             gets(adresse);
             FILE* fichier = NULL;
             ecrire_fichier(nom_du_fichier, ptr2);
             }
        if (j == 3){
             char note_c[2];
             char* ptr3 = note_c;
             printf("Saisir une note \t"); 
             gets(note_c);
             ecrire_fichier(nom_du_fichier, ptr3);
             }

        if (j == 4){
             char note_s[2];
             printf("Saisir une note \t"); 
             gets(note_s);
             ecrire_fichier(nom_du_fichier, note_s);
             FILE* fichier = NULL;
             fichier = fopen(nom_du_fichier, "a");
             fprintf(fichier, "\n");
             fclose(fichier);
             }
        
                
     }
    
 }
 
}