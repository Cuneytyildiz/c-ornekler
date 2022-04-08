#include <stdio.h>
#include <stdlib.h>
#define KUYRUK_BOYUT 10

struct kuyruk{
	int data[KUYRUK_BOYUT];
	int ilk;
	int son;
	int elemansayisi;
};

struct kuyruk *kuyrukolustur(){
	struct kuyruk *k=(struct kuyruk *)malloc(sizeof(struct kuyruk));
	k->elemansayisi =0;
	k->ilk=0;
	k->son=-1;
	return k;
}

void ekle(struct kuyruk *k,int deger){ //enqueue
	// kuyrukta yer var mı yok mu kontrol edilir
	
	if(k->elemansayisi < KUYRUK_BOYUT){ // kuyrukta boş yer olma durumu
		k->son++;
		k->elemansayisi++;
		
		// kuyrukta yer olup da son eleman dizinin son indisinde ise
		// eklenecek eleman dizisinin başına eklenmeli
		
		if(k->son==KUYRUK_BOYUT)
			k->son=0;
		
		k->data[k->son]=deger;		
	}
	else{ // kuyruğun dolu olma durumu
		printf("Kuyruk Dolu! %d eklenemedi",deger);
	}
		
}

int cikar(struct kuyruk *k){ // dequeue
	//kuyrukta eleman var mı yok mu kontrol edilir
	
	if(k->elemansayisi>0){	//kuyrukta eleman olma durumu
		k->elemansayisi--;
		int x=k->data[k->ilk];
		k->ilk++;
		
		//kuyruktaki ilk eleman dizisinin son indiisnde olabilir
		//dequeue (çıkarma) işlemi yapılırken kontrol edilmeli
		
		if (k->ilk == KUYRUK_BOYUT)
			k->ilk=0;
			
		return x;
	}
	else{
		// kuyruğun boş olma durumu
		printf("Kuyruk Boş!\n");
		return NULL;
	}
}

int main(){
	struct kuyruk *k = kuyrukolustur();
	
	ekle(k,1);
	ekle(k,3);
	ekle(k,5);
	ekle(k,7);
	ekle(k,9);
	ekle(k,11);
	ekle(k,13);
	ekle(k,15);
	ekle(k,17);
	ekle(k,19);
	ekle(k,67);
	cikar(k);
	ekle(k,21);
	cikar(k);
	ekle(k,23);
	
	int a = cikar(k);
	printf("\n %d",a);
	
	a=cikar(k);
	printf("\n %d",a);
	return 0;
}
