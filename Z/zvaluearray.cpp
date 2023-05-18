#include<bits/stdc++.h>
using namespace std;

//Z value array using bruteforce approach
vector<int> zArray(vector<string> &A){
    vector<int> z(A.size());
    int value=0;
    fill(z.begin(),z.end(),value);

    int j,k;
    z[0]=-1;
    for(int i=1;i<A.size();i++){
        j=i;
        k=0;
        while(j<A.size() && A[j] == A[k]){
            j++;
            k++;
        }
        z[i]=k;

    }
    return z;
}

//Z value array using z-algorithm 
vector<int> zValueArray(vector<string> &A){
    vector<int> z(A.size());
    int value=0;
    fill(z.begin(),z.end(),value);


    return z;
}


int main(){
    vector<string> A={"x","x","y","z","x","x","y","z","w","x","x","y","z","x","x","y","z","x"};
    vector<int> res=zArray(A);

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}