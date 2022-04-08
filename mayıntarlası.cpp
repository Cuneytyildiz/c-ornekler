/* 
 * Name of the Program : MineField
*/

// field : Arka planda mayýnlarýn yerleþtirildiði, komsu mayýn sayýsýný içeren matrix.
// seenField : Kullanýcýya gosterilen taraf ve atýlan adýmlar sonucunda uzerýnde islem yapýlan matrix.
// pattern : bir mayýna komþu olan 8 kareye ulaþmak için kullanýcak koordinatlar.
// acilacaklar : mayýna komsulugu olmayan kareler aciliyor.Acilan karelerden sifir cýkanlarýn komsularý tekrar acýlýyor.Onlarý tutan dizi.


#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

// Global
// Aþagýdaki veriler bir cok fonksiyonda kullanýldýgý icin global olarak tanýmladým.
int field[12][12];
int seenField[12][12];
int pattern[2][8] = { 	{-1,-0,+1,-1,-0,+1,-1,+1},
						{-1,-1,-1,+1,+1,+1,-0,-0}	};
int acilacaklar[100];
int in=0,nerdeyim=0,acilanKare=0;

// Mayýnlarý yerleþtirileceði rastgele satýr ve sutun sayýlarý ýcýn
int randNumber(void){ 
		int i;
		
		i = rand() % 9 + 1;		
		srand(time(NULL));	
		
		return i;	
}

void initalize(int field[12][12], int input){
	int i,j;
	
	for( i=0; i<12; i++){
		for( j=0; j<12; j++ ){
			field[i][j] = input;
		}
	}
}

void printMatrix(int field[12][12]){
	int i=1,j;
	
	printf("\n    01    02    03    04    05    06    07    08    09    10");
	for( i=1; i<11; i++){
		printf("\n   ----------------------------------------------------------\n%2.d",i);
		for( j=1; j<11; j++ ){
			printf(" |%2.d| ", field[i][j]);
		}
	}
	printf("\n   ----------------------------------------------------------\n");
}

void yerAl(int *row, int *col){
	
	do{
		printf("\nSatir ve Sutun sayisini giriniz > ");
		scanf("%d%d", row,col);		
		
		// Girilen yer bilgisi daha onceden acilmis olabilir
		if( seenField[*row][*col] != 11 ){
			printf("HATA : Bu kare daha onceden acilmis!\n");
			*row = 0; // while þartýný devam edecek þekilde etkilemek icin.
		}
		
		// girilen row ve col matris boyutlarinin dýsýnda olabilir kontrol!		
	}while( *row>10 || *row<1 || *col>10 || *col<1);
	

}

void menu(int *secim){
	
	printf("\n\n");
	printf("[1] Kare Ac\n");
	printf("[2] Mayin Isaretle\n");
	printf("[3] Yeni Oyun\n");	
	printf("[4] Nasil Oynanýr?\n");
	
	// Secim 1,2,3,4 girilene kadar devam et.
	do{		
		printf("Secim > ");
		scanf("%d", secim);
	}while( *secim>4 || *secim<1 );
}

void ekle(int row, int col){
	int i;
	// eklenecek yer daha onceden eklenmiþ mi?
	for( i=0; i<in; i=i+1){
		if( acilacaklar[i] == row && acilacaklar[i+1] == col ){
			return;
		}
	}
	// Eklenmemiþ ise ekle
	acilacaklar[in] = row;
	in++;
	acilacaklar[in] = col;
	in++;	
}

void kareAc(int acilacaklarIndex){
	int i,j,k;
	
	// Acilan karenin mayýna komsulugu yoksa komsu 8 kareyi ac.
	for( k=0; k<8; k++){
		i = acilacaklar[acilacaklarIndex]+(pattern[0][k]);
		j = acilacaklar[acilacaklarIndex+1]+(pattern[1][k]);
		seenField[i][j] = field[i][j];
		acilanKare++;
		// Eger acilan karelerden 0 olan varsa onlarý da "acilacaklara" ekle.
		if( field[i][j] == 0){
			ekle(i,j);
		}
	}
	// acilacaklar listesinde bulunan nokta.
	nerdeyim = nerdeyim + 2;// bir kare actýgýmýz ýcýn 2 ýlerlýyoruz
}

