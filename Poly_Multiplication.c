#include<stdio.h>
#include<stdlib.h>
struct node{
	int coe, exp;
	struct node *next;
};
void multiplication(struct node **poly1,struct node **poly2,struct node **res);
void create_poly(struct node **head);
void display(struct node **head);

int main(){
	struct node *list1=NULL,*list2=NULL, *diff=NULL;
	printf("\n\t\t Polynomial Multiplication\n");
	printf("\n\t Polynomial-1 \n");
	create_poly(&list1);
	printf("\n\t Polynomial-2 \n");
	create_poly(&list2);
	display(&list1);
	display(&list2);
	multiplication(&list1,&list2,&diff);
	printf("\n\t Multiplication: ");
	display(&diff);
	return 0;
}

void create_poly(struct node **head){
	int n,i;
	struct node *newterm,*temp;
	printf("\n Number of terms:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("\n term - %d",i);
		newterm=(struct node*) malloc(sizeof(struct node));
		if(newterm!=NULL){
		  printf("\n Coefficient:");
		  scanf("%d",&newterm->coe);
		  printf(" Exponent:");
		  scanf("%d",&newterm->exp);
		  newterm->next = NULL;
		    if(*head==NULL)
		       *head=newterm;
		    else{
		    	temp=*head;
		    	while(temp->next!=NULL)
		    	   temp=temp->next;
		    	temp->next=newterm;
			}
			printf(" Newterm Inserted...!\n");
	   }
	}
}

void multiplication(struct node **poly1,struct node **poly2,struct node **res){
	struct node *temp,*temp1,*temp2,*newterm,*dup;
	temp2=*poly2;
	while(temp2!=NULL){
	 temp1=*poly1;
	  while(temp1!=NULL){
	  	newterm = (struct node*) malloc (sizeof(struct node));
	  	if(newterm!=NULL){
	  		newterm->coe = temp1->coe * temp2->coe;
	  	 	newterm->exp = temp1->exp + temp2->exp;
	  	 	newterm->next = NULL;
	  	    if(*res==NULL)
	  	      *res = newterm;
	  	    else{
	  	   		temp = *res;
	  	   		while(temp->next!=NULL)
	  	   		    temp=temp->next;
	  	   		    temp->next=newterm;
			}
	  	}
	  	temp1=temp1->next;
	  }
	  temp2=temp2->next;
	}	

	temp=*res;
	while (temp != NULL && temp->next != NULL) {
        temp1 = temp;
         while (temp1->next != NULL){
            if (temp->exp == temp1->next->exp){
                temp->coe = temp->coe + temp1->next->coe;
                dup = temp1->next;
                temp1->next = temp1->next->next;
                free(dup);
            }
            else
                temp1 = temp1->next;
        }
        temp = temp->next;
    }
}

void display(struct node **head){
	struct node *temp;
	if(*head==NULL){
		printf("\n Polynomial List is Empty..!");
		return;
	}
	temp=*head;
	printf("\n Polynomial: ");
	   while(temp!=NULL){
	   	  printf("%dX^%d  ",temp->coe,temp->exp);
	   	  if(temp->next!=NULL)
	   	     printf("+ ");
	   	  temp=temp->next;
	   }
}
