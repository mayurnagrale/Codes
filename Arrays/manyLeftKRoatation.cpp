#include<bits/stdtr1c++.h>
using namespace std;

vector<int> reversePart(vector<int> arr,int k,int n){
    int i=k,j=n-1;
    int temp;
    while(i<j){
        //swap
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        //inc
        i++,j--;
    }
    return arr;
}

vector<int> kRotateLeftToRight(vector<int> arr,int k,int n){
    vector<int> revarr=reversePart(arr,0,n);
    // for(int i=0;i<n;i++){
    //     cout<<revarr[i]<<" ";
    // }
    // cout<<endl;
    //reverse first n-k elements
    vector<int> firstn_k=reversePart(revarr,0,n-k);
    // for(int i=0;i<n;i++){
    //     cout<<firstn_k[i]<<" ";
    // }
    // cout<<endl;
    //reverse remaining elements
    vector<int> remain=reversePart(firstn_k,n-k,n);
    return remain;
}

int main(){
    int n;
    vector<int> arr={1,2,3,4,5};
    vector<int> B={2,3};
    vector<vector<int>> res;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    int k=0;
    n=arr.size();
    for(int i=0;i<2;i++){
        k=B[i];
        //if k>n
        k=k%5;
        //cout<<k<<endl;
        //int* newkrotatedRL=kRotateRightToLeft(arr,k,n);
        vector<int> newkrotatedLR=kRotateLeftToRight(arr,k,n);
        res.push_back(newkrotatedLR);
        cout<<endl;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}