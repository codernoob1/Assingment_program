/*
Name - Saikat Mazumder
prog name - count sort
*/

#include<iostream>
using namespace std;

int getMax(int arr[],int n){
    int max = arr[1];
    for(int i = 2;i<=n;i++){
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
    for(int i =1;i<=n;i++){
        count[arr[i]]++;
    }

    //find comulative count in count array
    for(int i =1;i<=max;i++){
        count[i]+= count[i-1];
    }
    for(int i = n;i>=1;i--){
        output[count[arr[i]]] = arr[i];
        count[arr[i]] -= 1; //decrease count
    }
    for(int i = 1;i<=n;i++){
        arr[i] = output[i];
    }
}
void display(int *array, int size) {
   for(int i = 1; i<=size; i++)
      cout << array[i] << " ";
   cout << endl;
}

int main(){

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n+1];
    cout << "Enter elements:" << endl;

    for(int i =1;i<=n;i++){
        cin >> arr[i];
    }

    cout<< "Array before Sorting: ";
    display(arr, n);
    countSort(arr, n);
    cout << "Array after Sorting: ";
    display(arr, n);

}