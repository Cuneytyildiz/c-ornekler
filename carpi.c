#include <stdio.h>

int main() {
	
	int n;
	int i, j;
	
	do {
		printf("Gir: ");
		scanf("%d",&n);
	}
	while (n<1);
	
	for (i=0; i<n; i++) {
		for (j=0; j<i; j++)
			printf(" ");
		printf("*");
		for (j=0; j<2*(n-i)-1; j++)
			printf(" ");
		printf("*");
		printf("\n");
	}
	
	for (i=0; i<n; i++)
		printf(" ");
	printf("*\n");
	
	for (i=0; i<n; i++) {
		for (j = 0; j<n-i-1; j++)
			printf(" ");
		printf("*");
		for (j=0; j < 2*i+1; j++)
			printf(" ");
		printf("*\n");
	}	
		
	system("pause");
	return 0;
}
