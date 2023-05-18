#include<bits/stdc++.h> 
using namespace std;

void dfs(vector<vector<char>>grid,int i,int j,int n,int m){
    vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    int newi,newj;
    grid[i][j]=='$';
    for(int k=0;k<4;k++){
        newi=i+dir[k].first;
        newj=j+dir[k].second;
        if(newi>=0 && newj>=0 && newi<n && newj<m && grid[newi][newj]=='1'){
            dfs(grid,newi,newj,n,m);
        }
    }
}

void dfs2(int i,int j,int N,int M, vector<vector<int>> &mat){
    mat[i][j]=2;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int x,y;

    for(int k=0;k<4;k++){
        x=i+dx[k];
        y=j+dy[k];

        if(x>=0 && x<N && y>=0 && y<M && mat[x][y]==1){
            dfs2(x,y,N,M,mat);
        }
    }
}

int main(){
    // int n,m;
    int ans=0;
    // cout<<"enter input"<<endl;
    // cin>>n>>m;
    // vector<vector<char>>grid(n,vector<char>(m));
    vector<vector<int>> mat={{1,1,0},{0,0,0},{0,1,1}};
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cin>>grid[i][j];
    //     }
    // }
    // cout<<endl;
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]!=2 && mat[i][j] != 0){
                ans++;
                //dfs(grid,i,j,n,m);
                dfs2(i,j,mat.size(),mat[0].size(),mat);
            }
        }
    }
    cout<<"ans: "<<ans;
    return 0;
}
/*
3 3
1 1 0
0 0 0
0 1 1
*/

//https://www.twitch.tv/valorant