#include<bits/stdc++.h>
using namespace std;

int MAX(int x,int y){
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}

int solve(int * A, int size,int B){
    //prefix array
    int pf[size];
    int max=INT_MIN;

    pf[0]=A[0];
    for(int i=1;i<size;i++){
        pf[i]=pf[i-1]+A[i];
    }
    
    for(int i=0;i<size;i++){
        if(i==0){
            max=MAX(max,pf[B-1]);
        }
        if(i==(size-B)){
            max=MAX(max,pf[size-1]-pf[i-1]);
        }
        if(i>(size-B)){
            max=MAX(max,pf[size-1]-pf[i-1]+pf[i-(size-B+1)]);
        }
    }
    return max;
}

int main(){
    int res;
    int A[5]={5,-2,3,1,2};
    int B=3;
    int size=sizeof(A)/sizeof(int);
    cout<<solve(A,size,B);
    return 0;
}