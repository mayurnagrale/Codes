#include<iostream>
#include<math.h>
using namespace std;
#define MAX 1000

bool hashTable[MAX+1][2];

bool search(int val){
    if(val>=0){
        if(hashTable[val][0]==true){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        val=abs(val);
        if(hashTable[val][1]==true){
            return true;
        }
        else{
            return false;
        }
    }
}

void insert(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            hashTable[arr[i]][0]=true;
        }
        else{
            //to handle the negative numbers
            hashTable[abs(arr[i])][1]=true;
        }
    }
}

int main(){
    int arr[]={-1,9,2,-5,3,1};
    int n=sizeof(arr)/sizeof(int);
    insert(arr,n);
    int find = -3;
    if(search(find)){
        cout<<"Element is present in HashTable"<<endl;
    }
    else{
        cout<<"Element is not present in HashTable"<<endl;
    }
}