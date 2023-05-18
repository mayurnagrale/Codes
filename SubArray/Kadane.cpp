#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define fr(i,a,b) for(int i=a;i<b;i++)

int main(){
    int n;
    // cin>>n;
    // vi v(n);
    // fr(i,0,n){
    //     cin>>v[i];
    // }
    vector<int> v={-500,-2,1};
    n=v.size();
    int curr=0,maxTillNow=0,maxSoFar=INT_MIN;

    for(int i=0;i<n;i++){
        curr+=v[i];
        
        maxTillNow = max(maxTillNow,curr);
        maxSoFar = max(maxSoFar,curr);
        if(curr<0)
            curr=0;
    }
    if(maxTillNow==0){
        cout<<maxSoFar;
    }
    else{
        cout<<maxTillNow;
    }
    return 0;
}