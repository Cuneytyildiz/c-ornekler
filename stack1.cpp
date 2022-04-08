#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *push(struct node *s,int deger){
	struct node *ilk;
	ilk=s;
	
	if(s==NULL){
		s = (struct node *)malloc(sizeof(struct node));
		s->data=deger;
		s->next=NULL;
		return s;
	}
	else{
		while(s->next!=NULL){
			s = s->next;
		}
		s->next=(struct node *)malloc(sizeof(struct node));
		s=s->next;
		s->data=deger;
		s->next=NULL;
		return ilk;
	}
}

void pop(struct node *s){
	struct node *temp;	
	if(s->next==NULL){
		
		printf(" %d ",s->data);
		free(s);
	}
	else{
		while(s->next->next!=NULL)
		s=s->next;
		temp=s->next;
		s->next=NULL;
			
		printf(" %d ",temp->data);
		free(temp);
		
	}
}

int main(){
	struct node *stack;
	stack=NULL;
	
	stack=push(stack,1);
	stack=push(stack,2);
	stack=push(stack,3);
	stack=push(stack,4);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	return 0;
}
