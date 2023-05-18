#include <bits/stdc++.h>
using namespace std;

class Point{
  int x;
  int y;
  public:
   Point(int x,int y){
      this.x=x;
      this.y=y;
  }  
};  

class Node{
    Point pt;//coordinate of a cell
    int dist;//cell's distance from the source
    public:
     Node(Point pt,int dist){
        this->pt=pt;
        this->dist=dist;
    } 
};

bool isValid(int row,int col,int ROW,int COL){
    return (row>=0) && (row<ROW) && (col>=0) && (col<COL);   
}

int BFS(vector<vector<int> &grid,Point source,Point dest,int ROW,int COL){
    queue<Node> q;
    vector<vector<int>>visited(COL,vector<int>(ROW,0));
    int rowN={-1,0,0,1};
    int colN={0,-1,1,0};
    //corner case
    if(grid[source.x][source.y] != 1 || grid[dest.x][dest.y] != 1 ){
        return -1;
    }

    visited[source.x][source.y]=1;

    Node s=Node(source,0);
    q.push(s);

    while(!q.empty()){
        Node curr=q.front();
        Point pt=curr.pt;

        //Checking if we are at dstination cell
        if(pt.x==dest.x && pt.y==dest.y){
            return curr.dist;
        }

        //dequeue the curr cell and add its neighbour cell
        q.pop();

        for(int i=0;i<4;i++){
            int row=pt.x + rowN[i];
            int col=pt.y + colN[i];

            //if the adjucent cell is valid and has not been visited yet
            //add it to the queue
            if(isValid(row,col,ROW,COL) && grid[row][col]==1 && !visited[row][col]){
                //mark that cell visited
                visited[row][col]=1;
                Node adj=Node(Point(row,col),curr.dist);
                q.push(adj);
            }
        }

    }
    return -1;

}

int main() {
    int ROW=0;
    int COL=0;
    Point source=Point(0,0);
    Point dest = Point(2,2);
    
    vector<vector<int> grid={{1,0,0},
                             {1,0,0},
                             {1,1,1}};

    ROW=grid.size();
    COL=grid[0].size();

    cout<<BFS(grid,source,dest,ROW,COL)<<endl;
    return 0;
}