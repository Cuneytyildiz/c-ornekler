/*
20 adet tam say�, iki tane do�rusal liste yard�m�yla saklanacakt�r. 
Birinci liste tek say�lar�, ikinci liste �ift say�lar� tutmaktad�r. 
5 kez at�lan bozuk para ile tura gelirse tek say�lardan, yaz� gelirse �ift say�lardan sondan silme yap�lmaktad�r. 
En son olarak listeler ekranda g�r�nt�lenmektedir. Bu problemi ger�ekleyen kodu yaz�n�z.
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
	prev->next=NULL; // son eleman ile ba�lant� kesildi
	free(head); // son eleman bellekten silindi
}

int main(){
	//listelerin ilk elemanlar� eklenmi�tir.
	//bundan dolay� listenin NULL olma durumu kontrol edilmemi�tir.
	
	struct node *tekhead=yenidugum(1),*cifthead=yenidugum(2);
	
	for(int i=0;i<8;i++){ // ilk 2 eleman girildi�i i�in toplam 8 elemana ihtiya� var
		int sayi = rand()%20; //say�lar rastgele olarak �retildi
		
		if(sayi%2==0)//�ift listeye ekle
			sonaekle(cifthead,sayi);
		else //tek listeye ekle
			sonaekle(tekhead,sayi);
	}
	//listelerin olu�turulmu� hali yazd�r�l�yor
	printf("Listelerin ilk hali : \n");
	printf("\tTek Liste --> ");
	ekranaYaz(tekhead);
	printf("\n\tCift Liste --> ");
	ekranaYaz(cifthead);
	printf("\n\n");
	
	for(int i=0;i<5;i++){ // 5 kez yaz�-tura at�lma durumu
		int yazitura = rand()%2; // 0 tura ; 1 yaz�
		
		if (yazitura==0){ //tek listeden sil
			sondansil(tekhead);
			printf("Tek Listeden Eleman Silindi\n");
		}
		else{
			sondansil(cifthead);
			printf("Cift Listeden Eleman Silindi\n");
		}
	}
	
	//Listelerin yaz� tura at�ld�ktan sonraki eleman silinmi� hali yazd�r�l�yor
	printf("\nListelerin son hali : \n");
	printf("\tTek Liste --> ");
	ekranaYaz(tekhead);
	printf("\n\tCift Liste --> ");
	ekranaYaz(cifthead);
	

	return 0;
	
}

