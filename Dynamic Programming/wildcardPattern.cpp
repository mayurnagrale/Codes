#include<bits/stdtr1c++.h>
using namespace std;

bool solution(string s,string p){
    int dp[s.length()+1][p.length()+1];

    for(int i=dp.length()-1;i>=0;i--){
        for(int j=dp[0].length()-1;j>=0;j--){
            if()
        }
    }

    for(int i=s.length();i>=0;i--){
        for(int j=p.length();j>=0;j--){
            if(i==0 && j==0){

            }
            else if(i==0){

            }
            else if(j==0){

            }
        }
    }
    return true;
}

int main(){
    string s="abcde";
    string p="xyz";
    cout<<solution(s,p);

    return 0;
}