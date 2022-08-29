


You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.


T->O((3^m) * (3^m)) [Because both the robots will go through m cells and at each cell they will perform three stuffs either go left or down or right] && S->O(m/depth of the Recursion Tree) [Recursion Stack Space]

class Solution {
public:
	int f(int i,int j1,int j2, vector<vector<int>>& grid,int m,int n){
		if(j1<0 || j1>=n || j2<0 || j2>=n) return -1e9;
		if(i==m-1){
			if(j1==j2) return grid[i][j1];
			else return grid[i][j1] + grid[i][j2];
		}
//      Explore all the movements of both robots
		int maxi=INT_MIN;
		for(int dj1=-1;dj1<=+1;dj1++){
			for(int dj2=-1;dj2<=+1;dj2++){
				if(j1==j2) maxi=max(maxi,grid[i][j1]+f(i+1,j1+dj1,j2+dj2,grid,m,n));
				else maxi=max(maxi,grid[i][j1]+grid[i][j2]+f(i+1,j1+dj1,j2+dj2,grid,m,n));
			}
		}
		return maxi;
	}

	int cherryPickup(vector<vector<int>>& grid) {
		int m=grid.size();
		int n=grid[0].size();
		return f(0,0,n-1,grid,m,n);
	}
};

T->O(m * m * n) && S->O(m) + O(m * m * n )

class Solution {
public:
	int f(int i,int j1,int j2, vector<vector<int>>& grid,int m,int n,vector<vector<vector<int>>>& dp){
		if(j1<0 || j1>=n || j2<0 || j2>=n) return -1e9;
		if(i==m-1){
			if(j1==j2) return grid[i][j1];
			else return grid[i][j1] + grid[i][j2];
		}
		if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
//      Explore all the movements of both robots
		int maxi=INT_MIN;
		for(int dj1=-1;dj1<=+1;dj1++){
			for(int dj2=-1;dj2<=+1;dj2++){
				if(j1==j2) dp[i][j1][j2]=maxi=max(maxi, grid[i][j1] + f(i+1,j1+dj1,j2+dj2,grid,m,n,dp));
				else dp[i][j1][j2]=maxi=max(maxi, grid[i][j1] + grid[i][j2] + f(i+1,j1+dj1,j2+dj2,grid,m,n,dp));
			}
		}
		return maxi;
	}

	int cherryPickup(vector<vector<int>>& grid) {
		int m=grid.size();
		int n=grid[0].size();
		vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
		return f(0,0,n-1,grid,m,n,dp);
	}
};





class Solution {
public:
    int dp[80][80][80];
    int solve(vector<vector<int>>&grid,int c1,int c2,int r)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(r==n)
            return 0;
        if(dp[c1][c2][r]!=-1)
            return dp[c1][c2][r];
        int ans=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int x=c1+i;
                int y=c2+j;
                if(x>=0 and x<m and y>=0 and y<m){
                    ans=max(ans,solve(grid,x,y,r+1));
                }
            }
        }
        if(c1==c2)
            ans+=grid[r][c1];
        else
            ans+=grid[r][c1]+grid[r][c2];
        return dp[c1][c2][r]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
      return  solve(grid,0,m-1,0);
        
    }
};