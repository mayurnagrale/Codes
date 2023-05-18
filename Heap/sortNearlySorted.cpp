#include<bits/stdc++.h>
using namespace std;

void sortNearlySorted(int* arr,int n,int k){
    int i=0;
    priority_queue <int, vector<int>, greater<int> > min_heap;
    //priority_queue<int> max_heap;
    for(int i=0;i<n;i++){
        min_heap.push(arr[i]);
        if(min_heap.size()>k){
            arr[i-k]=min_heap.top();
            min_heap.pop();
        }
    }

    while(min_heap.size()>0){
        arr[n-k+i]=min_heap.top();
        min_heap.pop();
        i++;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}   

int main(){
    int arr[]={6,5,3,2,8,10,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    sortNearlySorted(arr,n,k);
    return 0;
}