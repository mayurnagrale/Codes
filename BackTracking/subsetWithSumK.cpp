#include<bits/stdc++.h>
using namespace std;

//count of subset of given sum

int ans;

int getCount(int i,int n, int arr[],int sum, int k){
    if(i==n-1){
        if(sum==k){
            return 1;
        }
        else{
            return 0;
        }
    }
    ans=0;
    sum+=arr[i];
    ans+=getCount(i+1,n,arr,sum,k);
    sum-=arr[i];
    ans+=getCount(i+1,n,arr,sum,k);
    return ans;
}

int main(){
    int A[]={5,2,-7};
    cout<<getCount(0,3,A,0,5);
    return 0;
}