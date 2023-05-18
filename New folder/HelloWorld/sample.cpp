#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int> arr(6);
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            arr[i][j]=1;
        }
    }
    cout<<arr.size()<<endl;
    cout<<arr[0].size()<<endl;
}