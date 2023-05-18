#include<bits/stdc++.h>
using namespace std;

bool ps(int n){
    long long start=1;
    long long end=n;
    long long mid;

    while(start<=end){
        mid = (start+end)/2;
        if(mid*mid == n){
            return true;
        }
        if(mid*mid < n){
            start=mid+1;
            
        }
        else{
            end=mid-1;
        }
    }
    return false;
}
int main()  {
    int n;
    cin>>n;
    if(ps(n)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}