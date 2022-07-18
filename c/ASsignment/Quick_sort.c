/*
Name- Saikat Mazumder
prog name- Quick sort 
*/
#include<stdio.h>
#include<stdlib.h>
int partition(int arr[],int s,int e);
void quickSort(int arr[],int s,int e);
void swap(int *x,int *y);
void printArray(int arr[],int n);
void input(int arr,int *n);
int *mem_alloc(int a);
int main(){
   
   int n,*arr,x;
   printf("How many numbers you want to print: \n");
   scanf("%d",&n);

   arr = mem_alloc(n);
   printf("Enter %d numbers :\n",n);
   input(n,arr);

    
    printf("\nBefore Sorting : ");
    printArray(arr,n);
    quickSort(arr, 0,n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
int *mem_alloc(int a){
    int *p;
    p = (int *)calloc(a,sizeof(int));
    return p;
}
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;

}
int partition(int arr[],int s,int e){
    int pivot = arr[s];

    int cnt = 0;
    for(int i= s+1; i<=e;i++){
        if(arr[i] <= pivot){
            cnt++;
        }
    }
    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(&arr[pivotIndex],&arr[s]);

    //left and right;
    int i = s, j=e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }
        
        if(i < pivotIndex && j > pivotIndex){
            swap(&arr[i++],&arr[j--]);
        }
    }

    return pivotIndex;
    
}

void quickSort(int arr[],int s,int e){

    //base case
    if(s>=e){
        return;
    }
    //partition 
    int p = partition(arr,s,e);

    //left part sort
    quickSort(arr,s,p-1);

    //right part sort
    quickSort(arr,p+1,e);

}
void input(int arr,int *n){
    int i;
    for(i=0;i<arr;i++){
        scanf("%d",&n[i]);
    }
}
void printArray(int arr[],int n){
    int i ;
    for(i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

/*
output:
How many numbers you want to print: 
8
Enter 8 numbers :
80 90 10 6 78 96 2 81

Before Sorting : 80 90 10 6 78 96 2 81 
Sorted array: 
2 6 10 78 80 81 90 96 
*/