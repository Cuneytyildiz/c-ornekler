/*
20 adet tam sayý, iki tane doðrusal liste yardýmýyla saklanacaktýr. 
Birinci liste tek sayýlarý, ikinci liste çift sayýlarý tutmaktadýr. 
5 kez atýlan bozuk para ile tura gelirse tek sayýlardan, yazý gelirse çift sayýlardan sondan silme yapýlmaktadýr. 
En son olarak listeler ekranda görüntülenmektedir. Bu problemi gerçekleyen kodu yazýnýz.
*/

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

struct node *ekranaYaz(struct node *yaz){
	while(yaz!=NULL){
		printf(" %d ",yaz->data);
		yaz=yaz->next;
	}
}

struct node *basaekle(struct node *head,int deger){
	struct node *temp=yenidugum(deger);
	temp->next=head;
	head=temp;
	return head;
}

struct node **basaekle(struct node **head,int deger){
	struct node *temp=yenidugum(deger);
	temp->next=*head;
	*head=temp;
}

void arayaekle(struct node *head,int deger){
	struct node *temp = yenidugum(deger);
	while(head->data!=7){
		head=head->next;
	}
	temp->next=head->next;
	head->next=temp;
}

void sonaekle(struct node *head,int deger){
	struct node *temp=yenidugum(deger);
	
	while(head->next!=NULL){
		head=head->next;
	}
	head->next=temp;
}

void sondansil(struct node *head){
	struct node *prev=NULL;
	while(head->next!=NULL){
		prev=head;
		head=head->next;
	}
	prev->next=NULL; // son eleman ile baðlantý kesildi
	free(head); // son eleman bellekten silindi
}

int main(){
	//listelerin ilk elemanlarý eklenmiþtir.
	//bundan dolayý listenin NULL olma durumu kontrol edilmemiþtir.
	
	struct node *tekhead=yenidugum(1),*cifthead=yenidugum(2);
	
	for(int i=0;i<8;i++){ // ilk 2 eleman girildiði için toplam 8 elemana ihtiyaç var
		int sayi = rand()%20; //sayýlar rastgele olarak üretildi
		
		if(sayi%2==0)//çift listeye ekle
			sonaekle(cifthead,sayi);
		else //tek listeye ekle
			sonaekle(tekhead,sayi);
	}
	//listelerin oluþturulmuþ hali yazdýrýlýyor
	printf("Listelerin ilk hali : \n");
	printf("\tTek Liste --> ");
	ekranaYaz(tekhead);
	printf("\n\tCift Liste --> ");
	ekranaYaz(cifthead);
	printf("\n\n");
	
	for(int i=0;i<5;i++){ // 5 kez yazý-tura atýlma durumu
		int yazitura = rand()%2; // 0 tura ; 1 yazý
		
		if (yazitura==0){ //tek listeden sil
			sondansil(tekhead);
			printf("Tek Listeden Eleman Silindi\n");
		}
		else{
			sondansil(cifthead);
			printf("Cift Listeden Eleman Silindi\n");
		}
	}
	
	//Listelerin yazý tura atýldýktan sonraki eleman silinmiþ hali yazdýrýlýyor
	printf("\nListelerin son hali : \n");
	printf("\tTek Liste --> ");
	ekranaYaz(tekhead);
	printf("\n\tCift Liste --> ");
	ekranaYaz(cifthead);
	

	return 0;
	
}

