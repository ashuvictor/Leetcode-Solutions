
You are given a 0-indexed m x n integer matrix grid consisting of distinct integers from 0 to m * n - 1. You can move in this matrix from a cell to any other cell in the next row. That is, if you are in cell (x, y) such that x < m - 1, you can move to any of the cells (x + 1, 0), (x + 1, 1), ..., (x + 1, n - 1). Note that it is not possible to move from cells in the last row.

Each possible move has a cost given by a 0-indexed 2D array moveCost of size (m * n) x n, where moveCost[i][j] is the cost of moving from a cell with value i to a cell in column j of the next row. The cost of moving from cells in the last row of grid can be ignored.

The cost of a path in grid is the sum of all values of cells visited plus the sum of costs of all the moves made. Return the minimum cost of a path that starts from any cell in the first row and ends at any cell in the last row.
Input: grid = [[5,3],[4,0],[2,1]], moveCost = [[9,8],[1,5],[10,12],[18,6],[2,4],[14,3]]
Output: 17
Explanation: The path with the minimum possible cost is the path 5 -> 0 -> 1.
- The sum of the values of cells visited is 5 + 0 + 1 = 6.
- The cost of moving from 5 to 0 is 3.
- The cost of moving from 0 to 1 is 8.
So the total cost of the path is 6 + 3 + 8 = 17.
Example 2:

Input: grid = [[5,1,2],[4,0,3]], moveCost = [[12,10,15],[20,23,8],[21,7,1],[8,1,13],[9,10,25],[5,3,2]]
Output: 6
Explanation: The path with the minimum possible cost is the path 2 -> 3.
- The sum of the values of cells visited is 2 + 3 = 5.
- The cost of moving from 2 to 3 is 1.
So the total cost of this path is 5 + 1 = 6.
class Solution {
public:
int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
int m = grid.size();
int n = grid[0].size();
int mn = INT_MAX;
vector<vector<int>> dp(m,vector(n,-1));
for(int i = 0 ; i < n ; i++){
mn = min(mn ,mi(grid,moveCost,0,i,m,n,dp));
}
return mn;
}
int mi(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int m , int n,int r , int c,vector<vector<int>>& dp) {
if(r-1 == m){
return grid[m][n];
}
if( n< 0 || n>c-1)return 1e6;
if(dp[m][n]!=-1) return dp[m][n];
int mn = 1e6;
for(int i = 0 ; i < c ; i++){
int k =mi(grid,moveCost,m+1,i,r,c,dp) +moveCost[grid[m][n]][i] +grid[m][n];

        mn=min(mn , k);//cout<<i<<mn<<k<<endl;
    }
    
    return dp[m][n] = mn;
}
};


int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
  int m=grid.size(),n=grid[0].size();
  int cost[m][n];
  for(int i=0;i<n;i++)
      cost[0][i]=grid[0][i];
  for(int i=1;i<m;i++)
    {
   for(int j=0;j<n;j++)
   {  int temp=INT_MAX;
       for(int k=0;k<n;k++)
       {
           temp=min(temp,cost[i-1][k]+moveCost[grid[i-1][k]][j]);
       }
    cost[i][j]=grid[i][j]+temp;
   }
}
int ans=INT_MAX;
for(int i=0;i<n;i++)
{
ans=min(ans,cost[m-1][i]);
}
return ans;
}
};
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        const int inf = 1e7;
        int rows = grid.size();
        int cols = grid[0].size();
        int i, j, k;
        
        vector<int> dp(cols);
        vector<int> temp(cols, inf);
        
        for(i = 0; i < cols; i++){
            dp[i] = grid[0][i];
        }
        
        for(i = 1; i < rows; i++){
            for(j = 0; j < cols; j++){
                for(k = 0; k < cols; k++){
                    temp[j] = min(temp[j], dp[k] + moveCost[grid[i - 1][k]][j] + grid[i][j]);
                }
            }
            
            for(j = 0; j < cols; j++){
                dp[j] = temp[j];
                temp[j] = inf;
            }
        }
        
        int minCost = inf;
        for(i = 0; i < cols; i++){
            minCost = min(minCost, dp[i]);
        }
        return minCost;
    }
};