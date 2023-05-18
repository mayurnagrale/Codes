#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={-1,4,7,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    int mx=-100;
    //Brute force approach
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                //cout<<arr[k]<<" ";
                sum=sum+arr[k];
            }
            //cout<<endl;
            mx=max(sum,mx);
            sum=0;
        }
    }
    //cout<<mx;

    //Cumulative sum approach
    int currSum[n+1];
    currSum[0]=0;
    int newmx=INT_MIN;
    //loop for cumulative sum
    for(int i=1;i<=n;i++){
        currSum[i]=currSum[i-1]+arr[i-1];
    }
    int sumnew;
    for(int i=1;i<=n;i++){
        sum=0;
        for(int j=0;j<i;j++){
            sumnew=currSum[i]-currSum[j];
            newmx=max(sumnew,newmx);
        }
    }

    //cout<<newmx;

    //O(n) Kadane's Algorithm
    int newcurrSum=0;
    int newmax=INT_MIN;
    for(int i=0;i<n;i++){
        newcurrSum +=arr[i];
        if(newcurrSum<0){
            newcurrSum=0;
        }
        newmax=max(newmax,newcurrSum);
    }
    cout<<newmax;
    return 0; 
}   