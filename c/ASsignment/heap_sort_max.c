/*
Name- Saikat Mazumder
prog no- heap sort using maxheap
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{

    int largest = i;

    int leftChild = 2 * i + 1;

    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] > arr[largest])

        largest = leftChild;

    if (rightChild < n && arr[rightChild] > arr[largest])

        largest = rightChild;

    if (largest != i)
    {

        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)

        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {

        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
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

    printf("Sorted Array: \n");
    heapSort(arr, n);
    printArray(arr, n);
}
/*
output:
Enter number of elements: 7
Enter elements: 15 10 11 7 8 9
45
Sorted Array: 
7 8 9 10 11 15 45 
*/