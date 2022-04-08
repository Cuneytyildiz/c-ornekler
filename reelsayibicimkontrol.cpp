/*
REEL SAYI BÝÇÝM KONTROLÜ:  
Bu projede, kullanýcý programý sonlandýrmak istediðini belirtene kadar karakterlerden oluþan bir girdi 
okunacak ve okunan girdinin geçerli bir pozitif reel sayý olup olmadýðý belirlenecektir. Girdinin 
geçerli/geçersiz olmasý için koþullar ve programýn çýktýlarýyla ilgili ayrýntýlar aþaðýdadýr:
  
1. Sayýnýn tamsayý bölümü ile ondalýk bölümünü ayýrmak için ondalýk nokta (‘.’) karakteri 
kullanýlmalýdýr. Tamsayýlar da geçerli reel sayýlar olarak kabul edileceði için ‘.’ karakteri hiç 
kullanýlmamýþ olabilir. Okunan karakterlerden en çok bir tanesi ‘.’ karakteri olmalýdýr. Birden 
çok ‘.’ görmek geçersizlik demektir. 

2. ‘.’ dýþýndaki tüm karakterler rakam olmalýdýr (‘0’,’1’,’2’,’3’,’4’,’5’,’6’,’7’,’8’,’9’). 

3. Girdinin baþýnda ve sonunda bulunan boþluk (‘ ‘) karakterleri göz ardý edilmeli ve hata olarak 
deðerlendirilmemelidir. 

4. Kullanýcýnýn saðladýðý girdi mutlaka yeni satýr (‘\n’) karakteriyle bitecektir. Yani, kullanýcýnýn 
ENTER’e basmasý  girdideki  karakterlerin  birer  birer  okunup  deðerlendirilme  zamanýnýn 
geldiði anlamýndadýr.
 
5. Boþluktan farklý iki karakter arasýnda boþluk karakterlerinin (‘ ‘) bir dizisi görülürse bu da 
geçersiz bir reel sayý olarak deðerlendirilecektir. 

6. Okunan sayý geçerli bir reel sayýysa, bu sayýnýn 2 katý, ondalýk noktadan sonra iki basamak 
bulunacak þekilde ekrana yazdýrýlmalýdýr.  

7. Okunan girdi geçerli bir reel sayý deðilse, bunun program tarafýndan belirlenen ilk nedeni de 
ekrana yazdýrýlmalýdýr.

8. Kullanýcýnýn  yeni  bir  girdi  için  geçerlilik/geçersizlik  (biçim)  kontrolü  yapmak  isteyip 
istemediðini  almak  için  her  yinelemenin  sonunda  bir  karakter  okunmalýdýr.  ‘q’  ve  ‘Q’ 
karakterleri girdi okumayý sonlandýrma, diðer karakterler yeni bir girdi okunacaðý anlamýna 
gelmelidir.
 
Sonraki sayfada programýn bir seanslýk koþmasýndan bir örnek var. Gösterimde, anlaþýlýr olsun diye, 
her ‘#’ karakteri boþluk karakterini ifade etmektedir. Gerçeklemede, diyez karakteri (‘#’) deðil, boþluk 
karakteri (‘ ‘) kullanýlacaktýr.

Reel sayi girin: 315 
Gecerli! Sayi = 630.00 
Sonlandir (q/Q)? A 

Reel sayi girin: -98.7 
Gecersiz! – karakteri goruldu. 
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
