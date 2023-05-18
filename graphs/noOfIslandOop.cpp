#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
        int numsIsland(vector<vector<char>> &grid){
            if(!grid.size()) return 0;
            if(!grid[0].size()) return 0;

            int count=0;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]=='1'){
                        count++;
                        dfs(grid,i,j);
                    }
                }
            }
            return count;
        }
        void dfs(vector<vector<char>>grid,int x,int y){
            grid[x][y]='0';
            if(x+1<grid.size() && grid[x+1][y]=='1'){
                dfs(grid,x+1,y);
            }
            if(x-1>=0 && grid[x-1][y]=='1'){
                dfs(grid,x-1,y);
            }
            if(y-1>=0 && grid[x][y-1]=='1'){
                dfs(grid,x,y-1);
            }
            if(y+1<grid[0].size() && grid[x][y+1]=='1'){
                dfs(grid,x,y+1);
            }
        }
        void main(){
            vector<vector<char>> grid={{'1','1','0'},{'0','0','0'},{'0','1','1'}};
            cout<<numsIsland(grid);
        }
};