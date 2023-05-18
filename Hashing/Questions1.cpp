#include<bits/stdc++.h>
using namespace std;

//Subarray with given sum

vector<int> solve(vector<int> &A, int B) {
    vector<int> pf;
    vector<int>res;
    unordered_map<int,int> hm;
    pf.push_back(A[0]);
    for(int i=1;i<A.size();i++){
        pf.push_back(pf[i-1]+A[i]);
    }

    for(int i=0;i<pf.size();i++){
        cout<<pf[i]<<" ";
    }
    cout<<endl;

    hm[0]=-1;
    int start=0;
    int end=0;
    for(int i=0;i<pf.size();i++){
        int x=pf[i]-B;
        cout<<x<<" ";
        if(hm.find(x) != hm.end()){
            start= hm[x];
            end = i;
            break;
        }
        else{
            hm[pf[i]]=i;
        }
    }
    cout<<endl;
    cout<<start<<" "<<end<<endl;
    for(int i=start+1;i<=end;i++){
        res.push_back(A[i]);
    }
    return res;
}

bool comp(pair<int,int> a,pair<int,int> b){
    if(a.second<b.second){
        return true;
    }
    else if(a.second>b.second){
        return false;
    }
    else{
        if(a.first<b.first){
            return true;
        }
        else{
            return false;
        }
    }
}

vector<pair<int,int>> twoSum(vector<int> &A,int B){
    unordered_map<int,int> hm;
    vector<pair<int,int>> res;
    vector<int> ans;
    // for(int i=0;i<A.size();i++){
    //     hm[A[i]]=i;
    // }
    for(int i=0;i<A.size();i++){
        int b=B-A[i];
        if(hm.find(b) != hm.end()){
            res.push_back(make_pair(hm[b]-1,i+1));
        }
        else{
            hm[A[i]]=i;
        }
    }

    sort(res.begin(),res.end(),comp);
    return res;
}

int greyCode(vector<string> &A, string B) {
    unordered_map<char,int> hm;
    for(int i=0;i<B.length();i++){
        hm[B[i]]=i;
    }
    for(int i=0;i<A.size()-1;i++){
        if(hm[A[i]]>hm[A[i+1]]){
            return 0;
        }
    }
    return 1;
}

int main(){
    //vector<int> A={12, 1, 50, 39, 32, 23, 22, 44, 17, 5, 9, 12, 10, 50, 26, 5, 23, 38, 31, 5, 34, 8, 21, 11, 24, 44, 18, 19, 6, 31, 3, 47, 5, 2, 33, 44, 14, 9};
    vector<int> A={ 10, -3, 5, -7, -4, 5, 6, -7, 8, -5, 8, 0, 8, -5, -10, -1, 1, -6, 4, -1, -2, -2, 10, -2, -4, -7, 5, 1, 7, -10, 0, 5, 8, 6, -8, 8, -8, -8, 3, -9, -10, -5, -5, -10, 10, -4, 8, 0, -6, -2, 3, 7, -5, 5, 1, -7, 0, -5, 1, -3, 10, -4, -3, 3, 3, 5, 1, -2, -6, 3, -4, 10, -10, -3, -8, 2, -2, -3, 0, 10, -6, -8, -10, 6, 7, 0, 3, 9, -10, -7, 8, -7, -7 };
    //vector<int> res=solve(A,16);
    // vector<pair<int,int>> res=twoSum(A,-2);
    // for(int i=0;i<res.size();i++){
    //     cout<<res[i].first<<" "<<res[i].second<<endl;
    // }
    // cout<<endl;

    
    return 0;
}