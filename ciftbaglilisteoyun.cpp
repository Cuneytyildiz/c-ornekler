/*
10 düðümlü bir dairesel çift baðlý liste olsun.
Bu listede 0-9 arasý sayýlar karýþýk sýrada bulunmaktadýr.
Örnek : (9 5 2 4 7 6 3 0 1 8 )

Rastgele bir düðüm sýrasý üretilerek
oyuncudan 0-9 arasýnda bir sayý ve ileri-geri yön bilgisi istenmektedir.
oyuncudan alýnan sayýnýn belirtilen yöndeki sýralý 2 elemandan birisi olmasý 
durumunda oyuncu 1 puan kazanýr. Aksi takdirde 1 puan kaybeder. 
Baþlangýçta oyuncunun 3 puaný vardýr. Puan 0 olduðunda oyun sonlanýr.
Puan 10 olduðunda oyun kazanýlmýþ olur. 
Bu oyunu gerçekleyecek programý yazýnýz.
(NOT: Düðümün kendi verisi ileri yön durumuna dahil edilecektir.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *yenidugum(int deger){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=deger;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}

void listeyazdir(struct node *head){
	struct node *list = head;
	
	while(list->next!=head){
		printf("%d",list->data);
		list=list->next;
	}
	printf("%d",list->data);
}


void ekle(struct node **head,int deger){
	struct node *temp =yenidugum(deger);
	
	if(*head==NULL){ // Listede düðüm yok ise
		*head = temp;
		(*head)->next=*head;
		(*head)->prev=*head;
	}
	else{ // Listede düðüm var ise
		struct node *list = *head;
		while(list->next!=*head){
			list = list->next;
		}
		list->next=temp;
		temp->prev=*head;
		temp->next=list;
		(*head)->prev=temp;
	}
}

int main(){
	struct node *head=NULL,*list=NULL;
	srand(time(NULL));
	
	ekle(&head,9);
	ekle(&head,5);
	ekle(&head,2);
	ekle(&head,4);
	ekle(&head,7);
	ekle(&head,6);
	ekle(&head,3);
	ekle(&head,0);
	ekle(&head,1);
	ekle(&head,8);
	
	listeyazdir(head);
	list = head;
	
	int sayi,secim,sira = rand()%10+1;
	int puan = 3;
	
	printf("\nSayi Giriniz :");
	scanf("%d",&sayi);
	printf("Yon bilgisi giriniz (0 geri 1 ileri) : ");
	scanf("%d", &secim);
	
	//üretilen  sýraya göre listede ilerleme
	for (int i = 1; i < sira; i++)
	{
		list = list->next;

	}
	
	
	if (secim == 0) { //geri yön durumu

		if (list->next->data == sayi || list->prev->prev->data == sayi)
			puan++;
		else
			puan--;

	}
	else //ileri yön durumu
	{
		if (list->data == sayi || list->next->data == sayi || list->next->next->data == sayi)
			puan++;
		else
			puan--;
	}

	printf("\nPuan : %d\n",puan);

	
	
	return 0;
}

