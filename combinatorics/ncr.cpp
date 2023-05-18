#include<bits/stdc++.h>
using namespace std;

//will not work value greater than 31
int fact(int n){
    if(n<2){
        return 1;
    }
    return fact(n-1)*n;
}

//nth fibbonacci without using dp solution
int fibSimple(int n){
    if(n<=1){
        return n;
    }
    return fibSimple(n-1)+fibSimple(n-2);
}

//nth fibbonacci using dp solution 
int fib(int n,int* dp){
    if(n<=1)
        return n;
    if(dp[n]!= -1){
        return dp[n];
    }
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    // return fib(n-1)+fib(n-2);
    return dp[n];
}

//nth fibbonacci using dp tabulation
int fibTab(int n,int* dp){
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

//ncr can be calculated using smaller terms
int ncr(int n,int r,int m,int* dp){
    if(r==n){
        return 1;
    }
    if(r==0){                     
        return 1;
    }
    if(r>n){
        return 0;
    }
    // if(dp[n] != -1){
    //     return dp[n];
    // }
    //dp[n] = ncr(n-1,r,m,dp)+ncr(n-1,r-1,m,dp);  
    return (ncr(n-1,r,m,dp)%m+ncr(n-1,r-1,m,dp)%m)%m;//dp[n]%m;
}

//ncr using pascal triangle
int ncrPascal(int n,int r,int m){
    if(n<r){
        return 0;
    }
    if(n-r<r){
        r=n-r;
    }
    int dp[r+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=min(i,r);j>0;j--){
            dp[j]=(dp[j]+dp[j-1])%m;
        }
    }
    return dp[r];
}

//ncr pascal method 2
int ncrPascal2(int n, int r, int m)
{
    int arr[n + 1][r + 1];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i <= n; i++){
        arr[i][0] = 1;
    }

    for(int j=1;j<=r;j++){
        arr[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=r;j++){
            arr[i][j]=(arr[i-1][j]%m + arr[i-1][j-1] %m)%m;
        }
    }

    // for (int i = 0; i <= n; i++)+++++++++++++++++++++++++++++++++
    // {
    //     for (int j = 0; j <= r; j++)
    //     {
    //         cout <<arr[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    return arr[n][r];
}

signed main(){
    int A=5;//32;
    int B=5;//40;//5;
    int C=143;
    int N=100000;//10^5
    //int N=le5+2, MOD=le9+7;
    int dp[N];
    //initialise dp with -1
    for(int i=0;i<N;i++){
        dp[i] = -1;
    }

    //cout<<fact(A)<<endl;
    //cout<<ncr(A,B,C,dp)%13<<endl;
    // for(int i=0;i<=B;i++){
    //     cout<<fib(i,dp)<<" ";
    //     //cout<<fibSimple(i)<<" "; // we can see that this solution is taking more time than dp solution 
    // }

    //cout<<fibTab(8,dp)<<endl;

    cout<<ncrPascal(A,B,C)<<endl;
    ncrPascal2(A,B,C);

    return 0;
}