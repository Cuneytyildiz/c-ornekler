#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	 char *girdi;
	 float sayi1, sayi2, sonuc;
	 char islem;
	 int i, j;
	 int hangi_sayi = 1;
	 
	 girdi = (char *)malloc(21*sizeof(char));
	 printf("Islem girin: \n");
	 gets(girdi);
	 
	 int uzunluk = strlen(girdi);
	 if (girdi[uzunluk-1] != '=') {
	 	printf("Hatali girdi\n");
	 	return -1;
	 }
	 
	 for (i=0;;) {
	 	if (hangi_sayi == 1) {
	 		sayi1 = girdi[i]-'0';
	 		for (i=1; girdi[i] >= '0' && girdi[i] <= '9'; i++)
	 			sayi1 = sayi1*10 + girdi[i] - '0';
	 		islem = girdi[i++];
	 		hangi_sayi = 2;
		 }
		 else {
		 	sayi2 = girdi[i]-'0';
		 	
	 		for (i = i+1; girdi[i] >= '0' && girdi[i] <= '9'; i++)
	 			sayi2 = sayi2*10 + girdi[i] - '0';
	 		
	 		switch (islem) {
	 			case '+':
	 				sayi1 = sayi1+sayi2;
	 				break;
	 			case '-':
	 				sayi1 = sayi1-sayi2;
	 				break;
	 			case '*':
	 				sayi1 = sayi1*sayi2;
	 				break;
	 			case '/':
	 				sayi1 = sayi1/sayi2;
	 				break;
	 			default:
	 				break;
			}

	 		if (i==uzunluk-1)
	 			break;
	 		else
	 			islem = girdi[i++];
		 }	 		
	}
	
	sonuc = sayi1;
	printf("%.2f\n",sonuc);
	
	system("pause");
	return 0;
}
