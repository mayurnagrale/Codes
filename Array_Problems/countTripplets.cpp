#include<bits/stdc++.h>
using namespace std;


int countTripplets(vector<int> arr,int r){
    int count=0;
    unordered_map<int,int> before;
    unordered_map<int,int> after;

    //put all the elements in after dictionary
    for(int i=0;i<arr.size();i++){
        after[arr[i]]++;
    }

    for(int i=0;i<arr.size();i++){
        int curr=arr[i];
        after[curr]--;

        if(curr%r==0 && before.find(curr/r) != before.end() && before[curr/r]>0 && after.find(curr*r) != after.end() && after[curr*r]>0){
            count += before[curr/r] * after[curr*r];
        }

        before[curr]++;  
    }

    return count;
}

int main(){
    vector<int> arr={1,4,4,16,64};
    int r=4;
    cout<<countTripplets(arr,r);
    return 0;
}
