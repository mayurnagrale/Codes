#include<bits/stdc++.h>
using namespace std;

void selectionSort(int* arr,int n){
    int temp;
    int counter=1;
    while(counter<n){
        for(int i=0;i<n-counter;i++){
            temp=arr[i];
            if(arr[i]>arr[i+1]){
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        counter++;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={6,2,8,5,4,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    return 0;
}