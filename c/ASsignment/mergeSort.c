/*
Name- Saikat Mazumder
prog name- merge sort 
*/
#include<stdio.h>
#include<stdlib.h>
void merge(int *arr,int s,int e);
void mergeSort(int *arr,int s,int e);
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
    mergeSort(arr,0,n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
int *mem_alloc(int a){
    int *p;
    p = (int *)calloc(a,sizeof(int));
    return p;
}
void merge(int *arr,int s,int e){

    int mid = s + (e-s)/2;

    int len1 = mid - s+1;
    int len2 = e - mid;

    int first[len1],second[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i =0;i<len1;i++){
        first[i] = arr[mainArrayIndex++];
    }

     mainArrayIndex = mid+1;
    for(int i =0;i<len2;i++){
        second[i] = arr[mainArrayIndex++];
    }

    //merge two sorted array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }else{
             arr[mainArrayIndex++] = second[index2++];
        }
    }
    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }
    
}
void mergeSort(int *arr,int s,int e){

    //base case
    if(s >= e){
        return;
    }

    int mid = s + (e-s)/2;

    //left part sort
    mergeSort(arr,s,mid);

    //right part sort 
    mergeSort(arr,mid+1,e);

    //merge
    merge(arr,s,e);

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
40 8 4 60 23 60 89 7

Before Sorting : 40 8 4 60 23 60 89 7 
Sorted array: 
4 7 8 23 40 60 60 89 
*/