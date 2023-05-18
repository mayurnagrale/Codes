#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={0,-9,1,3,-4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    bool arrnew[100];
    for(int i=0;i<100;i++){
        arrnew[i]=false;
    }

    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            arrnew[arr[i]]=true;
        }
    }

    for(int i=0;i<n;i++){
        if(arrnew[i]==false){
            cout<<i;
            break;
        }
    }
    
    return 0;
}