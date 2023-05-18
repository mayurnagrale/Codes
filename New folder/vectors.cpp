#include<bits/stdc++.h>
using namespace std;

int p1(vector<int> &A){
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
}

vector<int> p2(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int sum=0;
    int count=0;
    for(int i=0;i<B.size();i++){
        for(int j=0;j<A.size();j++){
            sum=sum+A[j];
            if(sum<B[i]){
                count++;
            }
        }
        C.push_back(count);
        count=0;
        sum=0;
    }
    return C;
}

int main(){
    //vector<int> A={2, 4, 3, 1, 5};
    vector<int> A={3, 4, 4, 6};
    vector<int> B={20, 4, 10, 2};
    //p1(A);
    vector<int> C=p2(A,B);
    for(int i=0;i<C.size();i++){
        cout<<C[i]<<" ";
    }
    return 0;
}

// for(std::vector<T>::iterator it = v.begin(); it != v.end(); ++it) {
//     it->doSomething();
//  }

[0 0 0 
 0 0 0
 0 0 0]