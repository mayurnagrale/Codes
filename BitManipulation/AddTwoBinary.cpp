#include<bits/stdc++.h>
using namespace std;

//Add two binary numbers
string AddBinary(string A,string B){
    int carry=0;
    int temp=0;
    string res="";
    int lenA=A.length()-1;
    int lenB=B.length()-1;
    int a,b;
    while(lenA>=0 || lenB>=0 || temp==1){
        int add=((lenA>=0)?A[lenA]-'0':0)+((lenB>=0)?B[lenB]-'0':0)+carry;
        temp=add%2;
        carry=add/2;
        res=char(temp+'0')+res;
        lenA--;lenB--;
    }
    return res;
}

int main(){
    string A="10011";
    string B="001";
    cout<<AddBinary(A,B);
    return 0;
}