#include<bits/stdc++.h>
using namespace std;

//Longest positive subarray
vector<int> solve(vector<int> &A) {
    vector<int> B;
    int l,r,len=0,max=0;
    int s,e,j,x;
    for(int i=0;i<A.size();i++){
        if(A[i]<0){
            l=0;
            for(int j=i-1;j>=0;j--){
                if(A[j]>0){
                    l++;
                    x=j;
                }
                else{
                    break;
                }
            }
            r=0;
            for(j=i+1;j<A.size();j++){
                if(A[j]>0){
                    r++;
                }
                else{
                    break;
                }
            }
            if(l > max || r > max)
            {
                if (l >= r)
                {
                    max = l;
                    len = l;
                    s = x;
                    e = i - 1;
                }
                else
                {
                    max = r;
                    len = r;
                    s = i + 1;
                    e = j - 1;
                }
            }
        }
    }
    if(len==0){
        return A;
    }
    for(int i=s;i<=e;i++){
        B.push_back(A[i]);
    }
    return B;
}

int main(){
    vector<int> A={7251357,-5026827,5591744};//,-5026827,5591744,4058312,2210051,5680315,-5251946,-607433,1633303,2186575
    vector<int>B=solve(A);
    for(int i=0;i<B.size();i++){
        cout<<B[i]<<" ";
    }
    return 0;
}
