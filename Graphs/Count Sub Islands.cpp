

You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

class Solution {
public:
    void dfs(vector<vector<int>>&grid1,vector<vector<int>>&grid2,int i,int j,int m ,int n,bool &flag){
        if(i<0 or i>=m or j<0 or j>=n or grid2[i][j]==0)
            return;
        if(grid1[i][j]==0)
        {
            flag=false;
        }
        grid2[i][j]=0;
        dfs(grid1,grid2,i+1,j,m,n,flag);
        dfs(grid1,grid2,i,j-1,m,n,flag);
        dfs(grid1,grid2,i,j+1,m,n,flag);
        dfs(grid1,grid2,i-1,j,m,n,flag);
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1)
                {  bool flag=true;
                    dfs(grid1,grid2,i,j,m,n,flag);
                 if(flag)
                     ans++;
                }
            }
        }
        return ans;
    }
};