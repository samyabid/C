#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// L'objectif est de chercher un element de type entier dans un tableau d'entier. 
int main(){
	// création du tableau de 100 entiers entre 0 et 100
	srand(time(NULL));
	int r,i,a,nombre;
	int RANDMAX = RAND_MAX/100;
	

	int tab[100];
	for (i=0;i<100;i++){
		r = rand()/RANDMAX;
		tab[i] = r;
		printf("%d \t",tab[i]);
	}

	//recherche du nombre donné par l'utilisateur dans le tableau
	printf("\nSaisissez un nombre entre 0 et 100 : ");
	scanf ("%d",&nombre);
	for (i=0;i<100;i++){
		a = tab[i];
		if (a == nombre){
			printf("\nL'entier %d est présent dans le tableau a l'indice %d\n\n",a,i);
	}
	}	
}
