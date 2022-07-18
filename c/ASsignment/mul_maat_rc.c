#include<stdio.h>
#include<stdlib.h>
void input(int row,int col,int **A);
void display(int row,int col,int **A);
int **mem_alloc(int row,int col);
void multiplyMatrix(int row1,int col1,int row2,int col2,int **X,int **Y,int **Res);
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
    multiplyMatrix(r1,c1,r2,c2,X,Y,Z);
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

void multiplyMatrix(int row1,int col1,int row2,int col2,int **X,int **Y,int **Res){

    static int i = 0, j = 0, k = 0;

    if(i>= row1){
        return;
    }
    if(j < col2){
        if (k< col1)
        {
            Res[i][j] += X[i][k] * Y[k][j];
            k++;
            multiplyMatrix(row1,col1,row2,col2,X,Y,Res);
        }
        k =0;
        j++;
        multiplyMatrix(row1,col1,row2,col2,X,Y,Res);
    }
    j = 0;
    i++;
    multiplyMatrix(row1,col1,row2,col2,X,Y,Res);
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