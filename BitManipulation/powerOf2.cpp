#include<iostream>
using namespace std;

bool powerOfTwo(int n){
    return (n && !(n & n-1));
}

int main(){
    cout<<powerOfTwo(64)<<endl;
    cout<<powerOfTwo(23)<<endl;
    return 0;
}