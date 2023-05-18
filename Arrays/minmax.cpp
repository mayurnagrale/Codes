#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    int evenMax=INT_MIN;
    int oddMax=INT_MIN;
    for(int i=0;i<A.size();i++){
        if(A[i]%2==0){
            if(A[i]>evenMax){
                evenMax=A[i];
            }
        }
        else{
            if(A[i]>oddMax){
                oddMax=A[i];
            }
        }
    }
    return evenMax-oddMax;
}

int main(){
    vector<int> A={-98, 54, -52, 15, 23, -97, 12, -64, 52, 85};
    cout<<solve(A);
    return 0;
}

