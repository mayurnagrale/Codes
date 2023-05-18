#include<bits/stdc++.h>
using namespace std;

int main(){
    //const int N=1e6 * 2;
    int N=100;
    int arr[]={1,5,3,4,3,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int idx[N];
    for(int i=0;i<N;i++){
        idx[i]=-1;
    }

    int minidx=INT16_MAX;

    for(int i=0;i<size;i++){
        
        if(idx[arr[i]] != -1){
            minidx=min(minidx,idx[arr[i]]);
        }
        else{
            idx[arr[i]]=i;
        }
    }

    if(minidx==INT16_MAX){
        cout<<"-1";
    }
    else{
        cout<<minidx+1;
    }
    return 0;
}