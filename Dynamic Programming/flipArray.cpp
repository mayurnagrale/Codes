#include<bits/stdc++.h>
using namespace std;

int minValue(vector<int> &A,int minsum,int n){
    if(n==0) return 0;
    if(minsum<0) return 0;

    if(A[n-1]<minsum){
        return minValue(A,minsum,n-1);
    }

    if(A[n-1]>=minsum){
        return 1+minValue(A,minsum-A[n-1] ,n-1);
    }

}

int main(){
    vector<int> in={15,10,6};
    int n;
    int sum;
    for(int i=0;i<in.size();i++){
        //in.push_back(cin>>n);
        sum+=in[i];
    }

    cout<<minValue(in,sum,in.size());

    return 0;
}