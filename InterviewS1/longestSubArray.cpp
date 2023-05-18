#include<bits/stdc++.h>
using namespace std;

//replace 0 with 1 in binary subarray and get the longest subarray of one
int firstSolution(vector<int> &A){
    int l=0,r=0,maxlen=0;
    for(int i=0;i<=A.size();i++){
        if(A[i]==0 || i==A.size()){
            if(r==A.size()){
                return r;
            }
            maxlen=max(maxlen,l+r+1);
            l=r;
            r=0;
        }
        else{
            r++;
        }
    }
    return maxlen;
}

//solution using bruteforce approach 
int secondSolution(vector<int> &A){
    int l,r,maxlen=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            l=0;
            for(int j=i-1;j>=0;j--){
                if(A[j]==1){
                    l++;
                }
                else{
                    break;
                }
            }
            r=0;
            for(int j=i+1;j<A.size();j++){
                if(A[j]==1){
                    r++;
                }
                else{
                    break;
                }
            }
            maxlen=max(maxlen,l+r+1);
        }
    }
    if(maxlen==0){
        return A.size();
    }
    return maxlen;
}

//swap the 0 with 1 from the same array and get the longest subarray of 1 we can get
int thirdSolution(vector<int> &A){
    int c=0;
    for(int i=0;i<A.size();i++){
        if(A[i]){
            c++;
        }
    }
    return c;
}

int main(){
    vector<int> A={1,1,1,1,0};
    //int res=firstSolution(A);
    //int res=secondSolution
    int res=thirdSolution(A);
    cout<<res<<endl;
    return 0;
}