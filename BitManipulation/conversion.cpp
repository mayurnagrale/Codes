#include<bits/stdc++.h>
using namespace std;

//Decimal To Binary
string DecimalToBinary(int A){
    int m,d;
    string res="";
    d=A;
    while(d!=0){
        m=d%2;
        res = char(m+'0')+res;
        d=d/2;
    }
    return res;
}

//Binary To Decimal
int BinaryToDecimal(string A,int n){
    int num=0;
    for(int i=n-1;i>=0;i--){
        if(A[i]=='0'){
            num+=0*pow(2,n-i);
        }
        else{
            num+=1*pow(2,n-i-1);
        }
            
    }
    return num;
}

//reverse the bit

unsigned int solve(unsigned int A){
    string res=DecimalToBinary(A);
    cout<<res<<endl;
    //reverse(res.begin(), res.end());
    int n = res.length();
    for (int i = 0; i < n / 2; i++)
        swap(res[i], res[n - i - 1]);
    cout<<res<<endl;
    int ans=0;
    for(int i=0;i<res.length();i++){       
        if(res[i]=='1'){
            ans += pow(2,32-(i+1));
        }
    }
    return ans;
}

int main(){
    string A="10110";
    //cout<<"Decimal of binary "<<A<<" : "<<BinaryToDecimal(A,A.length())<<endl;
    //cout<<DecimalToBinary(3)<<endl;
    cout<<solve(2);
}