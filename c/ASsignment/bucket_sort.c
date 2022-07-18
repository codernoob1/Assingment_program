/*
Name- Saikat Mazumder
prog name- Bucket sort 
*/
#include<stdio.h>
#include<stdlib.h>

int getMax(int a[], int n) ;
void bucket(int a[], int n);
void printArray(int arr[],int n);
void input(int arr,int *n);
int *mem_alloc(int a);
int main(){
   
   int n,x;
   int *arr;
   printf("How many numbers you want to print: \n");
   scanf("%d",&n);

   arr = mem_alloc(n);
   printf("Enter %d numbers :\n",n);
   input(n,arr);

    
    printf("\nBefore Sorting : ");
    printArray(arr,n);
    bucket(arr,n);
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
int *mem_alloc(int a){
    int *p;
    p = (int *)calloc(a,sizeof(int));
    return p;
}
 
int getMax(int a[], int n)
{  
  int max = a[0];  
  for (int i = 1; i < n; i++)  
    if (a[i] > max)  
      max = a[i];  
  return max;  
}  
void bucket(int a[], int n) 
{  
  int max = getMax(a, n); 
  int bucket[max], i;  
  for (int i = 0; i <= max; i++)  
  {  
    bucket[i] = 0;  
  }  
  for (int i = 0; i < n; i++)  
  {  
    bucket[a[i]]++;  
  }  
  for (int i = 0, j = 0; i <= max; i++)  
  {  
    while (bucket[i] > 0)  
    {  
      a[j++] = i;  
      bucket[i]--;  
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
8
Enter 8 numbers :
54 12 84 57 69 41 9 5

Before Sorting : 54 12 84 57 69 41 9 5 
Sorted array: 
5 9 12 41 54 57 69 84 
*/