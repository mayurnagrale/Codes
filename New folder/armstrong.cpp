#include<bits/stdc++.h>
using namespace std;

int ams(int x){
    int temp,n;
    int sum=0;
    temp=x;
    while(x>0){
        n=x%10;
        sum+=(n*n*n);
        x=x/10;
    }
    if(sum==temp){
        return temp;
    }
    else{
        return -1;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        if(ams(i)>0){
            cout<<ams(i)<<endl;
        }
    }
    return 0;
}