/*****************************************
Name : Saikat Mazumder
Program : Find the determinant of a matrix
Program No. : 007
Date : 30.06.2022
*****************************************/

#include <stdio.h>
#include <stdlib.h>

int **memalloc(int n);
void input(int n, int **A);
void display(int n, int **A);
int determinant(int **A, int n);
void subDeterminant(int **A, int **temp, int p, int q, int n);

int main()
{
	int r, c, **X;

	do
	{
		printf("No. of rows and coulmns :\t");
		scanf("%d %d", &r, &c);
	} while (r != c);

	X = memalloc(r);
	printf("\nEnter elements for matrix X.\n");
	input(r, X);
	printf("\nMatrix X =\n");
	display(r, X);
	printf("Determinant of the matrix = %d\n", determinant(X, r));

	return 0;
}

int **memalloc(int n)
{
	int i, **A;
	A = (int **)calloc(n, sizeof(int));
	for (i = 0; i < n; i++)
		A[i] = (int *)calloc(n, sizeof(int));
	return A;
}

void input(int n, int **A)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
}

void display(int n, int **A)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d\t", A[i][j]);
		printf("\n");
	}
}

int determinant(int **A, int n)
{
	int D = 0;
	if (n == 1)
		return A[0][0];
	int **temp = memalloc(n);
	int i, sign = 1;
	for (i = 0; i < n; i++)
	{
		subDeterminant(A, temp, 0, i, n);
		D += sign * A[0][i] * determinant(temp, n - 1);
		sign *= -1;
	}
	return D;
}

void subDeterminant(int **A, int **temp, int p, int q, int n)
{
	int i = 0, j = 0, r, c;
	for (r = 0; r < n; r++)
	{
		for (c = 0; c < n; c++)
		{
			if (r != p && c != q)
			{
				temp[i][j++] = A[r][c];
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}
/*
output:
No. of rows and coulmns :       2 2

Enter elements for matrix X.
1 2
7 8

Matrix X =
1       2
7       8
Determinant of the matrix = -6
*/