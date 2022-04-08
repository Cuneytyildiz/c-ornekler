#include <stdio.h>
#include <math.h>

/*Ikince derec denklemin gercek koklerini bulalim*/

int main(){
	
	float a, b, c, delta, kok1, kok2;
	
	printf("Ikinci derece denklamin katsayilarini girin: ");
	scanf("%f%f%f", &a, &b, &c);
	
	if (a == 0.0)
		printf("Denklem ikinci derece degil!\n");
	else {
		delta = b*b-4*a*c;
		if (delta < 0.0)
			printf("Gercek kok yok...\n");
		else
			if (delta > 0.0) {
				printf("Iki kok var...\n");
				kok1 = (-b+sqrt(delta))/(2*a);
				kok2 = (-b-sqrt(delta))/(2*a);
				printf("Kokler %f ve %f'dir.\n", kok1, kok2);
			}
			else {
				printf("Yalniz bir kok var...\n");
				kok1 = (-b)/(2*a);
				printf("Kok %f'dir.", kok1);
			}
		
	}
	
	system("pause");
	return 0;
}
