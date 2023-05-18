#include<bits/stdc++.h>
using namespace std;

//Nearest smmaller to the left

vector<int> nearestSmallerLeft(vector<int> &A){
    vector<int> v(A.size(),-1);
    stack<int> st;
    for(int i=0;i<A.size();i++){
        while(!st.empty() && st.top()>=A[i]){
            st.pop();
        }
        if(!st.empty())
            v[i]=st.top();
        
        st.push(A[i]);
    }
    return v;
}


//Nearest smaller to the right

vector<int> nearestSmallerRight(vector<int> &A){
    vector<int> v(A.size(),-1);
    stack<int> st;
    for(int i=A.size()-1;i>=0;i--){
        while(!st.empty() && st.top()>=A[i]){
            st.pop();
        }
        if(!st.empty())
            v[i]=st.top();
        
        st.push(A[i]);
    }
    return v;
}

//Nearest greater to the left

vector<int> nearestGreaterLeft(vector<int> &A){
    vector<int> v(A.size(),-1);
    stack<int> st;
    for(int i=0;i<A.size();i++){
        while(!st.empty() && st.top()<=A[i]){
            st.pop();
        }
        if(!st.empty())
            v[i]=st.top();
        
        st.push(A[i]);
    }
    return v;
}

//Nearest greater to the right

vector<int> nearestGreaterRight(vector<int> &A){
    vector<int> v(A.size(),-1);
    stack<int> st;
    for(int i=A.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=A[i]){
            st.pop();
        }
        if(!st.empty())
            v[i]=st.top();
        
        st.push(A[i]);
    }
    return v;
}

//Index of nearest smaller left

vector<int> nearestSmallerLeftIdx(vector<int> &A){
    vector<int> v(A.size(),-1);
    stack<int> st;
    for(int i=0;i<A.size();i++){
        while(!st.empty() && A[st.top()]>=A[i]){
            st.pop();
        }
        if(!st.empty())
            v[i]=st.top();
        
        st.push(i);
    }
    return v;
}


int main(){
    vector<int> A={4,6,10,11,7,6,3,5};
    vector<int> res=nearestSmallerLeftIdx(A);

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";  
    }
    cout<<endl;

    return 0;
}