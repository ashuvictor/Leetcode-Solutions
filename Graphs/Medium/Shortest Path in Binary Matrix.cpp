

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

class Solution {
public:
    int dx[8]={1,-1,0,0,-1,1,1,-1};
    int dy[8]={0,0,1,-1,1,1,-1,-1};
   int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 or grid[n-1][n-1]==1)
            return -1;
     queue<pair<int,int>>q;
       q.push({0,0});
       int dist=0;
       while(!q.empty())
       {
           int sz=q.size();
           dist++;
           while(sz--){
               int x=q.front().first;int y=q.front().second;
               q.pop();
               if(x==n-1 and y==n-1)
                   return dist;
               for(int i=0;i<8;i++){
                   int nx=x+dx[i];
                   int ny=y+dy[i];
                   if(nx>=0 and nx<n and ny>=0 and ny<n and grid[nx][ny]==0)
                   {
                       q.push({nx,ny});
                       grid[nx][ny]=1;
                   }
               }
           }
       }
       return -1;
            
    }
};