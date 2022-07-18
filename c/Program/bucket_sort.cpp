#include<bits/stdc++.h>
using namespace std;

void bucketSort(float arr[],int n){

    //create n empty buckets
    vector<float> b[n];

    //put array elements in different buckets
    for(int i =0;i<n;i++){
        int bIndex = n * arr[i];
        b[bIndex].push_back(arr[i]);
    }

    //sort the individual buckets
    for(int i =0;i<n;i++){
        sort(b[i].begin(),b[i].end());
    }

    //concatenate all buckets into arr[]
    int index = 0;
    for(int i =0;i<n;i++){
        for(int j =0; j< b[i].size();j++){
            arr[index++] = b[i][j];
        }
    }
}

int main(){
    float arr[] =   { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
 
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}