void howToPlay(){
		printf("\n###############\n");
		printf("9 sayisi mayinlari gösterir.\n");
		printf("10 sayisi ise mayin isaretlenmis bölgeleri.\n");
		printf("1-8 sayilari mayin komsuluk sayisini.\n");
		printf("Mayin tarlasi 10x10 boyutlarýndadir.\n");
		printf("Satir ve sutun sayilarina siz giriyorsunuz.\n");
		printf("\n###############\n");		
}

int main(){					
	int i,j,k=0,numberOfMine;
	int secim,userRow,userCol;
		
	// Tarlayý sifirla
	initalize(field,10); // Duvarlar 10 olsun.
	initalize(seenField,11); // 11 acilmamis kareleri gostermek icin	
	
	// Mayýnlarý yerleþtir.
	while( k != 14 ){
		i = randNumber();
		j = randNumber();
		// do not overwrite
		if( field[i][j] != 9 ){
			field[i][j] = 9; // 9 for mine
			k++;
		}		
	}	
	
	// Komsu olunan mayýn sayýsýný hesapla
	for( i=1; i<11; i++){
		for( j=1; j<11; j++ ){
			if( field[i][j] != 9 ){
				numberOfMine = 0;
				for( k=0; k<8; k++){
					if( field[i+(pattern[0][k])][j+(pattern[1][k])] == 9 ){
						numberOfMine++;
					}
				}				
				field[i][j] = numberOfMine;
			}
		}
	}

	// Oyun tüm kareler acildiysa veya mayin bulunduysa biter!
	// diðer durumlardan biri olusmussa acilanKare = 100 yapýp oyunu sonlandýrýyorum.
	while ( acilanKare != 100 ){
		printMatrix(seenField);
		
		// Get ýnput from user
		menu(&secim);
		
		switch(secim){
			case 1 : 
				// Bolgeyi kazacaz
									
				yerAl(&userRow,&userCol);
							
				// Eðer bolge mayinliysa oyunu bitir.
				if( field[userRow][userCol] == 9 ){ 
					printf("Mayinli bolge oyun bitti!\n\n");
					acilanKare = 100; // Oyunu bitir
				}  	
				// Eðer mayýn deðilse ve sýfýrdan farklý ise tek kare aciyoruz.
				else if( field[userRow][userCol] != 0 ){
					// Karenin komsu oldugu mayin sayisini aciyoruz.
					seenField[userRow][userCol] = field[userRow][userCol];
					acilanKare++;
				} else {
					// Secilen bolge 0.
					seenField[userRow][userCol] = 0;
					acilanKare++;
					// Kareyi acilacaklar dizisine ekliyoruz
					ekle(userRow,userCol);
					// Acilacaklar listesindekileri bitirene kadar devam				
					while( nerdeyim < in ){
						kareAc(nerdeyim);
					}
				}
			break;
			
			case 2 :				
				// Istenen yere bayrak koyacaz.	
				yerAl(&userRow,&userCol);			
				// Ýstenen kareye bayrak yerleþtiriyoruz.
				seenField[userRow][userCol] = 10; // 10 for flag
				acilanKare++;
			break;
			
			case 3 :
				// Yeni oyun baþlat
				printf("Yeni oyun baslatilacak!");
				return 0;
			break;
			
			case 4 :
				// oyun nasýl oynanýr
				howToPlay();					
			break;
			// Default a gerek yok secim alýrken gerekli kontroller yapildi!
		}// end of switch		
	} // while in sonu
	
	// Kullaniciya olusturulan mayin tarlasini göster
	printf("== Mayýn Tarlasi ==\n");
	printMatrix(field);
	return 0;
}
