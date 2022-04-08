#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};


void ekranaYaz(struct node *yaz){
	while(yaz!=NULL){
		printf("%d\n",yaz->data);
		yaz=yaz->next;
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

void basaekle(struct node *ekle,int x){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=ekle;
	
	ekle=temp;
};


int main(){
	struct node *head;
	head=(struct node *)malloc(sizeof(struct node));
	head->data=0;
	head->next=NULL;
	
	int secim,sayi;
	while(1){
		printf("1.Sona Ekle\n2.Basa Ekle\n3.Listele\n4.Cikis\nSeciminiz :");
		scanf("%d",&secim);
		
		if(secim==1){
			printf("Eklenilecek Sayi: ");
			scanf("%d",&sayi);
			sonaekle(head,sayi);
		}
		
		else if(secim==2){
			printf("Eklenilecek Sayi: ");
			scanf("%d",&sayi);
			basaekle(head,sayi);
		}
		
		else if(secim==3){
			ekranaYaz(head);
		}
		else if(secim==4){
			return 0;
		}
	}
}
