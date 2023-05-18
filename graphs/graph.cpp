#include <bits/stdc++.h>

using namespace std;

template<typename T>
//Adjucency list using hashmap
//hashmap<int,list<int>> al -- key and values inside list
//for undirected
/*
    int n,m
    for(int i=0;i<n;i++){
        //for undirected graph
        graph[u].insert(v);
        graph[v].insert(u);
    }
*/

//for weighted graph we have add nodes with its weight so
//hashmap<int,list<pair<int,int>>> al 

/*
    Traversal bfs and dfs

    (0)-----(1)
      \    /
       \  /
        (2)
         |
         |
        (3)

    0-1,2
    1-2,0
    2-0,1,2
    3-2
*/

// Graph class using adjacency list
class Graph {
private:
    int V; // number of vertices
    vector<vector<int>> adjList; // adjacency list

public:
    // Constructor to initialize graph
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // for an undirected graph
    }

    // Function to print the graph
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> ";
            for (auto j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};


void BFS(string source){
    //
}


//Weighted edge graph using hashmap
//A-(B,20),(D,50),(C,10)
//string(key) - list<pair<string,int>>(value) we cam keep these values inside the hashmap

class hashgraph{
    private:
        //Adj list using hashmap
        unordered_map<string,list<pair<string,int>>> l;
        
    public:
        void addEdge(string x,string y,bool bidir,int wt){
            l[x].push_back(make_pair(y,wt));
            if(bidir){
                l[y].push_back(make_pair(x,wt));
            }
        }

        void printAdjList(){
            //Iterate over all the keys in the map
            for(auto p:l){
                string city = p.first;
                list<pair<string,int>> nbrs = p.second;
                cout<<city<<"->";
                for(auto nbr:nbrs){
                    string destCity = nbr.first;
                    int destDist = nbr.second;
                    cout<<destCity<<","<<destDist<<" ";
                }
                cout<<endl;
            }
        }

        void bfs(string source)
        {
            map<string,bool> visited;
            queue<string> q;

            q.push(source);
            visited[source] = true;
            while (!q.empty())
            {
                string node = q.front();
                cout<<node<<" ";
                q.pop();
                for (auto nbr:l[node]){
                    if(!visited[nbr.first]){
                        q.push(nbr.first);
                        //mark that nbr as true
                        visited[nbr.first] = true;
                    }
                }
            }
        }

        //This is a recursive funtion that will traverse a graph
        void dfsHelper(string source,map<string,bool> &visitedNode){
            cout<<source<<" ";
            visitedNode[source]= true;
            //go to all the nbrs that is not visited
            for(auto nbr:l[source]){
                if(!visitedNode[nbr.first]){
                    dfsHelper(nbr.first,visitedNode);
                }
            }

        }

        void dfs(string source){
            map<string,bool> visitedNode;
            for(auto p:l){
                string node = p.first;
                visitedNode[node] = false;
            }
            dfsHelper(source,visitedNode);
        }
};


//To count disconnected components in the graph
/*
    component=0
    for(int source=0;source<=n;source++){
        if(!visited[source]){
            componeent++;
            dfs(source);
        }
    }
*/

//for disconnected graph
//for(source:Nodes) //run bfs on every node
//also add condition if not visited or if visited continue

// class genGraph{
//     map<T,list<T>>l;

//     public:
//         void addEdge(T x,T y){
//             l[x].push_back(Y);
//             l[y].push_back(x);
//         }

//         void bfs(T source){
//           map<T,bool> visited;
//             queue<T> q;

//             q.push(source);
//             visited[source] = true;
//             while (!q.empty())
//             {
//                 string node = q.front();
//                 cout<<node<<" ";
//                 q.pop();
//                 for (auto nbr:l[node]){
//                     if(!visited[nbr]){
//                         q.push(nbr);
//                         //mark that nbr as true
//                         visited[nbr] = true;
//                     }
//                 }
//             }  
//         }
// };


/*
    if given source and destination and a disconnected graph and check if source and destination have a path
    run bfs on a source once and after the bfs check id destination node is visited or not.
*/


