#include<bits/stdc++.h>
using namespace std;

void kClosest(int (&arr)[4][1],int n,int k){
    priority_queue<pair<int,pair<int,int>>> max_h;

}

int main(){
    int arr[4][1]={(0,1),(1,3),(-2,2),(5,8)};
    int n=sizeof(arr)/sizeof(arr[0][0]);
    int k=2;
    kClosest(arr,n,k);
    return 0; 
}