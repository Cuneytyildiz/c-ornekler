#include <stdio.h>
#include <stdlib.h>
#define KUYRUK_BOYUT 10


typedef struct {
	int veri[KUYRUK_BOYUT];
	int ilk;
	int son;
	int elemanSayisi;
}Kuyruk;


Kuyruk* KuyrukOlustur() {
	Kuyruk* k = (Kuyruk *)malloc(sizeof(Kuyruk));
	k->elemanSayisi = 0;
	k->ilk = 0;
	k->son = -1;
	return k;
}

void Ekle(Kuyruk *k,int deger) { //enqueue
	//kuyrukta yer var m� yok mu kontrol edilir

	if (k->elemanSayisi < KUYRUK_BOYUT) { //kuyrukta yer olma durumu
		k->son++;
		k->elemanSayisi++;

		//kuyrukta yer olup da son eleman dizinin son indisinde ise
		//eklenecek eleman dizinin ba��na eklenmeli
		if (k->son == KUYRUK_BOYUT)
			k->son = 0;

		k->veri[k->son] = deger;
	}
	else { //kuyru�un dolu olma durumu
		printf("Kuyruk Dolu! %d eklenemedi",deger);
	}


}


int Cikar(Kuyruk *k) { //dequeue
	//kuyrukta eleman var m� yok mu kontrol edilir

	if (k->elemanSayisi > 0) {//kuyrukta eleman olma durumu

		k->elemanSayisi--;
		int x = k->veri[k -> ilk];
		k->ilk++;

		//kuyruktaki ilk eleman dizinin son indisinde olabilir
		//dequeue (��karma) i�lemi yap�l�rken kontrol edilmeli
		if (k->ilk == KUYRUK_BOYUT)
			k->ilk = 0;

		return x;
	}
	else {//kuyru�un bo� olma durumu
		printf("Kuyruk Bos! \n");
		return NULL;
	}


}








int main() {

	
	Kuyruk *k = KuyrukOlustur();

	Ekle(k, 1);
	Ekle(k, 3);
	Ekle(k, 5);
	Ekle(k, 7);
	Ekle(k, 9);
	Ekle(k, 11);
	Ekle(k, 13);
	Ekle(k, 15);
	Ekle(k, 17);
	Ekle(k, 19);	
	Ekle(k, 67);	
	Cikar(k);
	Ekle(k, 21);
	Cikar(k);
	Ekle(k, 23);

	int a = Cikar(k);
	printf("\n %d ",a);

	a = Cikar(k);
	printf("\n %d ", a);


	return 0;
}
