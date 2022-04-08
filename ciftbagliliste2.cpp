#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *yenidugum(int deger){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data=deger;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}

void ekranaYaz(struct node *yaz){
	while(yaz->next!=NULL){
		printf("%d",yaz->data);
		yaz = yaz->next;
	}
}

struct node *basaekle(struct node *head,int deger){
	struct node *temp = yenidugum(deger);
	temp->next=head;
	head->prev=temp;
	head=temp;
	return head;
}

void basaekle2(struct node **head,int deger){
	struct node *temp=yenidugum(deger);
	temp->next= *head;
	(*head)->prev=temp;
	*head=temp;
}

void arayaekle(struct node *head,int deger){
	struct node *temp=yenidugum(deger);
	while(head->data!=7){
		head = head->next;
	}
	temp->next = head->next;
	head->next = temp;
	temp->prev = head;
	temp->next->prev=temp;
}

void sondansil(struct node *head){
	struct node *prev=NULL;
	while(head->next!=NULL){
		prev = head;
		head = head->next;
	}
	prev->next=NULL; // son elemanın bağlantısı kaldırıldı
	free(head);
}

void sonaekle(struct node *head,int deger){
	struct node *temp = yenidugum(deger);
	while(head->next!=NULL){
		head = head->next;
	}
	head->next=temp;
}

int main(){
	struct node *head = yenidugum(9);
	
	head = basaekle(head,7);
	basaekle2(&head,5);
	arayaekle(head,11);
	ekranaYaz(head);
}


