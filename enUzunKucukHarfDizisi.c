#include <stdio.h>

int main() {
	
	char simdiki, onceki, enuzun;
	int enBuyukUzunluk = 0, simdikiUzunluk = 0;
	
	printf("! ile biten karakter dizisini girin: ");
	scanf("%c", &simdiki);
	onceki = simdiki;
	
	while (onceki != '!') {
		if (onceki == simdiki)
			simdikiUzunluk++;
		else {
			if (simdikiUzunluk > enBuyukUzunluk && onceki >='a' && onceki <='z') {
				enuzun = onceki;
				enBuyukUzunluk = simdikiUzunluk;
			}
			simdikiUzunluk = 1;
		}
		onceki = simdiki;
		scanf("%c",&simdiki);
	}
	
	if (enBuyukUzunluk > 0)
		printf("%c karakteri %d kere art arda var.\n", enuzun,enBuyukUzunluk);
	else
		printf("Hic kucuk harf yok\n");
		
	system("pause");
	return 0;
}
