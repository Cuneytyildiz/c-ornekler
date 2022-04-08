#include <stdio.h>
#include <stdlib.h>
#include<time.h>


int main(int argc, char *argv[]) {
	srand(time(NULL));
	int i,ii,iii,iiii,iiiii,q,qq,qqq,qqqq,qqqqq,w,ww,www,wwww,wwwww,uzunkont,uzunkontq,j,jj,jjj,jjjjj,gecici,kalan;
	char oyuncu[20],maxtas[20],maxtoptas[20],basadon[20],sayi[20];
	qqqq=0;
	while(qqqq < 1)
	{
	basadon[0] = '\0';	
	q=0;qq=0;qqq=0;	qqqq=0;qqqqq=0;w=0;ww=0;www=0;wwwww=0;uzunkont=0;uzunkontq=0;j=0;jj=0;jjj=0;jjjjj=0;
	printf("Tas Toplama Oyununa Hosgeldiniz...\n");
	
	while(q < 1)
	{	
		maxtas[0] = '\0';
		w=0;
		j=0;
		printf("Kac tas kullanilcak?: ");
		
		gets(maxtas);

		for(i=0; maxtas[i]!='\0'; i++)
		{	
			j=1;		
			if(maxtas[i] >= 48 && maxtas[i] <= 57)
			{		
				
				if(w == 0 && atof(maxtas) > 1  || atof(maxtas) < 0)
				{						
					q=1;
				}
				else
				{			
					printf("Girilen deger '0','1' olamaz! \n");	
					q=0;
					w = 1;			
					break;								
				}		
			}
			else
			{
				printf("Girilen deger tamsayi degil! \n");			
				q=0;
				w = 1;			
				break;			
			}	   
		}
		if(j==0)
		{
		printf("Birseyler Yaz! \n");
		}	
	}
		

	while(qq < 1)
	{	
		maxtoptas[0] = '\0';
		ww=0;
		jj=0;
		printf("Her hamlede maksimum kac tane tas toplanabilir?: ");
		
		gets(maxtoptas);

		for(ii=0; maxtoptas[ii]!='\0'; ii++)
		{		
			jj=1;	
			if(maxtoptas[ii] >= 48 && maxtoptas[ii] <= 57)
			{	
			
				if(atof(maxtoptas) < atof(maxtas) && ww == 0 && atof(maxtoptas) != 0)
				{						
					qq=1;
				}
				else
				{
					qq=0;
					if(atof(maxtoptas) == atof(maxtas))
					{
						printf("Girilen deger toplam tas sayisina esit olamaz! \n");	
						break;
					}
					else if(atof(maxtoptas) > atof(maxtas))
					{
						printf("Girilen deger toplam tas sayisindan buyuk olamaz! \n");	
						break;
					}
					else
					{
						printf("Girilen deger '0' olamaz! \n");	
						break;
					}					
				}		
				
			}
			else
			{
				printf("Girilen deger tamsayi degil! \n");			
				qq=0;
				ww = 1;			
				break;			
			}	   
		}
		if(jj==0)
		{
		printf("Birseyler Yaz! \n");
		}		
	}
	
	
	
	while(qqq < 1)
	{	
		jjj=0;
		oyuncu[0] = '\0';
		uzunkont=0;
		printf("Oyuna kim baslayacak (Bigisayar  (B) / Kullnici (K))?: ");
		
		gets(oyuncu);
		for(iii=0; oyuncu[iii]!='\0'; iii++)
		{	
			jjj=1;
			if(oyuncu[iii] == 98 || oyuncu[iii] == 66 || oyuncu[iii] == 107 ||oyuncu[iii] == 75)
			{
			
						for(www=0; oyuncu[www]!='\0'; www++)
						{
							uzunkont++;							
						}
						if(uzunkont == 1)
						{							
							if(oyuncu[0] == 98 || oyuncu[0] == 66)
							{
							 oyuncu[0] = 66;
							}
							else if(oyuncu[0] == 107 || oyuncu[0] == 75)
							{
							 oyuncu[0] = 75;
							}
							else
							{
						 	printf("Oyuncu Seciminde Hata 000! \n");
							}
							qqq=1;															
							break;			
						}	
				printf("Girilen oyuncu tanimli degil! \n");			
				qqq=0;			
				break;					
			}
			else
			{
				printf("Girilen oyuncu tanimli degil! \n");			
				qqq=0;
							
				break;			
			}	   
		}
		if(jjj==0)
		{
		printf("Birseyler Yaz! \n");
		}		
	}
	 
	int kalanskor,akillihamle;
	kalanskor =  atoi(maxtas);
	while(qqqqq < 1)
	{	
		sayi[0] = '\0';		
		wwwww=0;
		jjjjj=0;
    	printf("%s: ",oyuncu);
		if(oyuncu[0] == 'B')
		{
	  
				
		  akillihamle = (kalanskor - 1) % (atoi(maxtoptas) + 1);
		  if(akillihamle == 0)
		  {
		    
		 	akillihamle = rand()%(atoi(maxtoptas))+1;
		  }		  
		  sprintf(sayi, "%d", akillihamle);	 
		  printf("%s\n",sayi);
		  
	     	
		}
		else if(oyuncu[0] == 'K')
		{

		gets(sayi);
		}
		else
		{
		printf("Oyuncu Seciminde Hata 111! \n");
		qqqqq=1;
		break;
		}
	

		for(iiiii=0; sayi[iiiii]!='\0'; iiiii++)
		{		
			jjjjj=1;	
			if(sayi[iiiii] >= 48 && sayi[iiiii] <= 57)
			{	
				
				if(atof(sayi) <= atof(maxtoptas) &&atof(sayi) < atof(maxtas) && wwwww == 0 && atof(sayi) != 0)
				{									
					kalanskor -= atof(sayi);			
					if(kalanskor == 1)
					{									
							if(oyuncu[0] == 'B')
							{
							 printf("Oyun Bitti. Bilgisayar kazandi... \n");	
							}
							else if(oyuncu[0] == 'K')
							{
					    	 printf("Oyun Bitti. Kullanici kazandi... \n");	
							}
							else
							{
						     printf("Oyuncu Seciminde Hata 111! \n");
							}			
						qqqqq=1;
						break;
						
					}
					else if(kalanskor == 0)
					{
						printf("Kalan Skor '0' olamaz! \n");
						kalanskor += atof(sayi);
						qqqqq=0;	
						break;			
					}
					else if(kalanskor < 0)
					{
						printf("Kalan Skor negatif sayi olamaz! \n");
						kalanskor += atof(sayi);
						qqqqq=0;	
						break;			
					}
					else
					{
					
						if(oyuncu[0] == 'B')
						{
						 oyuncu[0] ='K';
						}
						else if(oyuncu[0] == 'K')
						{
						 oyuncu[0] = 'B';
						}
						else
						{
						 printf("Oyuncu Degisiminde Hata! \n");
						}
						
						qqqqq=0;	
						break;	
					}
				}
				else
				{
					qqqqq=0;
					if(atof(sayi) == atof(maxtas))
					{
						printf("Girilen deger toplam tas sayisina esit olamaz! \n");	
						break;
					}
					else if(atof(sayi) > atof(maxtas))
					{
						printf("Girilen deger toplam tas sayisindan buyuk olamaz! \n");	
						break;
					}
					else if(atof(sayi) > atof(maxtoptas))
					{
						printf("Girilen deger alina bilecek degerden fazla! \n");	
						break;
					}
					else
					{
						printf("Girilen deger '0' olamaz! \n");	
						break;
					}					
				}		
				
			}
			else
			{
				printf("Girilen deger tamsayi degil! \n");			
				qqqqq=0;
				wwwww = 1;			
				break;			
			}	   
		}
		if(jjjjj==0)
		{
		printf("Birseyler Yaz! \n");
		}		
	}
		
	
	printf("Sonlandir (q/Q)? ");
	gets(basadon);
	for(iiii=0; basadon[iiii]!='\0'; iiii++)
	{			
		if(basadon[iiii] == 113 || basadon[iiii] == 81)
		{
					for(wwww=0; basadon[wwww]!='\0'; wwww++)
					{
						uzunkontq++;							
					}
					if(uzunkontq == 1)
					{
						qqqq=1;
						printf("\nHoscakal!!!");
						break;			
					}	
			printf("\n");			
			qqqq=0;			
			break;					
		}
		else
		{
			printf("\n");			
			qqqq=0;						
			break;			
		}	   
	}			
	}	
	system("pause");
	return 0;
}
