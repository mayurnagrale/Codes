#include<bits/stdc++.h>
using namespace std;

int solve(string A) {
    unordered_set<char> hs;
    
    for(int i=0;i<A.size();i++){
        hs.insert(A[i]);
    }
    cout<<hs.size()<<endl;
    cout<<A.size()<<endl;
    if(hs.size()>(A.size()/2)+1){
        return 0;
    }
    else{
        return 1;
    }
    
}

int main(){
    string A="aabbccddja";
    cout<<solve(A);
    return 0;
}