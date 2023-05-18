#include<bits/stdc++.h>
using namespace std;

//gcd using recursion
int gcd(int a,int b){
    while(a>0){
        int temp = a;
        a=b%a;
        b=temp;
    }
    return b;
}

//gcd of an entire array
int gcdOfArray(vector<int> &A){
    int ans=0;
    for(int i=0;i<A.size();i++){
        ans=gcd(ans,A[i]);
    }
    return ans;
}

//if gcd of 1 subset exist or not
bool gcdSubsetOne(vector<int> &A){
    if(gcdOfArray(A)==1){
        return true;
    }
    else{
        return false;
    }
}

//prefix gcd array
vector<int> prefixGcd(vector<int> &A){
    vector<int> prefixgcd;
    prefixgcd.push_back(A[0]);
    for(int i=1;i<A.size();i++){
        prefixgcd.push_back(gcd(prefixgcd[i-1],A[i]));
    }
    return prefixgcd;
}

//sufix gcd array
vector<int> sufixGcd(vector<int> &A){
    vector<int> sufixgcd(A.size(),0);
    sufixgcd[A.size()-1]=A[A.size()-1];
    for(int i=A.size()-2;i>=0;i--){
        sufixgcd[i] = gcd(sufixgcd[i+1],A[i]);
    }
    return sufixgcd;
}

//max possible gcd after deleting 1 ele
int maxPosGcd(vector<int> &A){
    int ans=INT_MIN;
    int res=0;
    vector<int> prefix_gcd = prefixGcd(A);
    vector<int> sufix_gcd = sufixGcd(A);
    for(int i=0;i<A.size();i++){
        if(i==0){
            res=gcd(0,sufix_gcd[i+1]);
        }
        if(i==A.size()-1){
            res=gcd(prefix_gcd[i-1],0);
        }
        res= gcd(prefix_gcd[i-1],sufix_gcd[i+1]);
        ans=max(res,ans);
    }
    return ans;
}

//convert string to int
long long int stringToInt(string A){
    // int ans=A[A.size()-1]-'0';
    // int temp;
    // int itr=1;
    // for(int i=A.size()-2;i>=0;i--){
    //     temp=10*(A[i]-'0');
    //     ans += pow(10,itr)*(A[i]-'0');
    //     itr++;
    // }
    // return ans;
    long long int temp = 0;
    for (int i = 0; i < A.size(); i++) {
        temp = temp * 10 + (A[i] - '0');
    }
    return temp;
}

int main(){
    vector<int> A= {4, 17, 2, 6};
    vector<int> B ={9,18,49,12,30};
    string s="678728391838182039102";
    // cout<<gcd(12,15)<<endl;
    // cout<<gcd(120,270)<<endl;
    // cout<<gcdOfArray(A)<<endl;
    // cout<<gcdSubsetOne(A)<<endl;
    // cout<<maxPosGcd(B)<<endl;
    cout<<stringToInt(s)<<endl;
    return 0;
}