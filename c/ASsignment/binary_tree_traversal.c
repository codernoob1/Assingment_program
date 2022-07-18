
/*********************************
Name : Saikat Mazumder
Program : inorder ,preoder , postoder in binary tree
Program No. : 001
Date : 04.05.2022
*********************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};


struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}


void printPostorder(struct node* node)
{
	if (node == NULL)
		return;

	printPostorder(node->left);

	printPostorder(node->right);

	printf("%d ", node->data);
}

void printInorder(struct node* node)
{
	if (node == NULL)
		return;

	printInorder(node->left);

	printf("%d ", node->data);

	printInorder(node->right);
}


void printPreorder(struct node* node)
{
	if (node == NULL)
		return;

	printf("%d ", node->data);

	printPreorder(node->left);

	printPreorder(node->right);
}


int main()
{
	struct node* root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(35);
	root->left->left = newNode(40);
	root->left->right = newNode(55);

	printf("\nPreorder traversal of binary tree is \n");
	printPreorder(root);

	printf("\nInorder traversal of binary tree is \n");
	printInorder(root);

	printf("\nPostorder traversal of binary tree is \n");
	printPostorder(root);
    printf("\n");
	
	return 0;
}
/*
output:

Preorder traversal of binary tree is 
10 20 40 55 35 
Inorder traversal of binary tree is 
40 20 55 10 35 
Postorder traversal of binary tree is 
40 55 20 35 10 
*/
