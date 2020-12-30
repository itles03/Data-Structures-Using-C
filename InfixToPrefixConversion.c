#include<stdio.h> 
#include<ctype.h> 
#define SIZE 50 
void strreverse(char []);

char stack[SIZE]; 
int top=-1; 

void push(char elem) { 
     stack[++top]=elem; 
} 

char pop(){ 
      return(stack[top--]); 
} 

int pr(char elem){ 
      switch(elem) { 
	        case '(': return 1; 
			case '+': 
			case '-': return 2; 
			case '*': 
			case '/': return 3; 
			case '^': return 4; 
		}
} 
		
void main() { 
   char infx[50],pofx[50],ch,elem; 
   int i=0,k=0; 
   
   printf("\n\nRead the Infix Expression ? "); 
       scanf("%s",infx);
   strreverse(infx);
	while( (ch=infx[i++]) != '\0') { 
		if( ch == '(') // character is open parenthesis ‘(‘ 
			push(ch); 
		else if(isalnum(ch)) // character is an Operand (a-z) 
		    pofx[k++]=ch; 
		else if( ch == ')') { // character is closed parenthesis ‘)‘ 
		        while(stack[top] != '(') 
				      pofx[k++]=pop(); 
					  elem=pop(); 
			} 
		else { 
		    if(top==-1) 
			    push(ch); 
			else {
			     while( pr(stack[top]) >= pr(ch) ) // Compare Operator Priority 
				       pofx[k++]=pop(); 
					push(ch); 
				} 
		}
	} 
	
	while( top>=0) // Pending Operators pop from the Stack 
	  pofx[k++]=pop(); 
	  
	 pofx[k]='\0'; 
	 strreverse(pofx);
	printf("\n Prefix Expn: %s\n",pofx); 
}

void strreverse(char str[]){
	int i,j,k;
	char t;
	for(i=0;str[i]!='\0';i++);
	for(j=0,k=i-1;j<i/2;j++,k--){
	   t=str[k];
	   str[k]=str[j];
	   str[j]=t;
	}
}
