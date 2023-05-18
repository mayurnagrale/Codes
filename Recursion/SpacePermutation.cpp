#include<bits/stdc++.h>
using namespace std;

void solve(string inp, string op){
    if(inp.length()==0){
        cout<<op<<" ";
        return;
    }
    string op1= op;
    string op2= op;
    
    //op2.push_back("_"+inp[0]);
    op1.push_back('_');
    op1.push_back(inp[0]);
    //op1.push_back('_');
    op2.push_back(inp[0]);
    inp.erase(inp.begin()+0);

    solve(inp,op1);
    solve(inp,op2);

}

int main(){
    string inp;
    cin>>inp;
    string op = "";
    solve(inp,op);
    return 0;
}