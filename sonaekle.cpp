#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void ekranaYaz(struct node *yaz){
	while(yaz!=NULL){
		printf("%d\n",yaz->data);
		yaz = yaz->next;
	}
};

void sonaekle(struct node *ekle,int x){
	while(ekle->next!=NULL){
		ekle = ekle->next;		
	}
	ekle->next=(struct node *)malloc(sizeof(struct node));
	ekle->next->data=x;
	ekle->next->next=NULL;
};





int main(){
	struct node *head;
	head=(struct node *)malloc(sizeof(struct node));
	head->data=0;
	head->next=NULL;
	
	int anahtar=1,secim,sayi;
	while(anahtar==1){
		printf("1.Sayi Ekle\n2.Listele\n3.Cikis\nSeciminiz:");
		scanf("%d",&secim);
		
		if(secim==1){
			printf("Eklenilecek Sayi: ");
			scanf("%d",&sayi);
			sonaekle(head,sayi);
		}
		else if(secim==2){
			ekranaYaz(head);
		}
		else if(secim==3){
			printf("Çikis Yapildi...");
			anahtar=0;
		}
		else{
			printf("Hatali Secim !!!");
		}
		
	}
}
