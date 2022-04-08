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

int ikiliArama(int *A, int boy, int sayi) {
	
	int alt = 0, ust = boy-1, orta;
	
	while (alt <= ust) {
		orta = (alt + ust)/2;
		if (A[orta] == sayi)
			return orta;
		if (A[orta] < sayi)
			alt = orta + 1;
		else
			ust = orta - 1;
	}
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
	
	dizi_sirala(S,boy);
	
	for (i=0; i<boy; i++)
		printf("%d ",S[i]);
	printf("\n");
	
	printf("Aranan sayiyi girin: ");
	scanf("%d",&sayi);
	bulunan_indeks = ikiliArama(S, boy, sayi);
	if (bulunan_indeks == -1)
		printf("%d bulunamadi\n",sayi);
	else
		printf("%d sayisi %d konumunda bulundu\n",sayi,bulunan_indeks);
	
	free(S);
	
	system("pause");
	return 0;	
}
