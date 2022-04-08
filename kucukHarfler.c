#include <stdio.h>

int main(){
	
	const char sonDeger = '*';
	char c;
	int sayac = 0;
	
	printf("Karakterleri teker teker girin: ");
	scanf("%c",&c);
	while (c!='*') {
		if (c >= 'a' && c<='z')
			sayac++;
		scanf("%c",&c);
	}
	
	printf("Kucuk harflerin sayisi: %d\n",sayac);
	
	system("pause");
	return 0;
}
