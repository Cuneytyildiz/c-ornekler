#include <stdio.h>
#include <stdlib.h>

struct node {
	
	int veri;
	struct node *next;
	
};

struct que{
	
	
	struct node *front;
	struct node *rear;
	
};
struct que *q;
void enq(int deger){
	if(q->rear==NULL)
	{
		q->rear=(struct node*)malloc(sizeof(struct node));
		q->rear->veri=deger;
		q->rear->next=NULL;
		q->front=q->rear;
	}
	else{
		
		q->rear->next=(struct node*)malloc(sizeof(struct node));
		q->rear=q->rear->next;
		q->rear->veri=deger;
		q->rear->next=NULL;
	}
	
}
void deq(){
	int s;
	struct node *temp;
	if(q->front==NULL) printf("\n kuyrukta silincek bir eleman yok.");
	else{
		
		s=q->front->veri;
		temp=q->front;
		q->front=q->front->next;
		free(temp);
		printf("\n %d",s);
	}
	
	
	
}
int main(){
	
	q=(struct que*)malloc(sizeof(struct que));
	q->front=q->rear=NULL;
	
	enq(5);
	enq(6);
	enq(15);	
	enq(3);	
	enq(8);
	
	deq();
	deq();
	deq();
	deq();
	deq();
	deq();





	
	
	
	return 0;	
}
