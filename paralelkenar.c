#include <stdio.h>

int main() {
	
	int n,m;
	int i, j;
	
	printf("n gir:");
	scanf("%d", &n);
	printf("m gir:");
	scanf("%d", &m);
	
	for (i=0; i<m; i++)
		printf("*");
	printf("\n");
	
	for (i=1; i<n-1; i++) {
		for (j=0; j<i; j++)
			printf(" ");
		printf("*");
		for (j=0; j<m-2; j++)
			printf(" ");
		printf("*\n");
	}
	
	for (i=0; i<n-1; i++)
		printf(" ");
	for (i=0; i<m; i++)
		printf("*");
	printf("\n");
		
	system("pause");
	return 0;
}
