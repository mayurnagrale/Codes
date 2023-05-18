#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int findFeasible(int*boards,int n,int mid){
    int painters=1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+boards[i];
        if(sum>mid){
            sum=boards[i];
            painters++;
        }
    }
    return painters;
}

int PaintersPartition(int*boards,int n,int k){
    int start=0;
    int end=0;
    int mid=0;
    start=*max_element(boards,boards+n);
    for(int i=0;i<n;i++){
        end=end+boards[i];
    }
    while(start<=end){
        mid=start+(end-start)/2;
        int painters=findFeasible(boards,n,mid);
        if(painters<=k){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return start;
}


int main(){
    int boards[]={10,20,30,40};
    int n=sizeof(boards)/sizeof(boards[0]);
    int k=2;
    cout<<"Minimum time to paint boards:"<<PaintersPartition(boards,n,k);
    cout<<endl;
    return 0;
}