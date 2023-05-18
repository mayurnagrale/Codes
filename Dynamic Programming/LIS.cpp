#include<bits\stdc++.h>
using namespace std;

// int lengthOfLIS(vector<int> &A){
//     return LisHelper(-1,0,A);
// }

// int LisHelper(int prev,int curr, vector<int> Lis){

//     return 0;
// }

//nlogn approach
int lenOfLis(vector<int> &A){
    int n=A.size();
    cout<<n<<endl;
    vector<int> lis_arr;
    cout<<A[0]<<endl;
    lis_arr.push_back(A[0]);
    cout<<lis_arr.back()<<endl;
    for(int i=1;i<n;i++){
        if(lis_arr.back()<A[i]){
            lis_arr.push_back(A[i]);
        }
        else{
            int x=lower_bound(lis_arr.begin(),lis_arr.end(),A[i])-lis_arr.begin();
            lis_arr[x]=A[i];
        }
    }
    for(auto x:lis_arr){
        cout<<lis_arr[x]<<" ";
    }
    cout<<endl;
    return lis_arr.size();
}

int main(){
    vector<int> A={1,2,5,3,4};
    // cout<<lengthOfLIS(A)<<endl
    cout<<lenOfLis(A)<<endl;
    return 0;
}