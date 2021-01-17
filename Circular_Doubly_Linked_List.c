//Circular Double Linked List Insertion & Traversing Operations
#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node *next,*prev;
};

void insert_begin(struct node **head, int num);
void insert_end(struct node **head, int num);
void insert_mid(struct node **head, int num);
void display(struct node **head);

int main() {
  int choice,input;
  struct node *ptr;
  ptr=NULL;
  do{
  printf("\n\n\t Circular Doubly Linked List \n\t -------- ------ ------ ---\n");
  printf("\n 1. Insert at Begin 2. Insert at end 3. Insert at Mid 4. display");
  printf("\n\n Enter your choice:");
  scanf("%d",&choice);
  		  
   		switch(choice) {
			case 1: printf("\n New Node: ");
		  			scanf("%d",&input);
		  			insert_begin(&ptr,input);
					break;
			case 2: printf("\n New Node: ");
		  			scanf("%d",&input);
					insert_end(&ptr,input);
					break;
			case 3: printf("\n New Node: ");
		  			scanf("%d",&input);
		  			insert_mid(&ptr,input);
					break;
			case 4: display(&ptr);
					break;
    	}
   }while(choice<=4);
  return 0;
}

//Insert the Newnode at the Begin of the CLL
void insert_begin(struct node **head, int num){
  struct node *newnode,*temp;
  newnode=(struct node*)malloc(sizeof(struct node));
  if(newnode==NULL){
     printf("\n Memory Not available");
     return;
   }
   newnode->data=num;
   if(*head==NULL){
	*head=newnode;
	newnode->prev=*head;
	newnode->next=*head;
   } else{
      temp=*head;
       while(temp->next!=*head)
	  		temp=temp->next;

	  	temp->next=newnode;
	  	newnode->prev=temp;
	  	newnode->next=*head;
	  	(*head)->prev=newnode;
	  	*head=newnode;
   }
}

//Insertion at the end of CLL
void insert_end(struct node **head, int num){
  struct node *newnode,*temp;
  newnode=(struct node*)malloc(sizeof(struct node));
  if(newnode==NULL){
     printf("\n Memory Not available");
     return;
   }
   newnode->data=num;
   if(*head==NULL){
      newnode->prev=newnode;
      newnode->next=newnode;
      *head=newnode;
   }
   else{
      temp=*head;
      while(temp->next!=*head)
	  	temp=temp->next;

      temp->next=newnode;
      newnode->prev=temp;
      newnode->next= *head;
      (*head)->prev=newnode;
   }
}

//Insertion at the Middle of the CLL
void insert_mid(struct node **head, int num){
  int count=0,mid,loc=0;
  struct node *temp,*newnode,*t;
  if(*head==NULL || (*head)->next==*head){
  	insert_begin(head,num);
  	return;
  }
  temp=*head;
  	while(temp->next!=*head){
	  temp=temp->next;
	  count++;
	}
	count++;
      temp=*head;
      mid=count/2;
      		while(loc<mid){
       		 t=temp;
       		 temp=temp->next;
      		  loc++;
      		}
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->data=num;
      newnode->next=temp;
      newnode->prev=t;
      t->next=newnode;
      temp->prev=newnode;
      printf("\n Node is Inserted...!");
}

// Traversing the CLL
void display(struct node **head){
   struct node *temp;
   temp=*head;
   if(temp==NULL)
     printf("\n List is Empty...!");
   else{
   	 printf("\n List Elements : ");
     while(temp->next!=*head){
	printf("--> %d",temp->data);
	temp=temp->next;
      }
      printf("--> %d",temp->data);
   }
}
