#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,7,5,3,2,11};
    int s=15;
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    int j=0;
    int currSum=arr[i];
    while(i<n){
        if(currSum<s){
            j++;
            currSum+=arr[j];
        }
        else if(currSum==s){
            cout<<i<<" "<<j;
            break;
        }
        else{
            currSum=currSum-arr[i];
            i++;
        }

    }
    return 0;
}