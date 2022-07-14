class Solution {
public:
    queue<pair<int,int>>q;
    void dfs(int i,int j,int n,vector<vector<int>>&grid)
    {
        if(i<0 or i>=n or j<0 or j>=n or grid[i][j]==0 or grid[i][j]==-1)
            return;
        q.push({i,j});
        grid[i][j]=-1;
        dfs(i+1,j,n,grid);
         dfs(i,j-1,n,grid);
         dfs(i,j+1,n,grid);
         dfs(i-1,j,n,grid);
        
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();bool found=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {
                    dfs(i,j,n,grid);
                    found=true;break;
                }
            }
            if(found)
                break;
        }
        int ans=0;
        int dx[4]={0,-1,1,0};
        int dy[4]={1,0,0,-1};
        while(!q.empty())
        {int sz=q.size();
            while(sz--){
                int xx=q.front().first;
                int yy=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=xx+dx[i];
                    int ny=yy+dy[i];
                    if(nx<0 or nx==n or ny<0 or ny==n or grid[nx][ny]==-1 )
                    {
                        continue;
                    }
                    if(grid[nx][ny]==1)
                        return ans;
                    grid[nx][ny]=-1;
                    q.push({nx,ny});
                }
            }
            ans++;
        }
        return -1;
    }
};