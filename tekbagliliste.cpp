#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int veri;
	struct dugum *sonraki;
};

int main(){
	struct dugum *ilk;
	ilk = (struct dugum *)malloc(sizeof(struct dugum));
	ilk -> veri = 10;
	
	ilk -> sonraki = (struct dugum *)malloc(sizeof(struct dugum));
	ilk -> sonraki -> veri = 20;
	
	struct dugum *iter;
	iter = ilk;
	printf("%d\n",iter->veri);
	
	iter = iter -> sonraki;
	printf("%d\n",iter->veri);
}


