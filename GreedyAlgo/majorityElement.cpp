#include<iostream>
using namespace std;

void majorityElement(int A[],int length){
    int ansIndex=0;
    int count=1;
    for(int i=1;i<length;i++){
        if(A[i]==A[ansIndex]){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            ansIndex=i;
            count=1;
        }
    }
    for(int i=0;i<length;i++){
        if(A[ansIndex]==A[i])
            count++;
    }
    if(count>length/2){
        cout<<A[ansIndex]<<endl;
    }
    else{
        cout<<0<<endl;
    }
}

int main(){
    int A []={5,1,4,5,5,99};
    majorityElement(A,5);
    return 0;
}