//No if island or No of connected components in a grid
// Space complexity and time complexity will of O(n*n) roughly
class graphOnGrid{
    
    public:
        int cnt=0;

        //using bfs
        void bfsOnGrid(int row,int col,vector<vector<int>> &visited,vector<vector<char>> & grid){
            visited[row][col]=1;
            queue<pair<int,int>> q;
            q.push(make_pair(row,col));

            int n=grid.size();
            int m=grid[0].size();

            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                //traverse in the neighbors of row and col
                for(int dr=-1;dr<=1;dr++){
                    for(int dc=-1;dc<=1;dc++){
                        int nrow = row+dr;
                        int ncol = col+dc;

                        //validation of having land there
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                            visited[nrow][ncol] = 1;
                            q.push(make_pair(nrow,ncol));
                        }
                    }
                }
            }
        }

        //using dfs
        void dfsOnGrid(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
        {
            for (int dr = -1; dr <= 1; dr++)
            {
                for (int dc = -1; dc <= 1; dc++)
                {
                    int nrow = row + dr;
                    int ncol = col + dc;

                    // validation of having land there
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !visited[nrow][ncol])
                    {
                        visited[nrow][ncol] = 1;
                        dfsOnGrid(nrow, ncol, visited, grid);
                        cnt++;
                    }
                }
                //If we dont want diagonals to be considered then
                /*
                    dx[]={};
                    dy[]={};

                    for(int k=0;k<dx.size();k++){
                        int nrow = row + dx[k];
                        int ncol = col + dy[k];

                        // validation of having land there
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !visited[nrow][ncol])
                    {
                        visited[nrow][ncol] = 1;
                        dfsOnGrid(nrow, ncol, visited, grid);
                        cnt++;
                    }
                    }
                */
            }
        }

        int numOfIslands(vector<vector<char>> & grid){
            int n=grid.size();
            int m=grid[0].size();
            vector<vector<int>> visited(n,vector<int>(m,0));
            int count=0;

            for(int row=0;row<n;row++){
                for(int col=0;col<m;col++){
                    if(!visited[row][col] && grid[row][col] == '1'){
                        bfsOnGrid(row,col,visited,grid);
                        count++;
                    }
                }
            }
            return count;
        }
};

class rottonOranges{
    public:

    int OrangesRotting(vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        //{{r,c},time}
        queue<pair<pair<int,int>,int>> q;
        //vector<vector<int>> visited;
        int visited[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(make_pair(i,j),0));
                    visited[i][j]=2;
                }
                else{
                    visited[i][j]=0;
                }
            }
        }

        int tm=0;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while (!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nrow = r + dr[k];
                int ncol = c + dc[k];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2)
                {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow,ncol},t+1})
                }
            }
        }

        //Check if all the fresh oranges got rotten
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] != 2 && gid[i][j]==1){
                    return -1;
                }
            }
        }

        return tm;
        
    }
};


//Shortest unit distance between source to any node
class shortestDist{
    public:
        vector<int> dist;

        void shortDist(vector<vector<int>> &adj, int n,int m, int src){

            int dist[N];
            for(int i=0;i<N;i++) dist[i] = INT32_MAX;
            dist[src]=0;
            queue<int> q;
            q.push(src);

            while(!q.empty()){
                int node=q.front();
                
            }
        }
};

// Main function to test the Graph class
int main() {
    // int V = 5;
    // Graph g(V);

    // g.addEdge(0, 1);
    // g.addEdge(0, 4);
    // g.addEdge(1, 2);
    // g.addEdge(1, 3);
    // g.addEdge(1, 4);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);

    // g.printGraph();

    // hashgraph gh;
    // gh.addEdge("A","B",true,20);
    // gh.addEdge("B","D",true,40);
    // gh.addEdge("A","C",true,10);
    // gh.addEdge("C","D",true,40);
    // gh.addEdge("A","D",false,50);

    // gh.printAdjList();

    // gh.bfs("A");
    // cout<<endl;
    // gh.dfs("A");

    return 0;
}