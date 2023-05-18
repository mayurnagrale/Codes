#include<bits/stdc++.h>
using namespace std;

void solve(int n){

    if(n==0){
        return;
    }
    cout<<n<<" ";
    solve(n-1);
    cout<<n<<" ";
}

int main(){
    solve(7);
    return 0;
}