#include <stdio.h>
#include<string.h>
//L'objectif  de cet  exercice est  de manipuler la notion de structure et de compter le nombre d'elements similaires dans une structure

int main(){
    struct Couleur {  // creation de la structure  
        char rouge[50];
        char vert[50];
        char bleu[50];
        char  alpha[50]; 
        int c;
    };
    struct Couleur  couleur1 = {"0xab","Oxbc","Oxad","Oxff",0}; //creation d'un objet  couleur de type structure  
    struct Couleur  couleur2 = {"0xab","Oxbc","Oxad","Oxff",0};
    struct Couleur  couleur3 = {"0xab","Oxbc","Oxad","Oxff",0};
    struct Couleur  couleur4 = {"0xab","Oxbc","Oxad","Oxff",0};
    struct Couleur  couleur5 = {"0xab","Oxbc","Oxad","Oxff",0};
    struct Couleur  couleur6 = {"0xab","Oxbc","Oxad","Oxff",0};
    struct Couleur  couleur7 = {"0xab","Oxbc","Oxad","Oxff",0};
    struct Couleur  couleur8 = {"0xab","Oxbc","Oxad","Oxff",0};
    struct Couleur  couleur9 = {"0xab","Oxbc","Oxad","Oxff",0};
    struct Couleur  couleur10 = {"0xab","Oxbc","Oxad","Oxff",0};






struct Couleur table[] = {couleur1,couleur2,couleur3,couleur4,couleur5,couleur6,couleur7,couleur8,couleur9,couleur10};
// creation d'une liste d'objets de type structure

    int i,j,k;
    for(i=0;i<10;i++){
        for(j=i+1 ; j<10 ;j++){
            if((table[i].rouge == table[j].rouge) && (table[i].bleu == table[j].bleu) && (table[i].vert == table[j].vert) && (table[i].alpha == table[j].alpha)){
                table[i].c++; // on modifie la valeur de c
                strcpy(table[i].bleu, "Dupont");
            }
        }
    }
    
    
    for (k=0;k<10;k++){ //on parcourt toutes les couleurs
        if (strcmp( table[k].bleu, "Dupont" )){ //On s'interesse uniquement aux couleurs distinctes 
            printf("%s %s %s %s %d\n",table[k].rouge,table[k].vert,table[k].bleu,table[k].alpha,table[k].c); //on affiche toutes les couleurs
        }

}
}
