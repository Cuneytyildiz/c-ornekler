#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <graphics.h>
#include <windows.h>

struct node {
	int x;
	int y;
	int e;
	struct node *next;
	struct node *prev;
};

struct node* root = NULL;
struct node* prev = NULL;
struct node* iter;
struct node* iter2;
int xx,fit;

struct node* CreateNewNode(int _x,int _y) {
	struct node* NewNode = (struct node*)malloc(sizeof(struct node));
	NewNode->x = _x;
	NewNode->y = _y;
	NewNode->e = 0;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	return NewNode;
}

void sonaEkle(int _x,int _y) {
	struct node* sonaEklenecek = CreateNewNode(_x,_y);

	//Eðer listede hiç eleman yoksa yeni eleman ekliyoruz
	if (root == NULL) {
		root = sonaEklenecek;
	}

	else {
		//traverse etmek için temp deðiþkenine start deðiþkenini atadýk, maksat start deðiþkenini bozmamak.
		iter = root;

		//Aþaðýdaki döngü traverse yapýyor ve temp düðümü döngü sonunda son düðüm oluyor.
		while (iter->next != NULL) {
			iter = iter->next;
		}

		//temp elemaný (eski son) olduðu için sonaEklenecek (yeni son) düðümünün prev iþaretçisi tempi gösterecek.
		sonaEklenecek->prev = iter;

		//temp deðiþkeninin next iþaretçisi ise artýk yeni son elemanýmýz olan sonaEklenecek düðümünü iþaret edecek.
		iter->next = sonaEklenecek;
	}
}

void girisekrani() {
	int x = 150;
	int y = 150;
	delay(500);
	// font style
	int font = 8;

	// font yön
	int direction = 0;

	// font size
	int font_size = 10;

	// ayarlarý metine uyarla
	settextstyle(font, direction, font_size);

	// Grafik Ekraný
	x+=300;
	setcolor( 4 );
	outtextxy(x, y, "Oyun Adý");
	font_size = 5;
	settextstyle(font, direction, font_size);
	y+=225;
	x-=150;
	//Beep(500,300);
	delay(1000);
	//Beep(500,300);
	setcolor( WHITE  );
	outtextxy(x, y, "Mehmet Fatih Bezir");
	y+=100;
	outtextxy(x, y, "Cüneyt Yýldýz");
	delay(500);
	y+=100;
	delay(500);
	//Beep(500,300);
	outtextxy(x, y, "Baslatmak Ýcin Tusa Týkla...");
	getch();
	cleardevice();

}


void TahtaCiz2(int xc,int yc) {
	//int p1=initwindow(1600,900,"EHU");

	Beep(500,200);
	//setcurrentwindow(p1);
	//cleardevice();
	//initwindow(1600,900);
	int en=13,boy=13;

	for(int x=50; x>=0; x--) {
		//printf("\n");

		for(int y=0; y<=100; y++) {

			xx=0;
			iter = root;
			while(xx==0) {
				if(iter->x == x && iter->y == y) {
					xx=1;
					fit = iter -> e;
					break;
				} else {
					iter = iter->next;
				}
			}

			if(iter->x == xc && iter->y == yc) {
				if(iter->e == 0) {
					//Beep(500,300);
					//printf("A");//Karakter Konumu Normal
					setcolor(WHITE);
					setfillstyle(SOLID_FILL,2);
					rectangle(en,boy,en+15,boy+15);
					floodfill(en+1,boy+1,WHITE);
					en+=15;

				} else if(iter->e == 1) {
					//Beep(800,300);
					//printf("X");//Karakter Konumu Engele Carpmýs
					setcolor(WHITE);
					setfillstyle(SOLID_FILL,0);
					rectangle(en,boy,en+15,boy+15);
					floodfill(en+1,boy+1,WHITE);
					en+=15;

				} else if(iter->e == 2) {
					//Beep(300,300);
					//printf("W");//Karakter Konumu Anhtar Almýs
					setcolor(WHITE);
					setfillstyle(SOLID_FILL,6);
					rectangle(en,boy,en+15,boy+15);
					floodfill(en+1,boy+1,WHITE);
					en+=15;

				} else {
					printf("/nHata");

				}

			} else {
				if(fit == 0) {
					//printf("*");//Normal
					setcolor(WHITE);
					setfillstyle(SOLID_FILL,BLUE);
					rectangle(en,boy,en+15,boy+15);
					floodfill(en+1,boy+1,WHITE);
					en+=15;
				} else if(fit == 1) {
					//printf("=");//Engel
					setcolor(WHITE);
					setfillstyle(SOLID_FILL,RED);
					rectangle(en,boy,en+15,boy+15);
					floodfill(en+1,boy+1,WHITE);
					en+=15;
				} else if(fit == 2) {
					setcolor(WHITE);
					setfillstyle(SOLID_FILL,YELLOW);
					rectangle(en,boy,en+15,boy+15);
					floodfill(en+1,boy+1,WHITE);
					en+=15;
					//printf("^");//Anahtar
				} else {
					printf("/nHata");
					break;
				}
			}


		}
		//delay(1);
		en=13;
		boy+=15;
	}
	//getch();  //çýkan grafik ekraný kapatmak için tusa basma
	//closegraph();
}

