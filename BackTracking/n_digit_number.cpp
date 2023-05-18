#include<bits/stdc++.h>
using namespace std;

void print(int i,int n,int temp[]){
    if(i==n){
        for(int j=0;j<n;j++){
            cout<<temp[j]<<" ";
        }
        cout<<endl;
        return;
    }

    temp[i]=1;
    print(i+1,n,temp);

    temp[i]=2;
    print(i+1,n,temp);

}

int main(){
    int A[3];
    print(0,3,A);
}