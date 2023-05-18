#include<bits/stdc++.h>
using namespace std;

void selectionSort(int* arr,int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            temp=arr[i];
            if(arr[i]>arr[j]){
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int KthMin(vector<int> A,int B){
    int temp;
    int min;
    int idx;
    vector<int> res;
    for(int i=0;i<A.size();i++){
        temp=A[i];
        min=A[i];
        for(int j=i+1;j<A.size();j++){
            if(A[j]<min){
                min=A[j];
                idx=j;
            }
        }
        if(A[i]>min){
            A[i]=min;
            A[idx]=temp;
        }
        res.push_back(A[i]);
        cout<<res.size()<<" : "<<A[i]<<endl;
        if(B==res.size()){
            return res[B-1];
        }
    }
}

int KthSmallest(vector<int> A,int B){
    int temp;
    int min;
    int idx;
    vector<int> Arr=A;
    vector<int> res;
    for(int i=0;i<Arr.size();i++){
        temp=Arr[i];
        min=Arr[i];
        for(int j=i+1;j<Arr.size();j++){
            if(Arr[j]<min){
                min=Arr[j];
                idx=j;
            }
        }
        if(Arr[i]>min){
            Arr[i]=min;
            Arr[idx]=temp;
        }
        res.push_back(Arr[i]);
        cout<<res.size()<<" : "<<Arr[i]<<endl;
        if(B==res.size()){
            return res[B-1];
        }
    }
}

int main(){
    int arr[]={8, 16, 80, 55, 32, 8, 38, 40, 65, 18, 15, 45, 50, 38, 54, 52, 23, 74, 81, 42, 28, 16, 66, 35, 91, 36, 44, 9, 85, 58, 59, 49, 75, 20, 87, 60, 17, 11, 39, 62, 20, 17, 46, 26, 81, 92};
    vector<int> A = {8, 16, 80, 55, 32, 8, 38, 40, 65, 18, 15, 45, 50, 38, 54, 52, 23, 74, 81, 42, 28, 16, 66, 35, 91, 36, 44, 9, 85, 58, 59, 49, 75, 20, 87, 60, 17, 11, 39, 62, 20, 17, 46, 26, 81, 92};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    cout<<KthMin(A,9);
    cout<<KthSmallest(A,9);
    return 0;
}