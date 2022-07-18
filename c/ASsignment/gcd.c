#include<stdio.h>
int gcd(int a,int b);
int main(){
    int a,b;

    printf("enter the value of a: ");
    scanf("%d",&a);
    printf("enter the value of b: ");
    scanf("%d",&b);

    printf("Gcd of two number %d and %d  : %d\n",a,b,gcd(a,b));

    return 0;
}
int gcd(int a,int b){
    if(a == 0){
        return b;
    }
    if( b == 0){
        return a;
    }
    if(a == b){
        return a;
    }
    if(a>b){
        return gcd(a%b,b);
    }
    return gcd(a,b%a);
}