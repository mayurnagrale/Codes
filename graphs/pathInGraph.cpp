#include<bits/stdc++.h>
using namespace std;

//Path in directed graph

void bfs(){

}

//Make adj list from 2D vector
void make_adj(int n,vector<vector<int>> &B){
    vector<int> adj[n+1];
    for(int i=0;i<B.size();i++){
        int u=B[i][0];
        int v=B[i][1];
        adj[u].push_back(v);
    }
}



int main(){
    int n;
    //Make visited array
    vector<bool> visited(n+1,false);
}