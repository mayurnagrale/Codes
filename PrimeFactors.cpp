#include<bits/stdc++.h>
using namespace std;

void PrimeFactors(int n)
{
    for(int i=2 ; i<sqrt(n); i++)
    {
        if(n%i == 0){
            int ct=0;
            while(n%i == 0){
                n=n/i;
                ct++;
            }
            cout<<i<<" "<<ct<<endl;
        }
    }
    if(n!=1){
        cout<<n<<" "<<1;
    }
}

int main()
{
    int n;
    cin>>n;
    PrimeFactors(n);
    return 0;
}