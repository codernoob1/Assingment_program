#include<stdio.h>
#include<stdbool.h>

bool isPrime(int n){
    if(n == 1 || n== 0) return false;
    for(int i =2; i*i<=n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
} 

int main(){

    int N ;
    printf("How many numbers you want to print: \n");
    scanf("%d",&N);

    printf("Prine nos. between 1 to %d :\n",N);

    for(int i = 1;i<=N;i++){
        if(isPrime(i)){
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}