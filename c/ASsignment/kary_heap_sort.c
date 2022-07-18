/*
Name - Saikat Mazumder
prog name - k-ary heap sort
*/

#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void maxHeap(int *arr,int n,int k){
    int i,j,y,temp;
    i = (n-1)/k;
    
    for(;i != -1;i--){
        j=1;
        temp = k*i+j;
        for(;j<k;j++){
            y = k*i+j+1;
            if(y<n && arr[temp]< arr[y]){
                temp = y;
            }
        }
        if(arr[temp]>arr[i]&&temp<n){
            swap(&arr[i],&arr[temp]);
        }
    }
    
}

void getMaxHeap(int *arr,int n,int k){
    for(int i = (n-1)/k;i>=0;i--){
        maxHeap(arr,n,k);
    }
}

void sortKaryHeap(int *arr,int n,int k){
    while(n!=0){
        swap(&arr[0],&arr[n-1]);
        n--;
        getMaxHeap(arr,n,k);
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

int main(){
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

    printf("Max-heapify\n");
    getMaxHeap(arr,n,k);
    printArray(arr,n);

    sortKaryHeap(arr,n,k);
    printf("Sorted List :\n");

    printArray(arr,n);
    return 0;
    

}

/*
output:
Enter number of elements: 8
Enter elements: 45 7 90 -25 1 6 7 65

EnteEnter the value of k: 4
Max-heapify
90 65 45 -25 1 6 7 7 
Sorted List :
-25 1 6 7 7 45 65 90r the value of k: 4
Max-heapify
90 65 45 -25 1 6 7 7 
Sorted List :
-25 1 6 7 7 45 65 90 
*/