
Given a 2D grid consists of 0s (land) and 1s (water). 
 An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.



class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j,int m,int n,bool &flag)
    {
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j]==2 or grid[i][j]==1)
            return;
        if(i==0 or i==m-1 or j==0 or j==n-1)
            flag=false;
        grid[i][j]=2;
        dfs(grid,i+1,j,m,n,flag);
        dfs(grid,i,j-1,m,n,flag);
        dfs(grid,i,j+1,m,n,flag);
        dfs(grid,i-1,j,m,n,flag);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                {
                    bool flag=true;
                    dfs(grid,i,j,m,n,flag);
                    if(flag)
                        ans++;
                }
            }
        }
        return ans;
    }
};