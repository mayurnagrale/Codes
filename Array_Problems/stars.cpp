#include<bits/stdc++.h>
using namespace std;

int val(vector<int> &a,int n,int sum){
    int mid=n/2;
    for(int i=0;i<n/2;i++){
        if(a[mid]*n<= sum){
        mid=mid+1;
    }
    else{
        return mid;
    }
    }
    
}

int main(){
    int n=5;
    vector<int> a={2,3,4,5,6};
    sort(a.begin(),a.end());

    int sum=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
    }

    cout<<sum;

    cout<<val(a,n,sum);



}

/**
 * @brief     for(int i=1;i<=4;i++){
        for(int j=1;j<i;j++){
            cout<<"*";
        }

        for(int j=1;j<=i;j++){
            cout<<"^";
        }
        cout<<"*"<<endl;
    }
 * 
 */