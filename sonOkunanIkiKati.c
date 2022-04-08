#include <stdio.h>

int main(){
	
	int sayi, onceki, sayac = 1;
	float ort;
	
	printf("Bir sayi girin: ");
	scanf("%d",&sayi);
	
	ort = onceki = sayi;
	
	while (sayi != 2*onceki) {
		onceki = sayi;
		printf("Bir sayi girin: ");
		scanf("%d",&sayi);
		ort += sayi;
		sayac++;
	}
	
	ort /= sayac;
	printf("Ortalama: %.2f\n", ort);
	
	system("pause");
	return 0;
}
