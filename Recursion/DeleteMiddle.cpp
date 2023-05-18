#include<bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &s,int k){
    if(k==0 || s.size()==0){
        return;
    }
    if(k==1){
        s.pop();
        return;
    }
    int temp=s.top();
    s.pop();
    deleteMiddle(s,k-1);
    s.push(temp);
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(2);
    s.push(4);
    s.push(3);
    s.push(1);
    int k=(s.size()/2)+1;
    deleteMiddle(s,k);


    while(!s.empty()){
        cout<<' '<<s.top();
        s.pop();
    }
    return 0;
}