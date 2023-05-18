#include<bits/stdc++.h>
using namespace std;

void picktoy(vector<string> S,int k){
    int i=0,j=0;
    unordered_map<string,int> m;
    //map<string,int>m;
    int mx=INT16_MIN;
    //cout<<S.size();
    int count=0;
    while(j<S.size()){
        //
        m[S[j]]++;
        if(m.size()<k)
        {
            j++;
        }
        else if(m.size() == k)
        {
            count = j-i+1;
            mx=max(mx,count);
            j++;  
        }
        else if(m.size()>k)
        {
            while(m.size()>k)
            {
                m[S[i]]--;
                if(m[S[i]]==0)
                {
                    m.erase(S[i]);
                }
            }
            i++,j++;
        }
    }
    cout<<mx;
}
int main(){
    vector<string> S;
    int k;
    S.push_back("a");
    S.push_back("b");
    S.push_back("a");
    S.push_back("c");
    S.push_back("c");
    S.push_back("a");
    S.push_back("b");
    S.push_back("a");

    cout<<"Enter window size :";
    cin>>k;
    
    picktoy(S,k);
    return 0;
}