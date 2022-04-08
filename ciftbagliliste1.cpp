#include <stdio.h>
#include <stdlib.h>


typedef struct Dugum { // D = struct Dugum
	char *veri;
	struct Dugum *sonraki;
	struct Dugum *onceki;
}D;

D *YeniDugum(char deger[]) {
	D* temp = (D *)malloc(sizeof(D));
	temp->veri = deger;
	temp->sonraki = NULL;
	temp->onceki = NULL;
	return temp;
}



void ListeYazdir(D* head) {
	while (head != NULL) {
		printf("%s ", head->veri);
		head = head->sonraki;
	}
}


void ArayaEkle(D* head, char *deger) {
	D* temp = YeniDugum(deger);
	while (head->veri != "\\") {
		head = head->sonraki;
	}
	head->onceki->sonraki = temp;
	temp->onceki = head->onceki;
	head->onceki = temp;
	temp->sonraki = head;
}

void Sil(D* head,char *SilinecekVeri) {
	
	while (head->veri != SilinecekVeri) {		
		head = head->sonraki;
	}
	head->onceki->sonraki = head->sonraki; 
	head->sonraki->onceki = head->onceki;
	free(head);
}



int main() {
	D *head = YeniDugum("-");
	head->sonraki = YeniDugum("\\");
	head->sonraki->onceki = head;
	
	ListeYazdir(head);
	ArayaEkle(head, "Zonguldak");
	printf("\n");
	ListeYazdir(head);
	ArayaEkle(head, "Karabuk");
	printf("\n");
	ListeYazdir(head);
	Sil(head, "Karabuk");
	printf("\n");
	ListeYazdir(head);

	return 0;
}
