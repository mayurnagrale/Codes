#include<bits/stdc++.h>
using namespace std;

//kadane's algorithm
int kadane(int * arr, int n){
    int currSum=0;
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        if(currSum<0){
            currSum=0;
        }
        mx=max(currSum,mx);
    }

    return mx;

}

int main(){
    int arr[]={4,-4,6,-6,10,-11,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    int currSum=0;
    int mx=INT_MIN;

    int wrapsum;
    int nonwrapsum;
    nonwrapsum=kadane(arr,n);

    cout<<nonwrapsum<<endl;   

    for(int i=0;i<n;i++){
        sum+=arr[i];
        arr[i]=-arr[i];
    }

    wrapsum = sum + kadane(arr,n);

    cout<<wrapsum<<endl;

}