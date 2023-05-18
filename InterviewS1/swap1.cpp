#include<bits/stdc++.h>
using namespace std;

int solve(string A) {
    int count=0;
    int ans=0,len=0;
    int l,r;
    cout<<A.length()<<endl;
    for(int i=0;i<A.length();i++){
        if(A[i]=='1'){
            count++;
        }
    }
    cout<<count<<endl;
    for(int i=0;i<A.length();i++){
        if(A[i]=='0'){
            l=0;
            for(int j=i-1;j>=0;j--){
                if(A[j]=='1'){
                    l++;
                }
                else{
                    break;
                }
            }
            r=0;
            for(int j=i+1;j<A.length();j++){
                if(A[j]=='1'){
                    r++;
                }
                else{
                    break;
                }
            }
            if(l+r<count){
                len=l+r+1;
            }
            else{
                len=l+r;
            }
            ans=max(ans,len);
            len=0;
        }
    }
    if(count==0) return 0;
    if(ans==0) return A.length();
    return ans;
}


int main(){
    string A = "11010110000000000";
    cout<<solve(A);
    return 0;
}