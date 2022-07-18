
/*********************************
Name : Saikat Mazumder
Program : multiply two matrices recursively
Program No. : 006
Date : 04.04.2022
*********************************/


#include<stdio.h>
#include<stdlib.h>

int** create_array (int **a, int r, int c);
void input_matrix (int **a, int r, int c);
void recursive_multi (int **a, int **b, int **k, int r, int c, int i, int j, int x, int sum);
void display_matrix (int **a, int r, int c);

int main()
{
    int **a, **b, **k;
    int r, c, i=0, j=0;

    printf("Enter the row of the Matrix.\n");
    scanf("%d",&r);

    printf("Enter the column of the Matrix.\n");
    scanf("%d",&c);

    a = create_array (a,r,c);
    printf("Enter the element in the 1st matrix.\n");
    input_matrix (a,r,c);
    printf("1st matrix is \n");
    display_matrix (a,r,c);

    b = create_array (b,r,c);
    printf("Enter the element in the 2nd matrix.\n");
    input_matrix (b,r,c);
    printf("2nd matrix is \n");
    display_matrix (b,r,c);

    printf("After the Multiplication.\n");

    k = create_array (k,r,c);
    recursive_multi (a,b,k,r,c,0,0,0,0);
    display_matrix (k,r,c);

    return 0;
}
int** create_array (int **a, int r, int c)
{
    int i, j;

    a = (int**)malloc(r*sizeof(int*));

    for(i=0;i<r;i++)
        a[i] = (int*)malloc(c*sizeof(int));

    return a;
}
void input_matrix (int **a, int r, int c)
{
    int i,j;

    
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void recursive_multi (int **a, int **b, int **k, int r, int c, int i, int j, int x, int sum)
{
    if(x==c)
    {
        k[i][j]=sum;
        j++;
        x=0;
        sum=0;
    }
    if(j==c)
    {
        i++;
        j=0;
    }
    if(i==r)
    return;

    sum+= a[i][x]*b[x][j];

    recursive_multi(a,b,k,r,c,i,j,++x,sum);
}
void display_matrix (int **a, int r, int c)
{
    int i,j;
    if(a==NULL)
        printf("Blank Memory.\n");
    else
    {
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                printf("\t%d",a[i][j]);
            }
            printf("\n");
        }
    }
}
/*
output:
Enter the row of the Matrix.
2
Enter the column of the Matrix.
2
Enter the element in the 1st matrix.
12
10 
40
50
1st matrix is 
        12      10
        40      50
Enter the element in the 2nd matrix.
23
29
78
79
2nd matrix is 
        23      29
        78      79
After the Multiplication.
        1056    1138
        4820    5110
*/