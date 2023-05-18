#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum; 
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            cout<<sum<<" ";
        }
    }
}