#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> B(3, vector<int> (3, 0));
    for(int i=0;i<B.size();i++){
        for(int j=0;j<B[0].size();j++){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}