#include<bits/stdc++.h>
using namespace std;

// void printNo(int n){
//     if(n==1){
//         cout<<1<<" ";
//         return;
//     }
//     cout<<n<<" ";
//     printNo(n-1);
//     cout<<n<<" ";
// }

//Check Palindrome
bool isPal(string s,int x,int y){
    if(x>y){
        return true;
    }

    if(s[x]==s[y]){
        isPal(s,x+1,y-1);
    }
    else{
        return false;
    }
}

int sumOfDigits(int A){
    if(A/10 == 0){
        return A;
    }
    return sumOfDigits(sumOfDigits(A/10) + A%10);
}

int solveSum(int A) {
    if(sumOfDigits(A)==1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    //int n=5;
    // string s="madam";
    // int r=s.length()-1;
    // cout<<r<<endl;
    // bool x=isPal(s,0,r);
    // if(x){
    //     cout<<"true";
    // }
    // else{
    //     cout<<"false";
    // }
    //cout<<isPal(s,0,s.length()-1);
    //printNo(n);

    cout<<solveSum(83557);
    return 0;
}