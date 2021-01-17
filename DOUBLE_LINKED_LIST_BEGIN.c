// Doubly Linked List Insertion at the Begin or Start
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next,*prev;
};
void insert_begin(struct node **head,int ele);
void display(struct node **head);
void reverse(struct node **head);

int main(){
	struct node *list=NULL;
	int choice,ele;
	do{
		printf("\n\n\t Doubly Linked List Operations \n\t ------ ------ ---- ----------");
		printf("\n\n 1. Insert @ Begin \t 2. Traverse \t 3. Revers Traverse \t 4. Exit\n");
		printf("\n Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					printf(" Enter New Element:");
					scanf("%d",&ele);
					insert_begin(&list,ele);
					break;
			case 2:
					display(&list);			
					break;
			case 3:
					reverse(&list);
					break;
			case 4:
					printf("\n Thank You..!");
					break;
		}
	}while(choice!=4);
  return 0;
}

//Create Linked List insertion at the Begin
void insert_begin(struct node **head,int ele){
	struct node *newnode;
		newnode = (struct node*) malloc (sizeof(struct node));
		if(newnode!=NULL){
			newnode->data = ele;
			newnode->prev = NULL;
			newnode->next = *head;
			if(*head!=NULL)
				(*head)->prev=newnode;
			*head = newnode;
			printf(" Newnode is inserted...!");
		}
}

// Display or Traverse the single linked list
void display(struct node **head){
	struct node *temp;	
	if(*head==NULL){
		printf("list is Empty....!");
		return;
	}
	printf("\n\n List of Elements:");
	temp= *head;
	   while(temp!=NULL){
	   	   printf("\t%d ",temp->data);
	   	   temp = temp->next;
		}
}

// Functiont to reverse the Doubly Linked List
void reverse(struct node **head){
	struct node *temp,*temp1,*duplicate;
	temp=*head;
	if(temp!=NULL){
		while(temp->next!=NULL)
	   		temp=temp->next;
		printf("\n\n Reversing the List:");
		while(temp!=NULL){
			printf("\t%d",temp->data);
			temp=temp->prev;
		}
	}
	else{
		printf("\n\n List is Empty....!");
	}
}
