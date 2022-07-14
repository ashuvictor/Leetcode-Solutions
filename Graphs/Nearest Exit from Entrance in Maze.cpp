


You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

 




class Solution {
public:
     int v[4] = {1,0,0,-1};
    int v1[4]={0,-1,1,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
         int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>>pq;
        pq.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int ans=0;
        while(!pq.empty())
        {
            ans++;
            int sz=pq.size();
            while(sz--){
                int x=pq.front().first;
                int y=pq.front().second;;
                pq.pop();
                for(int i=0;i<4;i++){
                    int nx=x+v[i];
                    int ny=y+v1[i];
                    if(nx>=0 and nx<n and ny>=0 and ny<m and maze[nx][ny]=='.')
                    {
                        if(nx==0 or nx==n-1 or ny==0 or ny==m-1)
                            return ans;
                        maze[nx][ny]='+';
                        pq.push({nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};