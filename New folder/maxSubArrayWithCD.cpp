#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={10,7,4,6,8,10,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    int pcd=arr[1]-arr[0];;
    int length=2;
    int ans=2;
    int i=2;
    while(i<n){
        if(pcd==arr[i]-arr[i-1]){
            length++;
        }
        else{
            pcd=arr[i]-arr[i-1];
            length=2;
        }
        ans=max(ans,length);
        i++;
    }
    cout<<ans;
}