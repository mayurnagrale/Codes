#include<bits/stdc++.h>
using namespace std;

int solve1(int n){
    int sum;
    int count=0;
    int temp;
    for(int i=1;i<=n;i++){
        sum=0;
        temp=i;
        while(temp!=0){
            sum+=temp%10;
            temp=temp/10;
        }
        if(sum%2==0){
            count++;
        }
    }
    return count;
}

int solve2(string a,string b){
    int count=0;
    cout<<b[0]<<endl;;
    for(int i=0;i<a.length();i++){
        if(a[i]==b[0]){
            count++;
        }
    }
    cout<<count<<endl;
    cout<<a.length()<<endl;
    return count*100/a.length();
}


int main(){
    int a=30;
    cout<<solve1(44)<<endl;
    cout<<solve2("football","o")<<endl;
    return 0;
}