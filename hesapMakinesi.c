#include <stdio.h>
#define KUCUK 0.0000001

/* x islem y viciminde bir ifade girilecek
ve sonuc hesaplanip ekrana bastirilacak  */

int main(){

	float x, y, sonuc;
	char islec;
	
	printf("Islem girin: ");
	scanf("%f %c %f", &x, &islec, &y);
	
	if (islec == '+')
		sonuc = x + y;
	else if (islec == '-')
		sonuc = x - y;
	else if (islec == '*')
		sonuc = x * y;
	else if (islec == '/' && ((y - 0.0 >= KUCUK) || (y - 0.0 <= -1 * KUCUK)))
		sonuc = x / y;
	else {
		printf("Gecersiz islec...\n");
		system("pause");
		return 0;
	}
		
	printf("Islemin sonucu = %f.\n", sonuc);	
	system("pause");
	return 0;	
}
