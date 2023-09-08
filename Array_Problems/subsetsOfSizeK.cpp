#include<bits/stdc++.h>
using namespace std;

//Using bitmanipulation
void printSubset(vector<int> &arr, int k){
    //Convert into binary
    for(int i=0;i<pow(2,arr.size());i++){
        vector<int> v;
        int x=i; //x=8
        while(x>0){
            int z=x%2; // 0 0 0 1
            v.push_back(z);
            x=x/2; //4 2 1 0
        }

        int p= arr.size()-v.size();
        for(int j=1;j<=p;j++){
            v.push_back(0);
        }

        reverse(v.begin(),v.end());

        int count=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==1){
                count++;
            }
        }

        if (count == k){
            for (int i = 0; i < v.size(); i++){
                if (v[i] == 1){
                    cout<<arr[i]<< " ";
                }
            }
            cout<<endl;
        }

        v.clear();
    }
}

int main(){
    vector<int> arr={3,5,4,2};
    int k=3;
    printSubset(arr,k);
    return 0;
}