#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// l'objectif est de determiner le plus grand et le plus petit element d'une liste
int main(){
	srand(time(NULL));
	int r,i;
	int RANDMAX = RAND_MAX/100;
	

	int tab[100];
	for (i=0;i<100;i++){
		r = rand()/RANDMAX;
		tab[i] = r;
		printf("%d \t",tab[i]);
	}
	
	int max = tab[0],j;
	for (j=0;j<100;j++) {
		if (tab[j]>max){
			max = tab[j];
		}
	}
	printf(" Le numéro le plus grand est : %d \n",max);
	
	int min = tab[0],k;
	for (k=0;k<100;k++) {
		if (tab[k]<min){
			min = tab[k];
		}
	}
	printf("Le numéro le plus petit est : %d \n",min);
}
