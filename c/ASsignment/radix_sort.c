
/*
Name- Saikat Mazumder
prog name- radix sort 
*/
#include<stdio.h>
#include<stdlib.h>
int getMax(int arr[], int n);
void countSort(int arr[], int n, int pos);
void radixSort(int arr[], int n);
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
    radixSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
int *mem_alloc(int a){
    int *p;
    p = (int *)calloc(a,sizeof(int));
    return p;
}
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
9
Enter 9 numbers :
181 289 390 121 145 736 514 888 122 

Before Sorting : 181 289 390 121 145 736 514 888 122 
Sorted array: 
121 122 145 181 289 390 514 736 888 
*/