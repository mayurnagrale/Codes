#include<bits/stdc++.h>
using namespace std;

int startingIndex(int* arr,int n){
    int start=0;
    int end=n-1;
    int res=0;
    int mid=0;
    int ele=7;
    while(start<=end){
        mid=start+((end-start)/2);
        if(arr[mid]==ele){
            res=mid;
            end=mid-1;
        }
        else if(arr[mid]>ele){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return res;
}
int endingIndex(int* arr,int n,int startIndex){
    int start=startIndex;
    int end=n-1;
    int res=0;
    int mid=0;
    int ele=7;
    while(start<=end){
        mid=start+((end-start)/2);
        if(arr[mid]==ele){
            res=mid;
            start=mid+1;
        }
        else if(arr[mid]>ele){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return res;
}

int main(){
    int arr[]={2,5,7,7,7,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int startIndex=startingIndex(arr,n);
    cout<<startingIndex(arr,n)<<endl;
    cout<<endingIndex(arr,n,startIndex);
    return 0;
}