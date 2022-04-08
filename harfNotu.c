#include <stdio.h>

int main() {
	
	int puan;
	char harf;
	printf("Puan giriniz: ");
	scanf("%d", &puan);
	
	if (puan > 100 || puan < 0)
		printf("Gercersiz puan!\n");
	else {
		if (puan >= 90)
			harf = 'A';
		else if (puan >= 80)
			harf = 'B';
		else if (puan >= 70)
			harf = 'C';
		else if (puan >= 60)
			harf = 'D';
		else
			harf = 'F';
			
		printf("Harf notunuz: %c\n", harf);
	}
	
	system("pause");	
	return 0;
}
