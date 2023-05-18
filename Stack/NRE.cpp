#include<bits/stdc++.h>
using namespace std;

void nle(int* a,int n){
    vector<int> out = {};
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        if(st.size()==0){
            out.push_back(-1);
        }
        else if(st.size()>0 && st.top()>a[i]){
            out.push_back(st.top());
        }
        else if(st.size()> 0 && st.top()<=a[i]){
            while(st.size()> 0 && st.top()<=a[i]){
                st.pop();
            }
            if(st.size()==0){
                out.push_back(-1);
            }
            else{
                out.push_back(st.top());
            }
        }
        st.push(a[i]);
    }
    for(int i=out.size()-1;i>=0;i--){
        cout<<out[i]<<" ";
    }
}

int main(){
    int a[4]={1,3,2,4};
    int n = sizeof(a)/sizeof(a[0]); 
    nle(a,n);
    return 0;
}