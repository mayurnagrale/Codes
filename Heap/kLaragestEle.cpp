#include<bits/stdc++.h>
using namespace std;

void kLargest(int* arr,int n,int k){
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(pq.size()>0){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

int main(){
    int arr[]={7,10,4,3,20,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    kLargest(arr,n,k);
    return 0;
}