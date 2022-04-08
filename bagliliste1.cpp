#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *yenidugum(int deger){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=deger;
	temp->next=NULL;
	return temp;
}

void ekranaYaz(struct node *yaz){
	while(yaz!=NULL){
		printf("%d",yaz->data);
		yaz = yaz->next;
	}
}

struct node *basaekle(struct node *head,int deger){
	struct node *temp=yenidugum(deger);
	temp->next=head;
	head=temp;
	return head;
}

void arayaekle(struct node *head,int deger){
	struct node *temp = yenidugum(deger);
	while(head->data!=7){ // 7 verisinden sonra ekliyecek
	head = head->next;
	}
	temp->next = head->next;
	head->next = temp;
}

int main(){
	struct node *head,*ikinci,*ucuncu;
	head=yenidugum(5);
	ikinci=yenidugum(7);
	ucuncu=yenidugum(9);
	head->next=ikinci;
	ikinci->next=ucuncu;
	ekranaYaz(head);
	printf("\n");
	head = basaekle(head,12);
	ekranaYaz(head);
	printf("\n");
	arayaekle(head,67);
	ekranaYaz(head);
}
