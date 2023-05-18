#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<pair<int,int>> pv){
    vector<int> res(15,0);
    for(int i=0;i<pv.size();i++){
        res[pv[i].first] += 1;
        if(pv[i].second< pv.size()){
            res[pv[i].second+1] = res[pv[i].second+1
            ] - 1;
        }
    }
    //prefix sum of res
    for(int i=1;i<res.size();i++){
        res[i] += res[i-1];
    }
    return res;
}

int main(){
    vector<pair<int,int>> pv={{1,3},{6,9}};
    vector<int> ans=solve(pv);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}