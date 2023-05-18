#include<bits/stdc++.h>
using namespace std;
//Balence paranthesis
void solve(int op,int cl,string out,vector<string> &v){
    if(op==0 && cl==0){
        v.push_back(out);
        return;
    }
    if(op!=0){
        string out1=out;
        out1.push_back('(');
        solve(op-1,cl,out1,v);
    }
    if(cl>op){
        string out2=out;
        out2.push_back(')');
        solve(op,cl-1,out2,v);
        return;
    }
}


int main(){
    int n;
    cin>>n;
    int op=n;
    int cl=n;
    string out="";
    vector<string>v;
    solve(op,cl,out,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}