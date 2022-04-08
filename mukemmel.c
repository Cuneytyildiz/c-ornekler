#include <stdio.h>

int main(){
	
	int sayi, i, toplam = 0;
	
	printf("Sayi girin: ");
	scanf("%d",&sayi);
	
	for (i=1; i<=sayi/2; i++)
		if (sayi % i == 0)
			toplam += i;
	
	if (sayi == toplam)
		printf("%d mukemmel sayidir.\n", sayi);
	else
		printf("%d mukemmel sayi degildir.\n", sayi);
	
	system("pause");
	return 0;
}
