#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int arr[],int n);
void printArray(int arr[],int n);
int *mem_alloc(int a);
void input(int arr,int *n);
int main(){

    int n,*arr,x;
    printf("How many numbers you want to print: \n");
    scanf("%d",&n);

    arr = mem_alloc(n);
    printf("Enter %d numbers :\n",n);
    input(n,arr);
    printf("\nBefore Sorting : ");
    printArray(arr,n);
    bubbleSort(arr, n);
    printf("Sorted array : \n");
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
void bubbleSort(int arr[],int n){
    if(n == 1){
        return;
    }
    for(int i = 0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(&arr[i],&arr[i+1]);
        }
    }
    bubbleSort(arr,n-1);
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