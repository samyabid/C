#include <stdio.h>
#include "string.h"

int main (){
	int i;
	int* iptr1 = &i;
	int** iptr2 = &iptr1;
	char c;
	char* cptr1 = &c;
	char** cptr2 = &cptr1;
	float f;
	float* fptr1 = &f;
	float** fptr2 = &fptr1;
	char message[] = "Taric";
	char* ptr_c = message;
	printf("%ld \n",sizeof(i));
	printf("%ld \n",sizeof(message));
	printf("%lu \n",strlen(ptr_c));
	printf("%ld \n",sizeof(iptr2));
	printf("%ld \n",sizeof(c));
	printf("%ld \n",sizeof(cptr1));
	printf("%ld \n",sizeof(cptr2));
	printf("%ld \n",sizeof(f));
	printf("%ld \n",sizeof(fptr1));
	printf("%ld \n",sizeof(fptr2));

	char a = '3';
	int b = a - 48 ;
	printf("%d",b);
}
