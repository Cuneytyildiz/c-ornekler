#include <stdio.h>

int main() {
	int puan;
	char harf;
	printf("Puaninizi girin: ");
	scanf("%d",&puan);
	
	if (puan > 100 || puan < 0)
		printf("Gecersiz not...\n");
	else {
		switch (puan/10) {
			case 10: case 9:
				harf = 'A';
				break;
			case 8:
				harf = 'B';
				break;
			case 7:
				harf = 'C';
				break;
			case 6:
				harf = 'D';
				break;
			default:
				harf = 'F';
				break;
		}
		printf("Harf notunuz: %c\n", harf);
	}
	system("pause");
	return 0;
}
