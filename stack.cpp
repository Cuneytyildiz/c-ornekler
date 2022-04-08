#include <stdio.h>
#include <stdlib.h>
#define STACK_BOYUT 10


typedef struct{

	int veri[STACK_BOYUT];
	int top;

}stack;


stack *StackOlustur() {
	stack *s = (stack *)malloc(sizeof(stack));
	s->top = -1;
	return s;

}

void push(stack *s,int deger) {
	//stackte yer var mý kontrol edilir

	if (s->top < STACK_BOYUT - 1) //stackte yer olma durumu
	{
		s->top++;
		s->veri[s->top] = deger;
	}
	else //stack'in dolu olma durumu
	{
		printf("Stack Dolu! %d eklenemedi \n",deger);
	}
		
}

int pop(stack *s) {
	//stackte eleman var mý yok mu kontrol edilir

	if (s->top == -1) { //stack'in boþ olma durumu
		printf("Stack bos \n");
		return NULL;
	}
	else { //stack'te eleman olma durumu
		int x = s->veri[s->top];
		s->top--;
		return x;
	}


}








int main() {

	stack *S = StackOlustur();

	push(S, 1);
	push(S, 3);
	push(S, 5);
	push(S, 7);
	push(S, 9);
	push(S, 11);
	push(S, 1);
	push(S, 3);
	push(S, 5);
	push(S, 7);
	pop(S);
	pop(S);
	push(S, 9);
	push(S, 11);
	

	int a = pop(S);
	printf("\n %d ",a);

	a = pop(S);
	printf("\n %d ", a);


	a = pop(S);
	printf("\n %d ", a);

	return 0;
}
