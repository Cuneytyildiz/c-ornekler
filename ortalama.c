#include <stdio.h>

int main(){

	int i = 1, n;
	float sayi, ort = 0.0;
	
	printf("Sayilarin sayisini girin: ");
	scanf("%d",&n);
	
	while (i<=n) {
		printf("Siradaki sayiyi girin: ");
		scanf("%f",&sayi);
		ort += sayi;
		i++;
	}
	
	if (n>0) {
		ort /= n;
		printf("Ortalama: %.2f\n", ort);
	}
	else
		printf("Sayilarin sayisi 0'dan buyuk olmali.\n");

	system("pause");
	return 0;
}

