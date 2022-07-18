// /*
// Name- Saikat Mazumder
// Program -Write a C program for a calculator involing +,-,*,/ operations.
// */

// #include<stdio.h>

// int main()
// {
//     float num1,num2;
//     float result;
//     char ch;

//     printf("Enter First number : ");
//     scanf("%f",&num1);

//     printf("Enter Second number : ");
//     scanf("%f",&num2);

//     printf("Choose an operation  (+,-,*,/): ");
//     scanf(" %c",&ch);

//     result = 0;
    
//     switch (ch)
//     {
//     case '+':
//         result=num1+num2;
//         break;
//     case '-':
//         result = num1 - num2;
//         break;
//     case '*':
//         result = num1 * num2;
//         break;
//     case '/':
//     if(num2 == 0){
//         printf("\n Divisor cannot be Zero.");
//         scanf("%f",&num2);
//     }
//         result = num1 / num2;
//         break;
//     default:
//         printf("Invalid operation\n");
        
//     }
//     printf("Result: %f %c %f = %.2f\n",num1,ch,num2,result);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l,
		int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[],
			int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
void input(int arr,int *n){
    int i;
    for(i=0;i<arr;i++){
        scanf("%d",&n[i]);
    }
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
int *mem_alloc(int a){
    int *p;
    p = (int *)calloc(a,sizeof(int));
    return p;
}
int main()
{
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
/*
output:
How many numbers you want to print: 
7
Enter 7 numbers :
120 89 40 56 121 0 -1

Before Sorting : 120 89 40 56 121 0 -1 
Sorted array: 
-1 0 40 56 89 120 121 
*/