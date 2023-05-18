#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> Arr,int l,int mid, int r){
    int n1=mid-l+1;
    int n2=r-mid;

    int a[n1];
    int b[n2];  //temp array

    for(int i=0;i<n1;i++){
        a[i]=Arr[l+i];
    }

    for(int i=0;i<n2;i++){
        b[i]=Arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            Arr[k]=a[i];
            k++;
            i++;
        }
        else{
            Arr[k]=b[j];
            k++;
            j++;
        }
    }

    while(i<n1){
        Arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2){
        Arr[k]=b[j];
        k++;
        j++;
    }
}

void mergeSort(int A[],int si,int ei){
    int mid = si+(ei-si)/2;
    mergeSort(A,si,mid);
    mergeSort(A,mid+1,ei);
    merge(A,si,mid,ei);
}

int main(){
    vector<int> A={};
    vector<int> res=mergeSort(A,0,A.size()-1);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}