#include<bits/stdc++.h>
using namespace std;

void insertAt(stack<int> &s,int temp){
    if(s.size()==0){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insertAt(s,temp);
    s.push(val);
}

void reverseStack(stack<int> &s){
    if(s.size()==0){
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAt(s,temp);
}


int main(){
    stack<int> s;
    s.push(5);
    s.push(2);
    s.push(4);
    s.push(3);
    s.push(1);
    reverseStack(s);

    while(!s.empty()){
        cout<<' '<<s.top();
        s.pop();
    }
    return 0;
}