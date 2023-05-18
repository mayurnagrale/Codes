#include<bits/stdc++.h>
using namespace std;

void fn(vector<int> S,int k){
    //cout<<S.size()<<endl;
    //cout<<k;
    vector<int> maxAr;
    int i=0;
    int j=0;
    int sum =0;
    int mx=0;
    while(j<S.size()){
        sum = sum + S[j];
        if(j-i+1<k)
            j++;
        else if (j-i+1 == k)
        {
            //calculation
            mx=max(mx,sum);
            maxAr.push_back(sum);
            //sliding winodw
            sum=sum-S[i];
            i++;
            j++;
        }        
    }
    for(int it=0;it<maxAr.size();it++){
        cout<<maxAr[it]<<" ";
    }
    cout<<"max is : "<<mx;
}
int main(){
    vector<int> S;
    int k;
    S.push_back(1);
    S.push_back(2);
    S.push_back(3);
    S.push_back(4);
    S.push_back(5);
    S.push_back(6);
    S.push_back(7);
    S.push_back(8);

    cout<<"Enter window size :";
    cin>>k;
    
    fn(S,k);
    return 0;
}