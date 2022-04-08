/*
10 d���ml� bir dairesel �ift ba�l� liste olsun.
Bu listede 0-9 aras� say�lar kar���k s�rada bulunmaktad�r.
�rnek : (9 5 2 4 7 6 3 0 1 8 )

Rastgele bir d���m s�ras� �retilerek
oyuncudan 0-9 aras�nda bir say� ve ileri-geri y�n bilgisi istenmektedir.
oyuncudan al�nan say�n�n belirtilen y�ndeki s�ral� 2 elemandan birisi olmas� 
durumunda oyuncu 1 puan kazan�r. Aksi takdirde 1 puan kaybeder. 
Ba�lang��ta oyuncunun 3 puan� vard�r. Puan 0 oldu�unda oyun sonlan�r.
Puan 10 oldu�unda oyun kazan�lm�� olur. 
Bu oyunu ger�ekleyecek program� yaz�n�z.
(NOT: D���m�n kendi verisi ileri y�n durumuna dahil edilecektir.)
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
	
	if(*head==NULL){ // Listede d���m yok ise
		*head = temp;
		(*head)->next=*head;
		(*head)->prev=*head;
	}
	else{ // Listede d���m var ise
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
	
	//�retilen  s�raya g�re listede ilerleme
	for (int i = 1; i < sira; i++)
	{
		list = list->next;

	}
	
	
	if (secim == 0) { //geri y�n durumu

		if (list->next->data == sayi || list->prev->prev->data == sayi)
			puan++;
		else
			puan--;

	}
	else //ileri y�n durumu
	{
		if (list->data == sayi || list->next->data == sayi || list->next->next->data == sayi)
			puan++;
		else
			puan--;
	}

	printf("\nPuan : %d\n",puan);

	
	
	return 0;
}

