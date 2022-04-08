#include <stdio.h>
#include <stdlib.h>

struct node {
	
	int veri;
	struct node *sag, *sol;
	
};
	struct node *agac,*kok,*sonkok;

void ekle(int veri)
{	

	agac = kok;
	if (agac == NULL)
	{
		agac = (struct node*)malloc(sizeof(struct node));
		agac->sag=agac->sol=NULL; 
		agac->veri = veri;
		kok = agac;
	}
	else
	{
		while (agac != NULL)
		{
			sonkok = agac;
			if (veri < agac->veri)
				agac = agac->sol;
			else
				agac = agac->sag;
		}
		if (veri < sonkok->veri)
		{
			sonkok->sol = (struct node*)malloc(sizeof(struct node));
			sonkok->sol->sag=sonkok->sol->sol=NULL;
			sonkok = sonkok->sol;
			sonkok->veri = veri;
		}
		else
		{
			sonkok->sag =(struct node*)malloc(sizeof(struct node));
			sonkok->sag->sag=sonkok->sag->sol=NULL;
			sonkok = sonkok->sag;
			sonkok->veri = veri;
		}
	}
}
void create(struct node *t)
{
	t=(struct node*)malloc(sizeof(struct node));
	t->sag=t->sol=NULL;
}
void gosterinorder(struct node * a)
{
	if (a == NULL) return;
	else
	{
		gosterinorder(a->sol);
		printf("%d ",a->veri);		
		gosterinorder(a->sag);
	}
}

void gosterpostorder(struct node * a)
{
	if (a == NULL) return;
	else
	{
		gosterpostorder(a->sol);
		gosterpostorder(a->sag);
		printf("%d ",a->veri);
	}
}
void gosterpreorder(struct node * a)
{
	if (a == NULL) return;
	else
	{
		printf("%d ",a->veri);
		gosterpreorder(a->sol);
		gosterpreorder(a->sag);
	}
}
void min (struct node *a)
{
	if(a==NULL) printf("Agac boþ");
	else{
		while(a->sol->sol!=NULL)
		{
			a=a->sol;
		}
		printf("Min: %d",a->sol->veri);
	}
	
}
void max (struct node *a)
{
	if(a==NULL) printf("Agac boþ");
	else{
		while(a->sag->sag!=NULL)
		{
			a=a->sag;
		}
		printf("Min: %d",a->sag->veri);
	}
	
}
int main(){
	agac=NULL;
	kok=NULL;



	agac = kok;
	printf("PostOrder: ");
	gosterpostorder(agac);
	printf("\nInOrder: ");
	gosterinorder(agac);
	printf("\nPreOrder: ");
	gosterpreorder(agac);
	printf("\n");
	min(agac);
	printf("\n");
	max(agac);


}

