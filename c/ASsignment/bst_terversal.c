
/*********************************
Name : Saikat Mazumder
Program : inorder ,preoder , postoder in bst
Program No. : 001
Date : 04.05.2022
*********************************/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node tree;
tree *insert(tree *bst,int value);
void preorder(tree *bst);
void Inorder(tree *bst);
void postorder(tree *bst);


int main(){

    tree *root = NULL;
    int ch,num;

    do{
      printf("\n1. Insert Element\n");
      printf("2. Pre-order Traversal\n");  
      printf("3. In-order Traversal\n");
      printf("4. Post-order Traversal\n");
      printf("5. Exit \n");

      printf("\nEnter your choice :\n");
      scanf("%d",&ch);

      switch (ch)
      {
      case 1:
          printf("\nEnter a value : ");
          scanf("%d",&num);
          root = insert(root,num);
          break;
      case 2:
            printf("\nPre-order Traversal : \n");
            preorder(root);
            printf("\n");
            break;

        case 3:
            printf("\nIn-order Traversal : \n");
            Inorder(root);
            printf("\n");
            break;
        case 4:
            printf("\nPost-order Traversal : \n");
            postorder(root);
            printf("\n");
            break;
        case 5:
            break;
      default:
        printf("\nEnter correct choice\n");
          break;
      }
    }while(ch!=5);
    
    return 0;

}
tree *insert(tree *bst,int value){
    if(bst == NULL){
        tree  *newNode = (tree*) calloc(1,sizeof(tree));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    else{
        if(bst->data >value){
            bst->left = insert(bst->left,value);

        }else{
            bst->right = insert(bst->right,value);
        }
    }
    return bst;
}
void preorder(tree *bst)
{
	if(bst != NULL)
	{
		printf("%d  ",bst->data);
		preorder(bst->left);
		preorder(bst->right);
	}
}

void Inorder(tree *bst)
{
	if(bst != NULL)
	{
		Inorder(bst->left);
		printf("%d  ",bst->data);
		Inorder(bst->right);
	}
}

void postorder(tree *bst)
{
	if(bst != NULL)
	{
		postorder(bst->left);
		postorder(bst->right);
		printf("%d  ",bst->data);
	}
}
/*
output:

1. Insert Element
2. Pre-order Traversal
3. In-order Traversal
4. Post-order Traversal
5. Exit 

Enter your choice :
1

Enter a value : 20

1. Insert Element
2. Pre-order Traversal
3. In-order Traversal
4. Post-order Traversal
5. Exit 

Enter your choice :
1 

Enter a value : 12

1. Insert Element
2. Pre-order Traversal
3. In-order Traversal
4. Post-order Traversal
5. Exit 

Enter your choice :
1

Enter a value : 50

1. Insert Element
2. Pre-order Traversal
3. In-order Traversal
4. Post-order Traversal
5. Exit 

Enter your choice :
1

Enter a value : 69

1. Insert Element
2. Pre-order Traversal
3. In-order Traversal
4. Post-order Traversal
5. Exit 

Enter your choice :
1

Enter a value : 45

1. Insert Element
2. Pre-order Traversal
3. In-order Traversal
4. Post-order Traversal
5. Exit 

Enter your choice :
1

Enter a value : 45

1. Insert Element
2. Pre-order Traversal
3. In-order Traversal
4. Post-order Traversal
5. Exit 

Enter your choice :
2

Pre-order Traversal : 
20  12  50  45  45  69  

1. Insert Element
2. Pre-order Traversal
3. In-order Traversal
4. Post-order Traversal
5. Exit 

Enter your choice :
3

In-order Traversal : 
12  20  45  45  50  69  

1. Insert Element
2. Pre-order Traversal
3. In-order Traversal
4. Post-order Traversal
5. Exit 

Enter your choice :
4

Post-order Traversal : 
12  45  45  69  50  20  

1. Insert Element
2. Pre-order Traversal
3. In-order Traversal
4. Post-order Traversal
5. Exit 

Enter your choice :
5
*/