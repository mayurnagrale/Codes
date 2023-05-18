//Topic std:: unordered set

//Notes
// Set of unique object
// Search Insertion and Removal will have costant time complexity
//

#include<bits/stdc++.h>
using namespace std;

bool comp(string &a,string &b){
    
    int first=a[a.length()-1]-'0';
    int second=b[b.length()-1]-'0';

    for(int i=a.length()-2;i>=0;i--){
        if(a[i]-'0'>=0 && a[i]-'0'<=9){
            first+= 10*(a[i]-'0');
        }

    }
    for(int i=b.length()-2;i>=0;i--){
        if(b[i]-'0'>=0 && b[i]-'0'<=9){
            second+= 10*(b[i]-'0');
        }
    }
    if(first>second){
        return true;
    }
    else{
        return false;
    }
}

vector<string> solve(vector<string> &A) {
    vector<string> res;
    sort(A.begin(),A.end(),comp);
    for(int i=0;i<A.size();i++){
        res.push_back(A[i]);
    }
    return res;
}



int main(){
    // unordered_set<int> uset = {4,1,2,3,4,2,3};

    // auto search = uset.find(2);
    // if(search != uset.end()){
    //     cout<< "Found "<<(*search)<<endl;
    // }
    // else{
    //     cout<<"Not Found"<<endl;
    // }

    // for(auto& elm : uset){
    //     cout<<elm<<" ";
    // }
    // cout<<endl;

    vector<string> A={"ad80","harsh95","shivam95"};
    vector<string> res=solve(A);

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    // string A="123";
    // cout<<(int)A[0]-'0';
    return 0;
}