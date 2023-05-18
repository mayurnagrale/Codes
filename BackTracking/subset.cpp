#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
set<vector<int>> hm;

//recursice function for inclusion and exclusion
void helper(vector<int> &A,vector<int> &temp,int i){
    //base case
    if(i==A.size()){
        ans.push_back(temp);
        hm.insert(temp);
        return;
    }
    //include
    temp.push_back(A[i]);
    helper(A,temp,i+1);
    //exclude
    temp.pop_back();
    helper(A,temp,i+1);
    return;
}


int main(){
    vector<int> A={1,2,3,4,5};
    vector<int> temp;
    vector<int> hmtemp;
    
    helper(A,temp,0);

    // sort(ans.begin(),ans.end());

    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         hmtemp.push_back(ans[i][j]);
    //     }
    //     hm.insert(temp);
    //     temp.clear();
    // }

    vector<vector<int>> res;
    for(auto e:hm){
        res.push_back(e);
    }

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}