#include<bits/stdc++.h>
using namespace std;

void solve(const vector<int> &A){
    vector<int> B;
    for(int i=A.size()-1;i>=0;i--){
        B.push_back(A[i]);
    }
    for(int i=0;i<B.size();i++){
        cout<<B[i]<<" ";
    }
}

int main(){
    const vector<int> A ={1,2,3,4,5};
    solve(A);
    return 0; 
}