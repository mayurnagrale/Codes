#include<iostream>
using namespace std;

int setBit(int n,int pos){
    return ((n & (1<<pos)) != 0);
}

void unique(int arr[],int n){
    int xorsum = 0;
    int setbit = 0;
    int pos = 0;
    int newxor = 0;
    int tempxor = 0;
    
    for(int i=0;i<n;i++){
     xorsum = xorsum ^ arr[i];
    }
    tempxor = xorsum;    
    while(setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    for(int i=0;i<n;i++){
        if(setBit(arr[i],pos-1)){
            newxor = newxor^ arr[i];
        }
    }
    cout<<newxor<<endl;
    cout<<(newxor^tempxor)<<endl;

}

int main(){
    int arr[8] = {2,4,6,7,6,5,4,2};
    unique(arr,8);
    return 0;
}