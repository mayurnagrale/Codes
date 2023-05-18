#include<bits/stdc++.h>
using namespace std;

void topkfreq(int * arr,int n,int k){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
    //for frequency we have to use hashmap
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    //traverse through the map
    for(auto i=mp.begin();i!=mp.end();i++){
        min_heap.push({i->second,i->first});
        if(min_heap.size()>k){
            min_heap.pop();
        }
    }

    //print the element of heap
    while(min_heap.size()>0){
        cout<<min_heap.top().second<<endl;
        min_heap.pop();
    }
}

int main(){
    int arr[]={1,1,1,3,2,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=2;
    topkfreq(arr,n,k);
    return 0;
}