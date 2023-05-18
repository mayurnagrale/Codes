#include<bits/stdc++.h>
using namespace std;

/*void nle(int* a,int n){
    vector<int> out = {};
    stack<int> st;
    for(int i=0;i<n;i++){
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
    for(int i=0;i<out.size();i++){
        cout<<out[i]<<" ";
    }
}*/
void spp(int* a,int n){
    vector<int> out={};
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        if(st.size()==0){
            out.push_back(-1);
        }
        else if(st.size()>0 && st.top().first>a[i]){
            out.push_back(st.top().second);
        }
        else if(st.size()> 0 && st.top().first<=a[i]){
            while(st.size()> 0 && st.top().first<=a[i]){
                st.pop();
            }
            if(st.size()==0){
                out.push_back(-1);
            }
            else{
                out.push_back(st.top().second);
            }
        }
        st.push({a[i],i});
    }

    for(int i=0;i<n;i++){
        out[i]=i-out[i];
        cout<<out[i]<<" ";
    }

}
int main(){
    int a[7]={100,80,60,70,60,75,85};
    int n = sizeof(a)/sizeof(a[0]); 
    //nle(a,n);
    spp(a,n);
    return 0;
}