#include <stdio.h>

int main() {
	
	char c;
	long sayi = 0;
	int gecersiz = 0;
	
	printf("Bir tamsayi girin: ");
	
	c = getchar();
	
	while (c!=' ' && c!='\n' && c!='\t') {
		gecersiz = 0;
		if (c >= '9' || c <='0') {
			gecersiz = 1;
			break;
		}
		sayi = sayi*10+c-'0';
		c = getchar();
	}
	
	if (gecersiz)
		printf("Girilen sayi gecersiz bir tamsayidir.\n");
	else
		printf("Girdiginiz sayi: %ld\n", sayi);
	
	system("pause");
	return 0;
}
