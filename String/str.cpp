#include<bits/stdc++.h>
using namespace std;

int expand(string str,int x,int y){
    
    while(x>=0 && y<str.length() && str[x]==str[y]){
            x--;
            y++;
    }
    return y-x-1;
}

int longestPalindrome(string A) {
    int ans=0;
    int temp=-1;
    string str;
    //for odd palindrome 
    for(int i=0;i<A.size();i++){
        if(ans<expand(A,i,i)){
            ans=expand(A,i,i);
            temp=i;
        }
    }

    //for even palindrome
    for(int i=0;i<A.size()-1;i++){
        if(ans<expand(A,i,i+1)){
            ans=expand(A,i,i+1);
            temp=i+1;
        }
    }
    int s=temp-(ans/2);
    int e = s+ans;
    for(int i=s;i<e;i++){
        str += A[i];
    }
    cout<<str<<endl;
    return ans;
}

string longestCommonPrefix(vector<string> &A) {
    string str=A[0];
    string temp="";
    for(int i=1;i<A.size();i++){
        int l=str.length();
        int al=A[i].length();
        for(int j=0;j<A[i].length();j++){    
            if(str[j]==A[i][j]){
                if(l>0 && al>0){
                    temp += str[j];
                    l--;
                    al--;
                }
                else{
                    break;
                }
            }
        }
        str=temp;
        temp="";
    }
    return str;
}

int main(){
    string str="umeaylnlfd";
    sort(str.begin(), str.end());
    //cout<<str<<endl;
    vector<string> A={"aaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aa", "aaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaa"};
    cout<<longestCommonPrefix(A);
    //cout<<longestPalindrome(str)<<endl;
    return 0;
}