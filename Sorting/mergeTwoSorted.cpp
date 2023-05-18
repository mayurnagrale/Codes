#include<bits/stdc++.h>
using namespace std;

vector<int> mergeTwoSorted(vector<int> &A, vector<int> &B){
    vector<int> C;
    int P1=0,P2=0;

    while(P1<A.size() && P2<B.size()){
        if(A[P1] < B[P2]){
            C.push_back(A[P1]);
            P1++;
        }
        else{
            C.push_back(B[P2]);
            P2++;
        }
    }
    while(P1<A.size()){
        C.push_back(A[P1]);
        P1++;
    }

    while(P2<B.size()){
        C.push_back(B[P2]);
        P2++;
    }

    return C;
}

//merge two sorted ranges
vector<int> mergeTwoSortedRanges(vector<int> A, int l,int y,int r){
    vector<int> C;
    int P1=l;P2=y;P3=0;
    while(P1<y && P2<r){
        if(A[P1] < A[P2]){
            C.push_back(A[P1]);
            P1++;
        }
        else{
            C.push_back(A[P2]);
            P2++;
        }
    }
    while(P1<y){
        C.push_back(A[P1]);
        P1++;
    }

    while(P2<=r){
        C.push_back(B[P2]);
        P2++;
    }

    return C;
}

int main(){
    vector<int> A = {1,3,5,7,9};
    vector<int> B = {2,4,6,8};
    vector<int> C = {1,2,5,4,3,8,7,6,9};
    //vector<int> res=mergeTwoSorted(A,B);
    vector<int> res = mergeTwoSortedRanges(A),2,5,7;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}