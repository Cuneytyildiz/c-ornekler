#include <stdio.h>
#define PI 3.14

/* Secilen kare (k,K), dikdortgen (d,D) veya cember (c,C) geometrik sekillerinden birinin
alanini hesaplar ve ekrana yazdirir. */

int main() {
	char secim;
	float a, b, alan;
	printf("Seciminizi girin: ");
	scanf("%c", &secim);
	
	switch(secim) {
		case 'k': case 'K':
			printf("Kenar boyunu girin: ");
			scanf("%f",&a);
			alan = a * a;
			printf("Karenin alani: %.4f\n", alan);
			break;
		case 'd': case 'D':
			printf("Kenar boylarini girin: ");
			scanf("%f%f",&a,&b);
			alan = a * b;
			printf("Dikdortgenin alani: %.4f\n", alan);
			break;
		case 'c': case 'C':
			printf("Yaricapi girin: ");
			scanf("%f",&a);
			alan = PI * a * a;
			printf("Cemberin alani: %.4f\n", alan);
			break;
		default:
			printf("Gecersiz secim\n");
			break;		
	}
	system("pause");
	return 0;
	
}
