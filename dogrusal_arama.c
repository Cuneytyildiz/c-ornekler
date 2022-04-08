#include <stdio.h>
#include <stdlib.h>

int dogrusalArama(int A[], int boy, int sayi) {
	
	int i;
	
	for (i=0; i< boy; i++)
		if (A[i] == sayi)
			return i;
	
	return -1;
}

int main() {
	
	int *S, boy, sayi, i, bulunan_indeks;
	
	printf("Dizinin boyunu gir: ");
	scanf("%d",&boy);
	
	S = (int *)malloc(boy*sizeof(int));
	
	for (i=0; i<boy; i++) {
		S[i] = rand()%10;
		printf("%d ",S[i]);
	}
	printf("\n");
	
	printf("Aranan sayiyi girin: ");
	scanf("%d",&sayi);
	bulunan_indeks = dogrusalArama(S, boy, sayi);
	if (bulunan_indeks == -1)
		printf("%d bulunamadi\n",sayi);
	else
		printf("%d sayisi %d konumunda bulundu\n",sayi,bulunan_indeks);
	
	free(S);
	
	system("pause");
	return 0;	
}
