#include<stdio.h>
#include<stdlib.h>
struct node{
	int coe, exp;
	struct node *next;
};
void differentiation(struct node **ploy,struct node **diff);
void create_poly(struct node **head);
void display(struct node **head);

int main(){
	struct node *list=NULL, *diff=NULL;
	printf("\n\t Polynomial Differentiation \n");
	create_poly(&list);
	display(&list);
	differentiation(&list,&diff);
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
void differentiation(struct node **poly,struct node **diff){
	struct node *temp,*temp1,*newterm;
	temp1=*poly;
	printf("\n Polynomial Differentiation :");
	while(temp1!=NULL){
		if(temp1->exp==0)
		   return;
		newterm=(struct node*) malloc(sizeof(struct node));
		if(newterm!=NULL){
		  newterm->coe = temp1->coe * temp1->exp;
		  newterm->exp = temp1->exp -1;
		  newterm->next = NULL;
		    if(*diff==NULL)
		       *diff=newterm;
		    else{
		    	temp=*diff;
		    	while(temp->next!=NULL)
		    	   temp=temp->next;
		    	temp->next=newterm;
			}
	   }
	  temp1=temp1->next;
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
