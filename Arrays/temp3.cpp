#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    vector<int>pf;
    int max=INT_MIN;
    int temp;
    for(int i=0;i<A.size();i++){
        if(i==0){
            pf.push_back(A[0]);
            max=A[0];
            temp=0;
        }
        else
        {
            pf.push_back(pf[i - 1] + A[i]);
            if (A[i] > max)
            {
                max = A[i];
                temp=i;
            }
        }
    }
    if(temp==0){
        return (max*(A.size()-1))-(pf[pf.size()-1]-pf[temp]);
    }
    return (max*(A.size()-1))-(pf[pf.size()-1]-pf[temp]+pf[temp-1]);
}

int main(){
    vector<int> A ={ 731, 349, 490, 781, 271, 405, 811, 181, 102, 126, 866, 16, 622, 492, 194, 735};
    int sum=0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
    }
    cout<<solve(A)<<endl;
    return 0;
}
//6684