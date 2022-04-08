#include <stdio.h>

#define euro_tl 6.17

int main() {
	
	float F;
	int z;
	float Y;
	
	printf("Fiyat: ");
	scanf("%f",&F);
	
	do {
		printf("Indirim yuzdesi: ");
		scanf("%d",&z);
	}
	while (z>99);
	
	Y = F - F*z/100;
	
	printf("Indirimli fiyat = %.2f\n",Y*euro_tl);
	
	system("pause");
	return 0;
}
