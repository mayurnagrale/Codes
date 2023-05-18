#include<bits/stdc++.h>
using namespace std;

bool canShip(int*arr,int n,int d,int mid){
    int days=1;
    int sumofweight=0;
    int i=0;
    for(i=0;i<n;i++){
        sumofweight+=arr[i];
        if(sumofweight>mid){
            days++;
            sumofweight=arr[i];
        }
    }
    if(days<=d){
        return true;
    }
    else{
        return false;
    }
}

int minCapacity(int* arr,int n){
    int start=*max_element(arr,arr+n);
    int end = accumulate(arr,arr+n,end);
    int mid=0;
    int d=5;
    int ans;
    while(start<=end){
        mid=start+(end-start)/2;
        if(canShip(arr,n,d,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<minCapacity(arr,n);
    return 0;
}