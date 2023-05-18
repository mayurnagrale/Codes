#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++) 
 
const int N=1e3+2, MOD=1e9+7;
int val[N],wt[N];

int dp[N][N];
//find the maximum value in given maximum/minimum weight

// int rec(vector<int> value,vector<int>wt,int maxwt,int n){
//     //base condition
//     if(n==0 || maxwt==0){
//         return 0;
//     }
//     if(wt[n-1]<=maxwt){
//         return value[n-1]+rec(value,wt,maxwt-wt[n-1],n-1);
//     }
//     if(wt[n-1]>maxwt){
//         return rec(value,wt,maxwt,n-1);
//     }
// }

int knapsack(int n,int w){
    if(w<=0){
        return 0;
    }
    if(n<=0){
        return 0;
    }

    if(dp[n][w] != -1){
       return dp[n][w];
    }

    if(wt[n-1]>w){
        dp[n][w]= knapsack(n-1,w);
    }
    else{
        dp[n][w]= max(knapsack(n-1,w),knapsack(n-1,w-wt[n-1])+val[n-1]); 
    }
    return dp[n][w];
}


signed main(){
    //creating a knapsack
    // vector<int> value={1,3,5,7,9};
    // vector<int>wt={1,3,6,7,9};
    // int maxwt=21;
    int n=9;
    //add values to the knapsack


    //call recursion to find the maximum value in given maximum weight
    // int ans=rec(value,wt,maxwt,n);
    //cout<<ans;
    //add dp/memoization to the existing recursion to save the calculations
    //cout<<"KnapSack";

    rep(i,0,N){
        rep(j,0,N){
            dp[i][j]=-1;
        }
    }

    rep(i,0,n){
        cin>>wt[i];
    }

    rep(i,0,n){
        cin>>val[i];
    }

    int w;
    cin>>w;

    cout<<knapsack(n,w);

    return 0;
}

