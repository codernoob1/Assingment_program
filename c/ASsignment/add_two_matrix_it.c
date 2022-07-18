/*********************************
Name : Saikat Mazumder
Program : Add two matrices
Program No. : 001
Date : 04.04.2022
*********************************/

#include<stdio.h>
#include<stdlib.h>

int **mem_alloc(int row,int col);
void input(int row,int col,int **A);
void display(int row,int col,int **A);
void add(int row,int col,int **P,int **Q,int **Res);

void main()
{
    int r1,c1,r2,c2,**X,**Y,**Z;

    do
    {
        printf("Enter no. of rows and columns for first matrix X :\n");
        scanf("%d %d",&r1,&c1);
        printf("Enter no. of rows and columns for second matrix Y :\n");
        scanf("%d %d",&r2,&c2);
    }while (r1!=r2 || c1!=c2);

    X = mem_alloc(r1,c1);
    Y = mem_alloc(r2,c2);
    Z = mem_alloc(r1,c2);
    printf("\nEnter elements for matrix X.\n");
    input(r1,c1,X);
    printf("\nEnter elements for matrix Y.\n");
    input(r2,c2,Y);

    printf("\nMatrix X =\n");
    display(r1,c1,X);
    printf("\nMatrix Y =\n");
    display(r2,c2,Y);
    add(r1,c1,X,Y,Z);
    printf("\nSum of  Matrix Z =\n");
    display(r1,c2,Z);
}

int **mem_alloc(int row,int col)
{
    int i,**A;
    A = (int**)calloc(row,sizeof(int*));
    for(i=0;i<row;i++)
        A[i] = (int*)calloc(col,sizeof(int));
    return A;
}
void input(int row,int col,int **A)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%d",&A[i][j]);
}
void display(int row,int col,int **A)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }
}
void add(int row,int col,int **P,int **Q,int **Res)
{
    int i,j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            Res[i][j] = P[i][j] + Q[i][j];
}

/*
output:
Enter no. of rows and columns for first matrix X :
2 2
Enter no. of rows and columns for second matrix Y :
2 2

Enter elements for matrix X.
1 2
9 10

Enter elements for matrix Y.
8 20
7 23

Matrix X =
1       2
9       10

Matrix Y =
8       20
7       23

Sum of  Matrix Z =
9       22
16      33
*/