// Remove duplicate nodes in the single linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
void create_list(struct node **head,int ele);
void display(struct node **head);
void remove_duplicate(struct node **head);

int main(){
	struct node *list=NULL;
	int choice,ele;
	do{
		printf("\n\n\t Linked List Operations \n\t ------ ---- ----------");
		printf("\n\n 1. Insert \t 2. Display \t 3. Remove Duplicate \t 4. Exit\n");
		printf("\n Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					printf(" Enter New Element:");
					scanf("%d",&ele);
					create_list(&list,ele);
					break;
			case 2:
					display(&list);			
					break;
			case 3:
					remove_duplicate(&list);
					break;
			case 4:
					printf("\n Thank You..!");
					break;
		}
	}while(choice!=4);
  return 0;
}

//Create Linked List insertion at the end
void create_list(struct node **head,int ele){
	struct node *newnode,*temp;
		newnode= (struct node*) malloc (sizeof(struct node));
		if(newnode!=NULL){
			newnode->data=ele;
			newnode->next=NULL;
			if(*head==NULL)			          //Very First Node in the list
			   *head = newnode;
			else{
				temp=*head;
				while(temp->next!=NULL)	         //Traverse the List
				    temp= temp->next;
				temp->next = newnode;		//Insert at the end
			}
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
	printf("\n\n Single Linked List:");
	temp= *head;
	   while(temp!=NULL){
	   	   printf(" %d\t ",temp->data);
	   	   temp = temp->next;
		}
}

/* Functiont to remove duplicate nodes in the single linked list*/
void remove_duplicate(struct node **head){
	struct node *temp,*temp1,*duplicate;
	temp=*head;
	while (temp != NULL && temp->next != NULL) {
        temp1 = temp;
         while (temp1->next != NULL){
            if (temp->data == temp1->next->data)	                //identify the duplicate
			{	
                duplicate = temp1->next;
                temp1->next = temp1->next->next;
                free(duplicate);					// remove the duplicate
            }
            else
                temp1 = temp1->next;
        }
        temp = temp->next;
    }
    printf("\n Duplicates are Deleted..!");
}
