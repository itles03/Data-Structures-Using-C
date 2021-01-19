//Delete a specific element Doubly Linked List 
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next,*prev;
};
void insert_begin(struct node **head,int ele);
void display(struct node **head);
void delete_specific(struct node **head,int specific);

int main(){
	struct node *list=NULL;
	int choice,ele;
	do{
		printf("\n\n\t Doubly Linked List Operations \n\t ------ ------ ---- ----------");
		printf("\n\n 1. Insert @ Begin \t 2. Traverse \t 3. Delete Specific Element \t 4. Exit\n");
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
			case 3: printf("\n Node to be delete:");
					scanf("%d",&ele);
					delete_specific(&list,ele);
					break;
			case 4:
					printf("\n Thank You..!");
					break;
		}
	}while(choice!=4);
  return 0;
}

//Insert a new node at the begin
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

//Traverse Double Linked List
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

//Delete Specific Element in the DLL
void delete_specific(struct node **head,int specific){
	struct node *temp,*temp1;
	temp=*head;
		while(temp!=NULL){
			if(temp->data==specific) //Search for specific Element
			{
				if(temp->prev==NULL){
					if(temp->next==NULL) // Only One Element in the List
					{
					   *head=NULL;
					   printf(" %d is Deleted",temp->data);
					   free(temp);
					   return;
				     } else{			// First Element to be delete
						temp1=temp;
						temp->next->prev = NULL;
						*head = temp->next;
						printf(" %d is Deleted",temp1->data);
					 	free(temp1);
					 	return;
					}
				}
				else if(temp->next==NULL){	// Last element to be delete
					temp->prev->next=NULL;
					printf(" %d is Deleted",temp->data);
					free(temp);
					return;
				}
				else{							// Intermediate node
					temp->prev->next=temp->next;
					temp->next->prev=temp->prev;
					printf(" %d is Deleted",temp->data);
					free(temp);
					return;
				}
			}
			temp=temp->next;
		}
	printf("\n Node Not Found...!");
}
