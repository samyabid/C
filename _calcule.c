#include <stdio.h>
#include<stdlib.h>
#include "_operator.h"

int main(int argc , char** argv) {
    int num1,num2;
    num1 = atoi(*(argv + 2));
    num2 = atoi(*(argv + 3));
    char* op;
	op = argv[1];
    int add,sous,multip,sd,and,or,comp,divis;
	if (argc > 3){
		exit(0);
	}
    switch (*op) {
        case '+' :
            add = somme(num1 , num2);
            printf("La somme vaut %d\n",add);
            break;
            
        case '-' :
            sous = diff(num1 , num2);
            printf("La différence vaut %d\n",sous);
            break;
            
        case '*' :
            multip = mult(num1,num2);
            printf("Le produit vaut %d\n",multip);
            break;
            
        case '/' :
            divis = div(num1 ,num2);
            printf("La division vaut %d\n", divis);
            break;
            
        case '%' :
            sd = reste(num1 , num2);
            printf("Le reste vaut %d\n",sd);
            break;
            
        case '&' :
            and = et(num1 , num2);
            printf("Le ET vaut %d\n",and);
            break;
            
        case '|' :
            or = ou(num1 , num2);
            printf("Le OU vaut %d\n",or);
            break;
            
        case '~' :
            comp = neg(num1);
            printf("La négation vaut %d\n",comp);   
            break;
            
    }
    
	return 0;    
}
