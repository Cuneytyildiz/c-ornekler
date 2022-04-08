#include <stdio.h>

//Buyuk harfi kucuge, kucuk harfi buyuge cevirir.*/

int main(){
	
	char C;
	
	printf("Harf girin: ");
	scanf("%c", &C);
	
	if (C>='A' && C<='Z')
		printf("%c'nin kucugu %c'dir.\n", C, C + 'a' -'A');
	else if (C>='a' && C<='z')
		printf("%c'nin buyugu %c'dir.\n", C, C + 'A' -'a');
	else
		printf("Girdiginiz karakter harf degil...\n");
	
	system("pause");
	return 0;
}
