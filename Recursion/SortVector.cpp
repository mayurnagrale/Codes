#include<bits/stdc++.h>
using namespace std;

void insertV(vector<int> &V,int temp){
    if(V.size()==0 || V[V.size()-1] <= temp)
    {
        V.push_back(temp);
        return;
    }
    int val=V[V.size()-1];
    V.pop_back();
    insertV(V,temp);
    V.push_back(val);

    }

void sortV(vector<int> &V)
    {
    if(V.size()==0 || V.size() == 1)
    {
        return;
    }
    int temp = V[V.size()-1];
    V.pop_back();
    sortV(V);
    insertV(V,temp);

    }

    

int main(){
    vector<int> V = {3,4,1,2,5};
    sortV(V);
    for(int i=0;i<V.size();i++){
        cout<<V[i]<<" ";
    }
    return 0;
}