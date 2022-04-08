#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
	int veri;
	struct node *next;
};
void goster(struct node *list)
{
	while(list!=NULL)
	{
	printf("\n%d \t adres=%p",list->veri,list);
	list=list->next;
	
	}
}
 struct node *arayaekle(struct node *list)//ilk düğüm adresi
{
	 struct node *yeni;
if (list==NULL)
{
	list=(struct node *)malloc(sizeof(struct node));
	printf("\nSayı Giriniz:");
	scanf("%d",&list->veri);
	list->next=NULL;
	return list;
}else 
{
	if(list->next==NULL)
	return list;
	else
	{
	yeni=(struct node *)malloc(sizeof(struct node));
	printf("\nSayı Giriniz:");
	scanf("%d",&yeni->veri);	
		yeni->next=list->next;
		list->next=yeni;
	return NULL;
	}
	
}




}



void sondanekle(struct node *list)
{char cev;
	printf("\nDevam etmek istiyormusunuz:");
	cev=getch();
while(cev=='e'||cev=='E')
{
list->next=(struct node *)malloc(sizeof(struct node));
list=list->next;	
	printf("\nSayı Giriniz:");
	scanf("%d",&list->veri);
	printf("\nDevam etmek istiyormusunuz:");
	cev=getch();
}
list->next=NULL;
}

int main()
{
struct node *ilk,*list;
ilk=(struct node *)malloc(sizeof(struct node));
printf("Sayı Giriniz:");
scanf("%d",&ilk->veri);
list=ilk;
sondanekle(list);
list=ilk;
while (list!=NULL)
{
list=arayaekle(list);	

}


list=ilk;//liste başa getirildi
goster(list);
return 0;	
}
