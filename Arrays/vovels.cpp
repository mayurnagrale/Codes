#include<bits/stdc++.h>
using namespace std;

vector<int> solve(string A, vector<vector<int> > &B) {
    vector<int> res;
    vector<int> pf;
    int count=0;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u')
        {
            count++;
            pf.push_back(count);
        }
        else
        {
            pf.push_back(count);
        }
    }

    for(int i=0;i<pf.size();i++){
        cout<<pf[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<B.size();i++){
        if(B[i][0]==0){
            res.push_back(pf[B[i][1]]);
        }
        else{
            res.push_back(pf[B[i][1]]-pf[B[i][0]-1]);    
        }
    }
    return res;
}

int main(){
    string str="interviewbit";
    vector<vector<int> > B = {{0,4},{9,10}};
    vector<int> ans = solve(str,B);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}