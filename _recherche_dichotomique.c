#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// L'objectif est d'appliquer la recherche dichotomique dans une liste d'elements 
int main(){
	//création du tableau de 100 entiers
	srand(time(NULL));
	int r,i;
	int RANDMAX = RAND_MAX/100;
	

	int tab[100];
	for (i=0;i<100;i++){
		r = rand()/RANDMAX;
		tab[i] = r;
		printf("%d \t",tab[i]);
	}
	
	//tri
	int j,k,varact;
	for (j=0;j<100;j++) { 
		for (k=j+1;k<100;k++){
			if (tab[j]>tab[k]){
				varact = tab[j];
				tab[j] = tab[k];
				tab[k] = varact;
			}
		}
	}
	//Affichage du taleau trié
	printf("\n\n\n\n\n\n\n\n\n");
	int l;
	for(l=0;l<100;l++){
		printf("%d \t",tab[l]);
	}

	//tri dichotomique	le principe etant de diviser a chaque la longeur de la chaine en 2 et de s'interesse au milieu a chaque fois.
	printf("Valeur à chercher = ");
	int nombre,mid;
	int inf = 0, sup = 99, o = -1;
	scanf("%d",&nombre);

	while ((inf <= sup)&&(o ==-1))
		{
		mid = (inf+sup)/2;
		if (nombre < tab[mid])
			sup = mid-1;
		
		else if (nombre > tab[mid])
			inf = mid+1;
		
		else 
			o = mid;	

		}
	if (o == -1)
		printf("La valeur recherchée ne se trouve pas dans le tableau. \n");
	else
		printf("La dernière valeur du numéro %d se trouve à la position %d. \n",nombre,o);
	return 0;
}
