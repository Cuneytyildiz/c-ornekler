#include <stdio.h>

int main() {
	
	int sayi, i;
	long fakt = 1;
	
	printf("Sayi girin: ");
	scanf("%d",&sayi);
	
	for (i=2; i<=sayi; i++)
		fakt *=i;
	
	if (sayi>=0) 
		printf("Faktoriyel: %ld\n",fakt);
	else
		printf("Negatif sayi girildi...\n");
	
	system("pause");
	return 0;
}
