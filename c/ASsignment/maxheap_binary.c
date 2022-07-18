/*
Name - Saikat Mazumder
prog name - maxheap
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int arr[], int i, int n)
{
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[largest] < arr[leftChild])
    {
        largest = leftChild;
    }
    if (rightChild < n && arr[largest] < arr[rightChild])
    {
        largest = rightChild;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, largest, n);
    }
}
void buildHeap(int arr[], int n)
{
    int lastNonLeafNode = (n / 2) - 1;

    for (int i = lastNonLeafNode; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
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

    printArray(arr, n);

    buildHeap(arr, n);
    printArray(arr, n);
}

/*
output:
Enter number of elements: 7
Enter elements: 8 13 30 20 50 15 10
8 13 30 20 50 15 10 
50 20 30 8 13 15 10 Enter elements: 8 13 30 20 50 15 10
8 13 30 20 50 15 10 
50 20 30 8 13 15 10 
*/