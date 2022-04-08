#include <stdio.h>

int main(){
	
	int satir, i, j;
	
	printf("Satir sayisini girin: ");
	scanf("%d",&satir);
	
	for (i=1; i<=satir; i++) {
		for (j=0; j<satir-i; j++)
			printf(" ");
		for (j=0; j<i*2-1; j++)
			printf("*");
		printf("\n");
	}
	
	system("pause");
	return 0;
}
