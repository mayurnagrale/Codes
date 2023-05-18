#include<bits/stdc++.h>
using namespace std;

int pn(int x){
    int sum=0;
    for(int i=1;i<x;i++){
        if(x%i==0){
            sum+=i;
        }
    }
    if(sum==x){
        return x;
    }
    else{
        return -1;
    }
}

int main(){
   // int n;
    //cin>>n;
    cout<<pn(6);
    return 0;
}