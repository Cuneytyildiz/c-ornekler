#include <stdio.h>
#define g 9.81

int main() {
	
	float h0, h;
	int t;
	
	printf("Kulenin yuksekligini girin: ");
	scanf("%f",&h0);
	
	h = h0;
	t = 0;
	
	while (h>0) {
		printf("%d\t%f\n",t,h);
		t++;
		h = h0 - 0.5*g*t*t;		
	}
	
	printf("NESNE YERE VURDU!\n");

	system("pause");
	return 0;
}
