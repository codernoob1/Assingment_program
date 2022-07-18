/*
Name - Saikat Mazumder
prog name - k-ary maxheap
*/
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void restoreDown(int arr[], int len, int index,
                 int k)
{

    int child[k + 1];

    while (1)
    {
        for (int i = 1; i <= k; i++)
            child[i] = ((k * index + i) < len) ? (k * index + i) : -1;

        int min_child = 0, min_child_index;

        for (int i = 1; i <= k; i++)
        {
            if (child[i] != -1 &&
                arr[child[i]] < min_child)
            {
                min_child_index = child[i];
                min_child = arr[child[i]];
            }
        }

        // leaf node
        if (min_child == -1)
            break;

        if (arr[index] > arr[min_child_index])
            swap(&arr[index], &arr[min_child_index]);

        index = min_child_index;
    }
}

void buildHeap(int arr[], int n, int k)
{
    for (int i = (n - 1) / k; i >= 0; i--)
        restoreDown(arr, n, i, k);
}

int extractMin(int arr[], int *n, int k)
{
    int min = arr[0];

    arr[0] = arr[*n - 1];
    *n = *n - 1;

    restoreDown(arr, *n, 0, k);

    return min;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{

    int n, i, *arr, k;

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
    printf("\nEnter the value of k: ");
    scanf("%d", &k);

    buildHeap(arr, n, k);

    printf("Built Heap : \n");
    printArray(arr, n);

    printf("\n\nExtracted min is %d",
           extractMin(arr, &n, k));

    printf("\n\nHeap after extract min: \n");
    printArray(arr, n);
    printf("\n");

    return 0;
}
/*
output:
Enter number of elements: 7
Enter elements: 4 5 6 7 8 9 10

Enter the value of k: 3
Built Heap : 
10 9 6 7 8 4 5 


Extracted max is 10

Heap after extract max: 
9 8 6 7 5 4 
*/