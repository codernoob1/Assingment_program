#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{

    int temp = *a;

    *a = *b;

    *b = temp;
}
//minheap

void heapify(int arr[], int n, int i)
{

    int Smallest = i;

    int leftChild = 2 * i + 1;

    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] < arr[Smallest])

        Smallest = leftChild;

    if (rightChild < n && arr[rightChild] < arr[Smallest])

        Smallest = rightChild;

    if (Smallest != i)
    {

        swap(&arr[i], &arr[Smallest]);

        heapify(arr, n, Smallest);
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