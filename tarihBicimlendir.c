#include <stdio.h>

int main(){
	
	int gun, ay, yil;
	
	printf("Gun, ay ve yil gir: ");
	scanf("%d%d%d",&gun,&ay,&yil);
	
	if (ay<1 || ay > 12) {
		printf("Gecersiz ay..\n");
		system("pause");
		return 0;
	}
	
	switch(ay) {
		case 4: case 6: case 9: case 11:
			if (gun>30) {
				printf("Gecersiz gun...\n");
				system("pause");
				return 0;
			}
			break;
		case 2:
			if (((yil%4 != 0) || ((yil%100 == 0) && (yil % 400 != 0))) && gun>28) {
				printf("Gecersiz gun...\n");
				system("pause");
				return 0;
			}
			else if ((((yil%4 == 0) && (yil%100 != 0)) || (yil%400 == 0)) && gun>29)  {
				printf("Gecersiz gun...\n");
				system("pause");
				return 0;
			}
			break;
		default:
			if (gun>31) {
				printf("Gecersiz gun...\n");
				system("pause");
				return 0;
			}
			break;
	}
	
	printf("%d/",gun);
	switch(ay) {
		case 1: printf("Ocak/"); break;
		case 2: printf("Subat/"); break;
		case 3: printf("Mart/"); break;
		case 4: printf("Nisan/"); break;
		case 5: printf("Mayis/"); break;
		case 6: printf("Haziran/"); break;
		case 7: printf("Temmuz/"); break;
		case 8: printf("Agustos/"); break;
		case 9: printf("Eylul/"); break;
		case 10: printf("Ekim/"); break;
		case 11: printf("Kasim/"); break;
		case 12: printf("Aralik/"); break;
		default: break;
	}
	printf("%d\n",yil);
	
	
	system("pause");
	return 0;
}
