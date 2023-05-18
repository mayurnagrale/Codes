#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ll long long

ll lcm(ll a,ll b){
    return a*b/__gcd(a,b);
}

int main(){
    cout << "gcd(6, 20) = " <<__gcd(6, 20) << endl;
    cout<< "lcm="<<lcm(6,20); 
    cout<<endl;
    //lcm of three numbers
    cout<<"lcm="<<lcm(lcm(6,20),3);
    return 0;
}
