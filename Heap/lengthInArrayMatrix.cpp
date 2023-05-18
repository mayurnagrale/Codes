#include<bits/stdc++.h>
using namespace std;

int minimumDistance(vector<vector<int>> area){
    return area[0].size();
}

int main(){
    vector<vector<int>>area={{1,0,0},{1,0,0},{1,9,1}};
    cout<<minimumDistance(area);
    return 0;
}