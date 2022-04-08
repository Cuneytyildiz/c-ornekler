#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *sol;
	struct node *sag;
};

struct node *yenidugum(int deger){
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=deger;
	temp->sag=NULL;
	temp->sol=NULL;
	return temp;
}

struct node *ekle(struct node *root,int deger){
	if(root==NULL){
		root = yenidugum(deger);
	}
	else if(deger<root->data){
		root->sol=ekle(root->sol,deger);
	}
	else if(deger>root->data){
		root->sag=ekle(root->sag,deger);
	}
	
	return root;
	
}


void inorder(struct node *root){
	// sol tarafta ilerle
	if(root->sol != NULL){
		inorder(root->sol);
	}
	
	// kökü yaz
	printf("%d",root->data);
	
	// sað tarafta ilerle
	if(root->sag!=NULL){
		inorder(root->sag);
	}
}

void preorder(struct node *root){
	// kökü yaz
	printf("%d",root->data);
	
	// sol tarafta ilerle
	if(root->sol!=NULL){
		preorder(root->sol);
	}
	
	// sað tarafta ilerle
	if(root->sag!=NULL){
		preorder(root->sag);
	}
	
}

void postorder(struct node *root){
	// sol tarafta ilerle
	if(root->sol != NULL){
		postorder(root->sol);
	}
	
	// sað tarafta ilerle
	if(root->sag!=NULL){
		postorder(root->sag);
	}
	
	// kökü yaz
	printf("%d",root->data);
}

int main(){
	struct node *root= NULL;
	
	root = ekle(root,5);
	ekle(root,3);
	ekle(root,7);
	ekle(root,4);
	ekle(root,6);
	ekle(root,9);
	ekle(root,15);
	
	printf("InOrder Siralama : ");
	inorder(root);
	printf("\nPreOrder Siralama : ");
	preorder(root);
	printf("\nPostOrder Siralama : ");
	postorder(root);

	return 0;
}



