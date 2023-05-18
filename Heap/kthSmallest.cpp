#include<bits/stdc++.h>
using namespace std;

int kthSmallestEle(int* arr, int n,int k){
    //sort(arr,arr+n);
    //return arr[k-1];
    //solution using nlogk time complexity
    priority_queue<int> max_heap;
    for(int i=0;i<n;i++){
        max_heap.push(arr[i]);
        if(max_heap.size()>k){
            max_heap.pop();
        }
    }
    return max_heap.top();
}

int main(){
    int arr[]={7,10,4,3,20,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    cout<<kthSmallestEle(arr,n,k);
}