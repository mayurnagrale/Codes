#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<int>>area,int row,int col,vector<vector<int>>visited,int rowLength,int colLength){
    if(row>=0  && col>=0 && row<rowLength && col<colLength && area[row][col]==1 && visited[row][col]!=1){
        return true;
    }
    return false;
}

void DFS(vector<vector<int>>area,int row,int col,vector<vector<int>>visited,int rowLength,int colLength){
    int r[]={-1,-1,-1,0,0,1,1,1};
    int c[]={-1,0,1,-1,1,-1,0,1};
    visited[row][col] = 1;

    for(int k=0;k<8;k++){
        if(isValid(area,row+r[k],col+c[k],visited,rowLength,colLength)){
            DFS(area,row+r[k],col+c[k],visited,rowLength,colLength);
        }
    }
}

int numberofislands(vector<vector<int>>area,int rowLength,int colLength){
    //no of connected components or no of islands
    int count=0;
    vector<vector<int>>visited(colLength,vector<int>(rowLength,0));
    //Iterate over every cell
    for(int i=0;i<rowLength;i++){
        for(int j=0;j<colLength;j++){
            //condition for calling a dfs on perticular cell
            if(visited[i][j]!=1 &&area[i][j]==1){
                //calling dfs for a cell i,j
                DFS(area,i,j,visited,rowLength,colLength);
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<vector<int>>area={{1,1,0},
                             {0,0,0},
                             {0,1,1}};
    vector<vector<int>>M={
            {1,1,0,0,0},
            {0,1,0,0,1},
            {1,0,0,1,1},
            {0,0,0,0,0},
            {1,0,1,0,1}
        };
    int rowLength=area.size();
    int colLength=area[0].size();
    cout<<numberofislands(area,rowLength,colLength);
    return 0;
}