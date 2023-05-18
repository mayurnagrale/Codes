#include<bits/stdtr1c++.h>
using namespace std;

int* reversePart(int *arr,int k,int n){
    int i=k,j=n-1;
    int temp;
    while(i<j){
        //swap
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        //inc
        i++,j--;
    }
    return arr;
}

int* kRotateLeftToRight(int *arr,int k,int n){
    int* revarr=reversePart(arr,0,n);
    //reverse first n-k elements
    int* firstn_k=reversePart(arr,0,n-k);
    //reverse remaining elements
    int* remain=reversePart(arr,n-k,n);
}

int* kRotateRightToLeft(int *arr,int k,int n){
    int* revarr=reversePart(arr,0,n);
    for(int i=0;i<n;i++){
        cout<<revarr[i]<<" ";
    }
    cout<<endl;
    //reverse first k elements
    int* firstk=reversePart(arr,0,k);
    for(int i=0;i<n;i++){
        cout<<firstk[i]<<" ";
    }
    cout<<endl;
    //reverse remaining elements
    int* remaining=reversePart(arr,k,n);
    return firstk;
}

int main(){
    int n;
    n=5;
    int arr[]={1,2,3,4,5};
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int k=2;
    //if k>n
    k=k%n;
    //int* newkrotatedRL=kRotateRightToLeft(arr,k,n);
    int* newkrotatedLR=kRotateLeftToRight(arr,k,n);
    for(int i=0;i<n;i++){
        cout<<newkrotatedLR[i]<<" ";
    }
    return 0;
}