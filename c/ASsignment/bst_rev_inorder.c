
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
void Inorder(tree *bst);
void revIndorder(tree *bst);


int main(){

    tree *root = NULL;
    int ch,num;

    do{
      printf("\n1. Insert Element\n");
      printf("2. sort the tree in ascending order\n");  
      printf("3. Sort data in descending order \n");
      printf("4. Exit \n");

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
            printf("\nsort the tree in ascending order : \n");
            Inorder(root);
            printf("\n");
            break;
        case 3:
            printf("\nSort data in descending order : \n");
            revIndorder(root);
            printf("\n");
            break;
        case 4:
            break;
      default:
        printf("\nEnter correct choice\n");
          break;
      }
    }while(ch!=4);
    
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


void Inorder(tree *bst)
{
	if(bst != NULL)
	{
		Inorder(bst->left);
		printf("%d  ",bst->data);
		Inorder(bst->right);
	}
}
void revIndorder(tree *bst){
    if(bst != NULL){
        revIndorder(bst->right);
        printf("%d  ",bst->data);
        revIndorder(bst->left);
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
30

Enter correct choice

1. Insert Element
2. Pre-order Traversal
3. In-order Traversal
4. Post-order Traversal
5. Exit 

Enter your choice :
1

Enter a value : 30

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

Enter a value : 60

1. Insert Element
2. Pre-order Traversal
3. In-order Traversal
4. Post-order Traversal
5. Exit 

Enter your choice :
1

Enter a value : 10

1. Insert Element
i_am_saikat@iamsaikat-HP-Laptop-15-db1xxx:~/Documents/c/ASsignment$ g
cc pro0012.c
i_am_saikat@iamsaikat-HP-Laptop-15-db1xxx:~/Documents/c/ASsignment$ ./a.out

1. Insert Element
2. sort the tree in ascending order
3. Sort data in descending order 
4. Exit 

Enter your choice :
1

Enter a value : 50

1. Insert Element
2. sort the tree in ascending order
3. Sort data in descending order 
4. Exit 

Enter your choice :
1

Enter a value : 20

1. Insert Element
2. sort the tree in ascending order
3. Sort data in descending order 
4. Exit 

Enter your choice :
1

Enter a value : 60

1. Insert Element
2. sort the tree in ascending order
3. Sort data in descending order 
4. Exit 

Enter your choice :
1

Enter a value : 30

1. Insert Element
2. sort the tree in ascending order
3. Sort data in descending order 
4. Exit 

Enter your choice :
1

Enter a value : 40

1. Insert Element
2. sort the tree in ascending order
3. Sort data in descending order 
4. Exit 

Enter your choice :
2

sort the tree in ascending order : 
20  30  40  50  60  

1. Insert Element
2. sort the tree in ascending order
3. Sort data in descending order 
4. Exit 

Enter your choice :
3

Sort data in descending order : 
60  50  40  30  20  

1. Insert Element
2. sort the tree in ascending order
3. Sort data in descending order 
4. Exit 

Enter your choice :
4
*/