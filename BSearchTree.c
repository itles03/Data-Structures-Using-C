#include<stdlib.h>
#include<stdio.h>

typedef struct tree_node *tptr;

struct tree_node{
 int element;
 tptr left;
 tptr right;
 };
typedef tptr search_tree;

search_tree make_null(){
        return NULL;
}

tptr find(int x,search_tree t){
    if(t==NULL)
        return NULL;
    if (x <  t -> element)
        return(find(x,t->left));
    else
        if(x>t->element)
            return(find(x,t->right));
        else
            return t;
}

tptr find_min(search_tree t) {
    if(t==NULL)
       return NULL;
    else
       if(t->left==NULL)
          return(t);
       else
          return(find_min(t->left));
}

tptr find_max(search_tree t){
    if(t!=NULL)
        while(t->right!=NULL)
            t=t->right;
        return t;
}

tptr insert(int x,search_tree t){
    if(t==NULL) {
        t=(search_tree)malloc(sizeof(struct tree_node));
        if(t==NULL)
          printf("\n out of space:");
        else {
    	   t-> element = x;
           t-> left = t -> right = NULL;
        }
    }
    else
        if(x<t->element)
            t->left=insert(x,t->left);
        else
           if(x>t->element)
                t -> right = insert ( x , t -> right);
        return t;
}

tptr delete(int x,search_tree t){
    tptr t1,temp,child;
    t1=t;
      if(t1==NULL)
         printf("\n element not found");
      else
        if ( x < t1 -> element)
              t1 -> left = delete ( x , t1 -> left);
        else
           if(x>t1->element)
              t1->right=delete(x,t1->right);
           else
             if((t1->left)&&(t1->right)){
                 temp = find_min ( t1 -> right);
                 t1 -> element = temp -> element;
                 t1->right=delete(t1->element,t1->right);
              }
              else {
                 temp=t1;
                 if(t1->left==NULL)
                    child=t1->right;
                 if(t1->right==NULL)
                    child=t1->left;
                 free(temp);
                 return(child);
            }
        return t;
  }

void print_tree(tptr t,int level){
    int i;
    if(t){
        print_tree(t->right,level+1);
        printf("\n");
        for(i=0;i<level;i++)
            printf("  ");
        printf(" %d",t->element);
        print_tree ( t -> left , level+1 );
     }
}

void preorder(tptr t) {
    if(t!= NULL){
      printf("%d\t",t->element);
      preorder(t->left);
      preorder(t->right);
    }
}
                   
void inorder(tptr t){
    if(t!= NULL){
      inorder(t->left);
      printf("%d\t",t->element);
      inorder(t->right);
	}
}

void postorder(tptr t){
    if(t!=NULL){
      preorder(t->left);
      preorder(t->right);
      printf("%d\t",t->element);
    }
}

int main(){
    search_tree t;
    tptr a;
    int level=0;
    int option,x;
                      
    t = make_null();
    do{
      printf("\n\t\t Binary Search Tree Operations \n\t\t ------ ------ ---- ----------");
      printf("\n 1.insert an element \n 2.delete an element");
      printf("\n 3.print  bstree \n 4.print  preorder");
      printf("\n 5.print postorder \n 6.print inorder");
      printf("\n 7.quit from the program");
      printf("\n\n\t enter your option:");
      scanf("%d",&option);
           switch(option){
            case 1: printf("\n enter element to be inserted");
				    scanf("%d",&x);
	                t=insert(x,t);
	                print_tree(t,level);
	                break;
            case 2: if(t==NULL)
	                    printf("\n TREE IS EMPTY");
	                else{
	                   printf(" enter element to be deleted");
	                   scanf("%d",&x);
	                   a = find ( x , t );
	                   if(a){
	                       t=delete(x,t);
	                       printf("\n deleted element is: %d",x);
	                       print_tree(t,level);
                         }
	                   else
	                       printf("\n element not found: ");
	                }
	                break;
            case 3: print_tree(t,level);
	  			    break;
			case 4: printf("\n Preorder is:\n");
	  			    preorder(t);
	  			    break;
   			case 5: printf("\n postorder is:\n ");
				    postorder(t);
	 			    break;
   			case 6: printf("\n inorder is:\n");
				    inorder(t);
				    break;
			default: printf("\n select option from menu");
				     break;
  		}
  	}while(option!=7);
  printf("\n GOOD BYE");
}