int main() {
//	int gr = DETECT, gm;
//	initgraph(&gr,&gm,"C:\\TC\\BGI");

	int wd;
	wd=initwindow(1600,900,"Veri Yapilari Oyun");
	srand(time(NULL));
	girisekrani();
//	oyunbilgileri();

	//tahta olustur
	for(int x = 0; x <= 50; x++) {
		for(int y = 0; y <= 100; y++) {
			sonaEkle(x,y);
		}
	}

	//tahtaya engel koy
	int xe,ye,q=0,qq=0;
	iter = root;

	for(int anahtar=0; anahtar<=0; anahtar) {
		xe = rand()%51;
		ye = rand()%101;
		while(qq==0) {
			if(iter->x == xe && iter->y == ye) {
				if((xe == 0 && ye == 0) || (xe == 50 && ye == 100)) {

					printf("Baslangýca ve sona Anahtar koyulmaz");

				} else {
					iter->e = 2;
					anahtar++;
					qq=1;
					printf("Anahtar Koyduk:%d,%d,%d\n",iter->x,iter->y,iter->e);
					iter = root;
				}
			} else {
				iter = iter->next;
			}
		}
	}

	for(int e = 0; e <= 30; e) {
		q=0;
		xe = rand()%51;
		ye = rand()%101;
		//printf("%d,%d\n",xe,ye);
		while(q==0) {
			if(iter->x == xe && iter->y == ye) {
				if(iter->e == 2) {
					printf("Anahtar olan yere engel koyulmaz");
					q=1;
					break;
				} else {
					if((xe == 0 && ye == 0) || (xe == 50 && ye == 100)) {

						printf("Baslangýca ve sona engel koyulmaz");
						q=1;
						break;
					} else {
						iter->e = 1;
						e++;
						q=1;
						printf("Engel Koyduk:%d,%d,%d\n",iter->x,iter->y,iter->e);
						iter = root;
					}
				}
			} else {
				iter = iter->next;
			}
		}
	}

	char *renk;
	int r, x = 0, y = 0, b = 0,anahtarx = 0;
	int engelsayisi=0,hamlesayisi=0,tablodisi=0;
	int  ks=0,ms=0,bs=0;
	int gecerlihamlesayisi=0,gecersizhamlesayisi=0;
	int  gksiz=0,gmsiz=0,gbsiz=0;
	int  gks=0,gms=0,gbs=0;
	int  tks=0,tms=0,tbs=0;
	int s = 0;
	int shk=0;
	int khs=0;
	iter = root;
	while(b == 0) {
		//1 sonraki her hamleyi kontrol et
		//3 hamle de engel varmý
		//en son a mesala x gelirse beyaz ve mavi oynanamaz olcak ve ayný zamanda kýrmýzýdada engel varsa sonsuz dongu olur
		shk=0;
		khs=0;
		hamlesayisi++;
		iter2=root;
		while(shk==0) {
			if(x >= 50) {
				shk++;
				khs++;
				break;
			} else {
				if(x+2 > 50) {
					shk++;
					khs++;
					break;
				} else {
					if(iter2->x == x+2 && iter2->y == y) { //Mavi
						if(iter2->e == 1) {
							khs++;
						}
						shk++;
						//printf("q");
						break;
					} else {
						iter2 = iter2->next;
					}
				}
			}
		}
		iter2=root;
		while(shk==1) {
			if(y >= 100) {
				shk++;
				khs++;
				break;
			} else {
				if(y+2 > 100) {
					shk++;
					khs++;
					break;
				} else {
					if(iter2->x == x && iter2->y == y+2) { //Mavi
						if(iter2->e == 1) {
							khs++;
						}
						shk++;
						//printf("q");
						break;
					} else {
						iter2 = iter2->next;
					}
				}
			}
		}
		iter2=root;
		while(shk==2) {
			if(x == 50 || y==100) {
				shk++;
				khs++;
				break;
			} else {
				if(x+1 > 50 && y+1 > 100) {
					shk++;
					khs++;
					break;
				} else {
					if(iter2->x == x+1 && iter2->y == y+1) { //Mavi
						if(iter2->e == 1) {
							khs++;
						}
						shk++;
						//printf("q");
						break;
					} else {
						iter2 = iter2->next;
					}
				}
			}
		}


		if(s==0) {
			printf("%d,%d\n",x,y);
			TahtaCiz2(x,y);
		}
		s++;

		if(khs == 3) {
			printf("\nSah Mat!\nSona Gelinmedi - Basarisiz");
			b++;
			TahtaCiz2(x,y);
			break;
		} else {
			//zar at
			r = rand()%6;
			// zara göre hamle ayarla
			if(r == 0 || r == 5) {
				tms++;
				renk= "\nMavi";
				printf("\n%s\n",renk);
				printf("Eski Konum:%d,%d\n",x,y);
				x += 2;
				printf("Yeni Konum:%d,%d\n",x,y);
				//tahta dýsýna çýkma kontrol
				if(x > 50) {
					x -= 2;
					printf("Tablo Disi Geri Alindi:%d,%d\n",x,y);
					tablodisi++;
					gecersizhamlesayisi++;
					gmsiz++;
				} else {
					//engel kontrol + anahtar kontrol
					iter = root;
					q = 0;
					while(q==0) {
						if(iter->x == x && iter->y == y) {
							q=1;
							printf("Engel Yok:%d,%d\n",iter->x,iter->y);
							break;
						} else {
							if(iter->x == 50 && iter->y == 100) {
								//printf("Denme");
								break;
							} else {
								iter = iter->next;
							}

						}
					}
					if(iter->e == 1) { //engel
						printf("Engel Geri Alindi:");
						engelsayisi++;
						gecersizhamlesayisi++;
						gmsiz++;
						iter= root;
						q=0;
						while(q==0) {
							if(iter->x == x-2 && iter->y == y) {
								q=1;
								printf("%d,%d\n",iter->x,iter->y);
								break;
							} else {
								iter = iter->next;
							}
						}
						x -= 2;
						printf("Konum:%d,%d\n",x,y);
					} else if(iter->e == 2) { //anahtar
						anahtarx++;
						iter->e = 0;
						printf("Anahtar Alindi!\n");
					}
				}

			} else if(r == 1 || r == 4) {
				tks++;
				renk= "\nKirmizi";
				printf("\n%s\n",renk);
				printf("Eski Konum:%d,%d\n",x,y);
				y += 2;
				printf("Yeni Konum:%d,%d\n",x,y);
				//tahta dýsýna çýkma kontrol
				if(y > 100) {
					y -= 2;
					printf("Tablo Disi Geri Alindi:%d,%d\n",x,y);
					tablodisi++;
					gecersizhamlesayisi++;
					gksiz++;
				} else {
					//engel kontrol
					iter = root;
					q = 0;
					while(q==0) {
						if(iter->x == x && iter->y == y) {
							q=1;
							printf("Engel Yok:%d,%d\n",iter->x,iter->y);
							break;
						} else {
							if(iter->x == 50 && iter->y == 100) {
								//printf("Denme");
								break;
							} else {
								iter = iter->next;
							}

						}
					}
					if(iter->e == 1) {
						printf("Engel Geri Alindi:");
						engelsayisi++;
						gecersizhamlesayisi++;
						gksiz++;
						iter= root;
						q=0;
						while(q==0) {
							if(iter->x == x && iter->y == y-2) {
								q=1;
								printf("%d,%d\n",iter->x,iter->y);
								break;
							} else {
								iter = iter->next;
							}
						}
						y -= 2;
						printf("Konum:%d,%d\n",x,y);
					} else if(iter->e == 2) { //anahtar
						anahtarx++;
						iter->e = 0;
						printf("Anahtar Alindi!\n");
					}
				}
			} else if(r == 2 || r == 3) {
				tbs++;
				renk= "\nBeyaz";
				printf("\n%s\n",renk);
				printf("Eski Konum:%d,%d\n",x,y);
				x++;
				y++;
				printf("Yeni Konum:%d,%d\n",x,y);
				//tahta dýsýna çýkma kontrol
				if(x > 50 || y > 100) {
					x--;
					y--;
					printf("Tablo Disi Geri Alindi:%d,%d\n",x,y);
					tablodisi++;
					gecersizhamlesayisi++;
					gbsiz++;
				} else {
					//engel kontrol
					iter = root;
					q = 0;
					while(q==0) {
						if(iter->x == x && iter->y == y) {
							q=1;
							printf("Engel Yok:%d,%d\n",iter->x,iter->y);
							break;
						} else {
							if(iter->x == 50 && iter->y == 100) {
								//printf("Denme");
								break;
							} else {
								iter = iter->next;
							}

						}
					}
					if(iter->e == 1) {
						printf("Engel Geri Alindi:");
						engelsayisi++;
						gecersizhamlesayisi++;
						gbsiz++;
						iter= root;
						q=0;
						while(q==0) {
							if(iter->x == x-1 && iter->y == y-1) {
								q=1;
								printf("%d,%d\n",iter->x,iter->y);
								break;
							} else {
								iter = iter->next;
							}
						}
						x--;
						y--;
						printf("Konum:%d,%d\n",x,y);
					} else if(iter->e == 2) { //anahtar
						anahtarx++;
						iter->e = 0;
						printf("Anahtar Alindi!\n");
					}
				}
			} else {
				printf("Zar Araligi Hatasi\n");
			}
			TahtaCiz2(x,y);
			//bitiþ kontrol
			if(x == 50 && y == 100) {
				if(anahtarx == 1) {
					printf("\n\nSona Gelindi - Basarili");
					TahtaCiz2(x,y);
				} else {
					printf("\n\nSona Gelindi - Basarisiz");
					TahtaCiz2(x,y);
				}
				b=1;
			}
		}

	}
	gecerlihamlesayisi= hamlesayisi - gecersizhamlesayisi;
	gms = tms - gmsiz;
	gks = tks - gksiz;
	gbs = tbs - gbsiz;
	printf("\nEngele Carpma Sayisi         : %d - Tablo Disina Cikma Sayisi     : %d",engelsayisi,tablodisi);
	printf("\nToplam Hamle Sayisi          : %d - Gecerli Hamle Sayisi        : %d - Gecersiz Hamle Sayisi          : %d",hamlesayisi,gecerlihamlesayisi,gecersizhamlesayisi);
	printf("\nToplam Mavi Hamle Sayisi     : %d - Gecerli Mavi Hamle Sayisi    : %d - Gecersiz Mavi Hamle Sayisi     : %d",tms,gms,gmsiz);
	printf("\nToplam Kirmizi Hamle Sayisi  : %d - Gecerli Kirmizi Hamle Sayisi : %d - Gecersiz Kirmizi Hamle Sayisi  : %d",tks,gks,gksiz);
	printf("\nToplam Beyaz Hamle Sayisi    : %d - Gecerli Beyaz Hamle Sayisi   : %d - Gecersiz Beyaz Hamle Sayisi    : %d",tbs,gbs,gbsiz);

}
