#include <stdio.h>

int main() {
	char secim;
	float a;
	
	do {
		printf("Kenar uzunlugunu girin: ");
		scanf("%f",&a);
		printf("Alan: %f\n",a*a);
		printf("Sonlandirmak icin q/Q girin...\n");
		printf("Surdurmek icin herhangi baska bir tus girin...\n");
		scanf("\n%c",&secim);
	}while (secim!='q' && secim!='Q')
;	
	system("pause");
	return 0;
}
