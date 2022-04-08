#include <stdio.h>
#include <stdlib.h>

void kdegistir(int *a, int *b) {
	
	int gecici;
	
	gecici = *a;
	*a = *b;
	*b = gecici;
}

void dizi_sirala(int *D, int boy) {
	
	int i, j, gecici;
	
	for (i = 0; i<boy; i++)
		for (j = i+1; j < boy; j++)
			if (D[i] > D[j])
				kdegistir(&D[i], &D[j]);
}

int main() {
	
	int *S, boy, i;
	
	printf("Dizinin boyunu gir: ");
	scanf("%d",&boy);
	
	S = (int *)malloc(boy*sizeof(int));
	
	for (i=0; i<boy; i++) {
		S[i] = rand()%10;
		printf("%d ",S[i]);
	}
	printf("\n");
	
	dizi_sirala(S,boy);
	
	for (i=0; i<boy; i++)
		printf("%d ",S[i]);
	printf("\n");
	
	free(S);
	
	system("pause");
	return 0;
		
}
