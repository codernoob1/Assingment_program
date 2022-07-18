/*
Name- Saikat Mazumder
prog name- Insertion sort 
*/
#include<stdio.h>
#include<stdlib.h>
void selectionSort(int *arr,int n);
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
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
int *mem_alloc(int a){
    int *p;
    p = (int *)calloc(a,sizeof(int));
    return p;
}

void selectionSort(int arr[],int n){
    int i,j;
    for(i = 1;i <n;i++){
        int key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j]; 
            j = j-1;
        }
        arr[j+1] = key;
    }
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
10
Enter 10 numbers :
80 50 10 56 0 7 8 -1 55 70

Before Sorting : 80 50 10 56 0 7 8 -1 55 70 
Sorted array: 
-1 0 7 8 10 50 55 56 70 80 
*/