#include<iostream>
using namespace std;

//using recursion
int countOne(int n,int count){
    if((n && !(n & n-1)) == 1)
        return count;
    n = (n & (n-1));
    count++;
    countOne(n,count);
}
//using simple while loop
int numberOfOnes(int n){
    int count=0;
    while(n){
        n = (n & (n-1));
        count++;
    }
    return count;
}

int main(){
    cout<<countOne(19,1)<<endl;
    cout<<numberOfOnes(19)<<endl;
    return 0;
}