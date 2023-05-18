#include<bits/stdc++.h>
using namespace std;

void kClosestSorting(int* arr,int n,int k,int x){
    for(int i=0;i<n;i++){
        arr[i]=arr[i]-x;
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<k;i++){
        cout<<arr[i]+x<<" ";
    }
}

void kClosest(int* arr,int n,int k,int x){
    priority_queue<pair<int,int>>max_heap;
    for(int i=0;i<n;i++){
        max_heap.push(make_pair(abs(arr[i]-x),arr[i]));
        if(max_heap.size()>k){
            max_heap.pop();
        }
    }
    while(max_heap.size()>0){
        cout<<max_heap.top().second<<" ";
        max_heap.pop();
    }
}
int main(){
    int arr[]={5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int x=7;
    kClosest(arr,n,k,x);
    cout<<endl;
    kClosestSorting(arr,n,k,x);
    return 0;
}
