#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	
}
