#include<bits/stdc++.h>
using namespace std;

struct trp{
    int x,y,z;
};

vector<trp> solve(vector<int> &A,vector<int> &B){
   vector<int>s,g,m,n;
   vector<trp> ans;
   int mincost=INT_MAX;
   int cost;
   int j,k;
    for(int i=0;i<A.size();i++){
        for(j=i-1;j>=0;j--){
            if(A[j]<A[i]){
                s.push_back(A[j]);
                m.push_back(B[j]);
            }
        }
        for(k=i+1;k<A.size();k++){
            if(A[k]>A[i]){
                g.push_back(A[k]);
                n.push_back(B[k]);
            }
        }
        if(!s.size()){
            g.clear();
            n.clear();
        }
        for( j=0;j<s.size();j++){
            for(int k=0;k<g.size();k++){
                if(s[j]<A[i]<g[k])
                    ans.push_back({s[j],A[i],g[k]});
                    cost=m[j]+B[i]+n[k];
                    mincost=min(mincost,cost);
            }
        }
        s.clear();
        g.clear();
        m.clear();
        n.clear();
    } 
    cout<<mincost<<endl;
    return ans;
}

int main(){
    vector<int>B={1,3,5};//4,1,2,6,9,7
    vector<int>C={1,2,3};
    vector<trp>myvec;
    myvec=solve(B,C);
    for (int i=0;i<myvec.size();i++)
    {
        cout << myvec[i].x << ", " << myvec[i].y<< ", " << myvec[i].z << endl;
    }
    return 0;
}