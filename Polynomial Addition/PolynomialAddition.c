#include <stdio.h>
#include<stdlib.h>

struct Node{
  int coeff;
  int exp;
  struct Node* link;
};

//Function for New Node Creation
struct Node* getNode(int n1,int n2){
	struct Node* Nd=(struct Node*)malloc(sizeof(struct Node));
	Nd->coeff=n1;
	Nd->exp=n2;
	Nd->link=NULL;
	return Nd;
}

//Function for traversal
void traverse(struct Node* head){
  struct Node* temp=head;
  while(temp->link!=NULL){
    printf("%dx^%d + ",temp->coeff,temp->exp);
    temp=temp->link;
  }
  printf("%dx^%d",temp->coeff,temp->exp);
  printf("\n");
}

//Function for insertion at ending
struct Node* insertatend(struct Node* head,int n1,int n2){
  if(head==NULL){
  	struct Node* partial=(struct Node*)malloc(sizeof(struct Node));
    partial->coeff=n1;
    partial->exp=n2;
    partial->link=NULL;
    return partial;
  }
  struct Node* partial=(struct Node*)malloc(sizeof(struct Node));
  partial->coeff=n1;
  partial->exp=n2;
  struct Node* temp=head;
  while(temp->link!=NULL){
    temp=temp->link;
  }
  temp->link=partial;
  partial->link=NULL;
  return head;
}

//Function for adding Polynomials
struct Node* pAdd(struct Node* head1,struct Node* head2){
	struct Node* ptr1=head1;
	struct Node* ptr2=head2;
	struct Node* newhead=NULL;
	while(ptr1!=NULL && ptr2!=NULL){
		if(ptr1->exp==ptr2->exp){
		newhead=insertatend(newhead,(ptr1->coeff+ptr2->coeff),ptr1->exp);
		ptr1=ptr1->link;
		ptr2=ptr2->link;
		}
		else if(ptr1->exp>ptr2->exp){
		newhead=insertatend(newhead,ptr1->coeff,ptr1->exp);
		ptr1=ptr1->link;	
		}
		else if(ptr1->exp<ptr2->exp){
		newhead=insertatend(newhead,ptr2->coeff,ptr2->exp);
		ptr2=ptr2->link;	
		}		
	}
	while(ptr1!=NULL){
		newhead=insertatend(newhead,ptr1->coeff,ptr1->exp);
		ptr1=ptr1->link;	
		}
	while(ptr2!=NULL){
		newhead=insertatend(newhead,ptr2->coeff,ptr2->exp);
		ptr2=ptr2->link;	
		}
	return newhead;
}

int main()
{	
  //Creation of first single Linked List
  struct Node* first1=(struct Node*)malloc(sizeof(struct Node));
  first1->coeff=10;
  first1->exp=5;
  struct Node* second1=(struct Node*)malloc(sizeof(struct Node));
  second1->coeff=30;
  second1->exp=4;
  struct Node* third1=(struct Node*)malloc(sizeof(struct Node));
  third1->coeff=50;
  third1->exp=3;
  struct Node* fourth1=(struct Node*)malloc(sizeof(struct Node));
  fourth1->coeff=70;
  fourth1->exp=2;
  
  //Creation of second single Linked List using getNode() function
  struct Node* first2=getNode(20,4);
  struct Node* second2=getNode(40,3);
  struct Node* third2=getNode(60,2);
  struct Node* fourth2=getNode(80,1);
  
  //Head Node:
  struct Node* head1=first1;
  struct Node* head2=first2;
  
  //Linking:
  
  //For first Linked List
  first1->link=second1;
  second1->link=third1;
  third1->link=fourth1;
  fourth1->link=NULL;
  
  //For second Linked List
  first2->link=second2;
  second2->link=third2;
  third2->link=fourth2;
  fourth2->link=NULL;
  
  printf("The first Polynomial is:\n");
  traverse(head1);
  printf("The second Polynomial is:\n");
  traverse(head2);
 
  printf("After addition :\n");
  struct Node* sum=pAdd(head1,head2);
  traverse(sum); 
 return 0; 
}