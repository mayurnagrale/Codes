#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A) {
    vector<long> pf;
    unordered_set<long> um;

    pf.push_back(A[0]);
    for(int i=1;i<A.size();i++){
        pf.push_back(pf[i-1]+A[i]);
    }

    for (int i = 0; i < pf.size(); i++)
    {
        um.insert(pf[i]);
        if (pf[i] == 0)
        {
            return 1;
        }
    }
    cout<<um.size()<<endl;
    if (um.size() < A.size())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(){
    vector<int> A= {1, 2, 3, 4, 5};

    cout<<solve(A);
}