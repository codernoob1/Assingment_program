
/*
Name- Saikat Mazumder
prog name- selection sort 
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
    int i,j,min,temp;
    for(i = 0;i<n-1;i++){
        min = i;
        for(j = i+1;j<n;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
9 3 1 4 2 7 5

Before Sorting : 9 3 1 4 2 7 5 
Sorted array: 
1 2 3 4 5 7 9  
*/