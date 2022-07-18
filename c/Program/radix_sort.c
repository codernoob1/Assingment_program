#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int pos)
{
    int output[n + 1];
    int count[10] = {0};

    // calculate count of elements
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / pos) % 10]++;
    }

    // calculate cumulative frequency
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // placed the elements in sorted order
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / pos) % 10]-1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    for (int pos = 1; max / pos > 0; pos *= 10)
    {
        countSort(arr, n, pos);
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
    int a[] = {181, 289, 390, 121, 145, 736, 514, 888, 122};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Before sorting array elements are - \n");
    printArray(a, n);
    radixSort(a, n);
    printf("After applying Radix sort, the array elements are - \n");
    printArray(a, n);
}