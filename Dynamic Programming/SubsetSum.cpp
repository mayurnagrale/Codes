#include<bits/stdc++.h>
using namespace std;

const int N=1e3+2, MOD=1e9+7;

//Check target sum or subset sum are present or not using dynamic programming

bool checkSubsetSum(vector<int> &A,int sum){
    bool dp[A.size()+1][sum+1];
    for(int i=0;i<A.size()+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                dp[i][j]=false;             
            }
            else if(j==0){
                dp[i][j]=true;
            }
            else if(dp[i-1][j]){
                dp[i][j]=true;
            }
            else{
                int val=A[i-1];
                if(val>=j){
                    if(dp[i-1][j-val]==true){
                        dp[i][j]=true;
                    }
                }
            }
        }
    }
    return dp[A.size()][sum];
}
//subset sum solution using knapsack variation
//Print target sum subset 

//equal sum partition
bool equalSumPartition(vector<int> &A,int Asum){
    if(Asum%2==1){
        return false;
    }
    else{
        return checkSubsetSum(A,Asum/2);
    }
}

int main(){
    vector<int> A={2,3,7,8,10};
    int sum=11;
    int Asum=0;
    for(int i=0;i<A.size();i++){
        Asum += A[i];
    }
    cout<<checkSubsetSum(A,sum)<<endl;
    cout<<equalSumPartition(A,Asum);
    return 0;
}