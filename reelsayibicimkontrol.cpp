/*
REEL SAYI B���M KONTROL�:  
Bu projede, kullan�c� program� sonland�rmak istedi�ini belirtene kadar karakterlerden olu�an bir girdi 
okunacak ve okunan girdinin ge�erli bir pozitif reel say� olup olmad��� belirlenecektir. Girdinin 
ge�erli/ge�ersiz olmas� i�in ko�ullar ve program�n ��kt�lar�yla ilgili ayr�nt�lar a�a��dad�r:
  
1. Say�n�n tamsay� b�l�m� ile ondal�k b�l�m�n� ay�rmak i�in ondal�k nokta (�.�) karakteri 
kullan�lmal�d�r. Tamsay�lar da ge�erli reel say�lar olarak kabul edilece�i i�in �.� karakteri hi� 
kullan�lmam�� olabilir. Okunan karakterlerden en �ok bir tanesi �.� karakteri olmal�d�r. Birden 
�ok �.� g�rmek ge�ersizlik demektir. 

2. �.� d���ndaki t�m karakterler rakam olmal�d�r (�0�,�1�,�2�,�3�,�4�,�5�,�6�,�7�,�8�,�9�). 

3. Girdinin ba��nda ve sonunda bulunan bo�luk (� �) karakterleri g�z ard� edilmeli ve hata olarak 
de�erlendirilmemelidir. 

4. Kullan�c�n�n sa�lad��� girdi mutlaka yeni sat�r (�\n�) karakteriyle bitecektir. Yani, kullan�c�n�n 
ENTER�e basmas�  girdideki  karakterlerin  birer  birer  okunup  de�erlendirilme  zaman�n�n 
geldi�i anlam�ndad�r.
 
5. Bo�luktan farkl� iki karakter aras�nda bo�luk karakterlerinin (� �) bir dizisi g�r�l�rse bu da 
ge�ersiz bir reel say� olarak de�erlendirilecektir. 

6. Okunan say� ge�erli bir reel say�ysa, bu say�n�n 2 kat�, ondal�k noktadan sonra iki basamak 
bulunacak �ekilde ekrana yazd�r�lmal�d�r.  

7. Okunan girdi ge�erli bir reel say� de�ilse, bunun program taraf�ndan belirlenen ilk nedeni de 
ekrana yazd�r�lmal�d�r.

8. Kullan�c�n�n  yeni  bir  girdi  i�in  ge�erlilik/ge�ersizlik  (bi�im)  kontrol�  yapmak  isteyip 
istemedi�ini  almak  i�in  her  yinelemenin  sonunda  bir  karakter  okunmal�d�r.  �q�  ve  �Q� 
karakterleri girdi okumay� sonland�rma, di�er karakterler yeni bir girdi okunaca�� anlam�na 
gelmelidir.
 
Sonraki sayfada program�n bir seansl�k ko�mas�ndan bir �rnek var. G�sterimde, anla��l�r olsun diye, 
her �#� karakteri bo�luk karakterini ifade etmektedir. Ger�eklemede, diyez karakteri (�#�) de�il, bo�luk 
karakteri (� �) kullan�lacakt�r.

Reel sayi girin: 315 
Gecerli! Sayi = 630.00 
Sonlandir (q/Q)? A 

Reel sayi girin: -98.7 
Gecersiz! � karakteri goruldu. 
Sonlandir (q/Q)? 3 
 */


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	basla:
	char c[100];
	char kontrol[]={'.','0','1','2','3','4','5','6','7','8','9',' '};
	char nokta = {'.'};
	char cik[100],karakter,karakter1,karakter2;
	char* giris=NULL;
	const char* bosluk=" ";
	int cikuzunluk=0;
	int blok=0;
	int noktacount=0;
	int kontrolcount=0;
	float sayi=0.0;
	
	printf("Reel sayi girin: ");
	gets(c);
		 
	giris = strtok(c,bosluk);
	while(giris!=NULL) {
		blok++;
	 	giris = strtok(NULL,bosluk);
	}
	if(blok==1){
		for(int sayac1=0;c[sayac1]!='\0';sayac1++){
			karakter1=c[sayac1];
			for(int sayac2=0;kontrol[sayac2]!='\0';sayac2++){
				karakter2=kontrol[sayac2];
				if(karakter1==karakter2){
					kontrolcount++;
				}
				else{
				}
			}
			if(kontrolcount!=1){
				printf("Gecersiz! %c karakteri goruldu.\n",karakter1);
				goto son;
			}
			else{
				kontrolcount=0;
			}
		}
		for(int sayac=0;c[sayac]!='\0';sayac++){
			karakter=c[sayac];
			if(nokta==karakter)
				noktacount++;
		}
		if(noktacount<2){		
			sayi = atof(c);
			printf("Gecerli! Sayi = %.2f\n",sayi*2);
			goto son;
		}
		else{
			printf("Gecersiz! Birden fazla . karakteri goruldu.\n");
			goto son;
		}
	}
	else if(blok==0){
		printf("Gecersiz! Hic karakter girilmedi.\n");
		goto son;
	}
	else {
		printf("Gecersiz! Bosluk olmayan karakterler arasinda bosluk dizisi var.\n");
		goto son;
	}	
	son:
	printf("Sonlandir (q/Q)? ");
	gets(cik);
	cikuzunluk = strlen(cik);
	if(cikuzunluk==1){
		if(cik[0]!='q' && cik[0]!='Q'){
			devam:
			noktacount=0;
	 		printf("\n");
 			goto basla;
 		}
 		else{
			printf("HOSCAKAL!!!\n");
 			return 0;
		}
	}
	else{
		goto devam;
	}
}
