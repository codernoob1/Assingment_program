#include<stdio.h>
int add_n_naturalNumbers(int n);
int main(){
    int num;
    printf("Enter a number : ");
    scanf("%d",&num);
    printf("Sum is : %d\n",add_n_naturalNumbers(num));
    return 0;
}
int add_n_naturalNumbers(int n){
    if(n != 0){
        return n + add_n_naturalNumbers(n-1);
    }
    else{
        return n;
    }
}