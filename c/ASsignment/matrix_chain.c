/*
Name - Saikat Mazumder
prog - matrix parenthesization problem
*/
#include <limits.h>
#include <stdio.h>
#include<stdlib.h>

int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	
	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k)
				+ MatrixChainOrder(p, k + 1, j)
				+ p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	// Return minimum count
	return min;
}

// Driver code
int main()
{
	 int n, i, *arr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

    printf("Enter elements: ");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", arr + i);
    }

	printf("Minimum number of multiplications is %d ",
		MatrixChainOrder(arr, 1, n - 1));
    printf("\n");
	getchar();
	return 0;
}

/*
output:
Enter number of elements: 5
Enter elements: 1 2 3 4 3
Minimum number of multiplications is 30 
*/