#include<bits/stdc++.h>
using namespace std;


int jumps(vector<int> arr){
    int count=0;
    int start= 0;
    int end=arr.size();

    while(start<end){
        if(arr[start]==0){
            return -1;
        }
        int idx;
        int max;
        for(int j=start+1;j<=arr[start]+start;j++){
                max=INT_MIN;
                if(arr[j]>max){
                    max=arr[j];
                    idx=j;
                }
        }
        count++;
        if(idx+max>=arr.size()){
            return count;
        }
        else{
            start=idx;  
        }
    }

    return count;
}



int main(){
    vector<int> a={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout<<jumps(a);
    return 0;
}