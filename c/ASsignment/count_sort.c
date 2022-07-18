/*
Name- Saikat Mazumder
prog name- count sort 
*/
#include<stdio.h>
#include<stdlib.h>
int getMax(int *arr,int n);
void countSort(int *arr,int n);
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
    countSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
int *mem_alloc(int a){
    int *p;
    p = (int *)calloc(a,sizeof(int));
    return p;
}
int getMax(int *arr,int n){
    int max = arr[0];
    for(int i = 1;i<n;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
void countSort(int *arr,int n){
    int output[n+1];
    int max = getMax(arr,n);
    int count[max+1];

// initializing count array to 0
    for(int i =0;i<=max;i++){
        count[i] = 0;
    }

    //how many repeated value is there
    for(int i =0;i<n;i++){
        count[arr[i]]++;
    }

    //find comulative count in count array
    for(int i =1;i<=max;i++){
        count[i]+= count[i-1];
    }
    for(int i = n-1;i>=0;i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--; //decrease count
    }
    for(int i = 0;i<n;i++){
        arr[i] = output[i];
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
How many numbers you want to print: 
8
Enter 8 numbers :
 4 5 0 1 4 0 5 4

Before Sorting : 4 5 0 1 4 0 5 4 
Sorted array: 
0 0 1 4 4 4 5 5 
*/