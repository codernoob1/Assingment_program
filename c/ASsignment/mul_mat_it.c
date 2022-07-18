/*********************************
Name : Saikat Mazumder
Program : multiply two matrices
Program No. : 001
Date : 04.04.2022
*********************************/
#include<stdio.h>
#include<stdlib.h>
void input(int row,int col,int **A);
void display(int row,int col,int **A);
int **mem_alloc(int row,int col);
void multiply(int r1,int r2,int c1,int c2,int **P,int **Q,int **Res);
int main(){
    int r1,r2,c1,c2,**X,**Y,**Z;
   
    printf("Enter no. of rows and columns for first matrix X :\n");
    scanf("%d %d",&r1,&c1);
    printf("Enter no. of rows and columns for second matrix Y :\n");
    scanf("%d %d",&r2,&c2);
   if(c1!=r2){
       printf("Invalid Input\n");
   }
   else{

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
    printf("\nResultant Matrix : \n");
    multiply(r1,r2,c1,c2,X,Y,Z);
    display(r1,c2,Z);
   }

    return 0;
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
void multiply(int r1,int r2,int c1,int c2,int **P,int **Q,int **Res){
    int i ,j ,k;
    Res[r1][c2];
    for(i = 0;i<r1;i++){
        for(j = 0;j<c2;j++){
            Res[i][j] = 0;
             for (int k = 0; k < r2; k++) {
                Res[i][j] += P[i][k] * Q[k][j];
            }
        }
    }
}

/*
output:
Enter no. of rows and columns for first matrix X :
2 3
Enter no. of rows and columns for second matrix Y :
3 2

Enter elements for matrix X.
2 4 5
8 9 4

Enter elements for matrix Y.
2 1
7 8
5 6

Matrix X =
2       4       5
8       9       4

Matrix Y =
2       1
7       8
5       6

Resultant Matrix : 
57      64
99      104
*/