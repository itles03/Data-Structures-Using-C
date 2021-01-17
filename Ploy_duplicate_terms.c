//Remove the duplicate terms in the Polynomial 
/*Application 
	if exponents are equal then 
	   Add coefficients & remove the duplicate equivalent terms
  
	Polynomial = 3X^3 + 3X^2 +9X^3 -4X^2 + 4X^1 + 5
	After Performing Deletion: 12X^3 - X^2 + 4X^1 + 5
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
	int coe, exp;
	struct node *next;
};

void create_poly(struct node **ploy);
void display(struct node **ploy);
void remove_duplicate(struct node **poly);

int main(){
	struct node *list=NULL;
	create_poly(&list);
	display(&list);
	remove_duplicate(&list);
	display(&list);
  return 0;
}

//Create Polynomial using Linked List
void create_poly(struct node **poly){
	int terms,i;
	struct node *newterm,*temp;
	printf("\n Number of Terms in Polynomial:");
	scanf("%d",&terms);
	for(i=1;i<=terms;i++){
		printf("\n\n \t Term-%d:\n",i);
		newterm= (struct node*) malloc (sizeof(struct node));
		if(newterm!=NULL){
			printf("\n Coefficient:");
			scanf("%d",&newterm->coe);
			printf("\n Exponent:");
			scanf("%d",&newterm->exp);
			newterm->next=NULL;
			if(*poly==NULL)
			   *poly = newterm;
			else{
				temp=*poly;
				while(temp->next!=NULL)
				    temp= temp->next;
				temp->next = newterm;
			}
			printf("\n New term is inserted...!");
		}
	}
}

// Display or Travers the Polynomial
void display(struct node **poly){
	struct node *temp;
	
	if(*poly==NULL){
		printf("list is Empty....!");
		return;
	}
	printf("\n\n Given Polynomial:");
	temp= *poly;
	   while(temp!=NULL){
	   	   printf(" %dX^%d ",temp->coe,temp->exp);
	   	   if(temp->next!=NULL)
	   	      printf(" + ");
	   	   temp = temp->next;
		}
}

//Remove the duplicate terms
void remove_duplicate(struct node **poly){
	struct node *temp,*temp1,*duplicate;
	temp=*poly;
	while (temp != NULL && temp->next != NULL) {
        temp1 = temp;
         while (temp1->next != NULL){
            if (temp->exp == temp1->next->exp){
                temp->coe = temp->coe + temp1->next->coe;
                duplicate = temp1->next;
                temp1->next = temp1->next->next;
                free(duplicate);
            }
            else
                temp1 = temp1->next;
        }
        temp = temp->next;
    }
}
