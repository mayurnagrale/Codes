#include<bits\stdc++.h>
using namespace std;
//bruteforce
void candy(vector<int> &A){
    int n=A.size();
    int sum=0;
    int temp=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
            mp[A[i]]++;
    }
    std::map<int, int> ordered(mp.begin(), mp.end());
    for(auto x:ordered){
        cout<<x.first<<" "<<x.second<<endl;
        sum=sum + (1 * (n-temp));
        temp = temp+x.second;
    }
    cout<<sum<<endl;
}

void optimulCandy(vector<int> &A){
    int count=1;
    int temp=1;
    std::sort(A.begin(),A.end());
    cout<<A[0]<<" ";
    for(int i=1;i<A.size();i++){
        cout<<A[i]<<" ";
        if(A[i-1]!=A[i]){
            temp++;
        }
        count = count + temp;
    }
    cout<<endl;
    cout<<count<<endl;
}
int main(){
    //Array of ranks or rating
    vector<int> A={1,3,2,1};
    //candy(A);
    optimulCandy(A);
    return 0;
}