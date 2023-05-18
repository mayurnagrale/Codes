#include<bits/stdc++.h>
using namespace std;


//using distribute responsibility technique

vector<int> solve(int A, vector<vector<int> > &B) {
    vector<int> res(A,0);
    for(int i=0;i<B.size();i++){
        res[B[i][0]-1] += B[i][2];
        if(B[i][1]< A){
            res[B[i][1]] = res[B[i][1]] - B[i][2];
        }
    }
    //prefix sum of res
    for(int i=1;i<A;i++){
        res[i] += res[i-1];
    }
    return res;
}

int main(){
    int A=5;
    vector<vector<int>> B = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    vector<int> res;
    res=solve(A,B);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}