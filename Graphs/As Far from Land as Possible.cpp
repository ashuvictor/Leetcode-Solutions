


Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.


class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        bool land=false;
        bool water=false;
        queue<pair<int,int>>q;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {
                    land=true;q.push({i,j});
                }
                else{
                    water =true;
                }
            }
        }
        if(land==false or water==false)
            return -1;
        int dx[4]={1,0,0,-1};
        int dy[4]={0,-1,1,0};
        int ans=0;int depth=0;
        while(!q.empty())
        {
            int sz=q.size();
            ans=max(ans,depth);
            depth++;
            while(sz--){
                int xx=q.front().first;
                int yy=q.front().second;q.pop();
                for(int i=0;i<4;i++){
                    int nx=xx+dx[i];
                    int ny=yy+dy[i];
                    if(nx>=0 and nx<n and ny>=0 and ny<n and grid[nx][ny]==0)
                    {
                        grid[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return ans;
    }
};