#include <stdio.h>

/*Uc tamsayinin ortalamasini, en kucugunu ve en buyugunu hesapla ve bastir */

int main(){
	int a, b, c;
	int min, max;
	printf("Uc sayi girin: ");
	scanf("%d%d%d", &a, &b, &c);
	printf("Ortalama: %f\n", (a + b + c)/3.0);
	
	if (a < b) {
		min = a;
		max = b;
	}
	else {
		min = b;
		max = a;
	}
	if (c < min)
		min = c;
	else if (c > max)
		max = c;
		
	printf("En kucuk sayi: %d\n", min);
	printf("En buyuk sayi: %d\n", max);
	
	system("pause");
	return 0;
}
