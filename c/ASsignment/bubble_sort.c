/*
Name- Saikat Mazumder
prog name- Bubble sort 
*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y);
void BubbleSort(int *arr,int n);
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
    BubbleSort(arr, n);
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
void BubbleSort(int arr[],int n){
    int i,j;
    for(i = 0;i<n-1;i++){
        for(j = 0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
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
7
Enter 7 numbers :
80 5 65 90 120 56 3

Before Sorting : 80 5 65 90 120 56 3 
Sorted array: 
3 5 56 65 80 90 120 
*/