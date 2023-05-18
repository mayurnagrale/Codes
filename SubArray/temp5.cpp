#include<bits/stdc++.h>
using namespace std;

vector<int> pf(vector<int> A){
    vector<int> pfs;
    pfs.push_back(A[0]);
    for(int i=1;i<A.size();i++){
        pfs.push_back(pfs[i-1]+A[i]);
    }
    return pfs;
}

float Min(float x,float y){
    if(x<y){
        return x;
    }
    else{
        return y;
    }
}

int main() {
    vector<int> A={18, 11, 16, 19, 11, 9, 8, 15, 3, 10, 9, 20, 1, 19}; 
    int B=1;
    // vector<int> A={3, 7, 90, 20, 10, 50, 40};
    // int B=3;
    // vector<int> A={20, 3, 13, 5, 10, 14, 8, 5, 11, 9, 1, 11};
    // int B=9;
    int e=0;
    float la=340282346638528859811704183484516925440.0000000000000000;
    float sum=0.0;
    int idx=0;
    vector<int> pfA=pf(A);
    for(int i=0;i<pfA.size();i++){
        cout<<pfA[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<=A.size()-B;i++){
        e=i+B-1;
        if(i==0){
            sum=pfA[e];
            la=Min(la,sum/B);
            cout<<la<<" ";
        }
        else{
            sum=pfA[e]-pfA[i-1];
            if(Min(la,sum/B)<la){
                idx=i;
            }
            la=Min(la,sum/B);
            cout<<la<<" ";
        }
    }
    cout<<endl;
    cout<<la<<" "<<idx;
    return 0;    
}
