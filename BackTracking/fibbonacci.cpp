#include<bits/stdc++.h>
using namespace std;

int fib(int n,vector<int> A){
    if(n<=1){
        return n;
    }

    if(A[n]!= -1){
        return A[n];
    }
    else{
        A[n]=fib(n-1,A)+fib(n-2,A);
        return A[n];
    }
}

int main(){
    vector<int> A(45,-1);
    cout<<fib(44,A);

    return 0;
}