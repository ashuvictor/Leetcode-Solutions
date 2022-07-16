
You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.




class Solution {
public:

    // Two times exploration of paths required
    // total number of paths we need to explore = [ all paths from "top left to bottom right corner" ] X [all paths from "bottom right to top left corner"]
    // step 1 - collect optimal numer of cherries while going down to `bottom right corner`.
    // step 2 - collect optimal numer of cherries while coming up to `top left corner`.
	
    void cp1(int row, int col, vector<vector<int>>&grid, int ccsf, int &maxcc){
        
        if(row<0 || row>=grid.size() || col<0 || col>= grid[0].size() || grid[row][col]==-1) return;
        if(row==grid.size()-1 && col==grid[0].size()-1) // bottom right corner
        {
            // it is used for exploring the all paths from bottom right to top left corner with respect/corresponding to
            // single path that is from top left to bottom right. 
			//(Basically cartesian product of paths from both directions i.e topLeftToBottomRight & BottomRightTotopLeft)
            bottomToTop(row, col, grid, ccsf, maxcc);
        }
        
        //collect this cherry
        int cherries = grid[row][col];
        grid[row][col]=0; // make this as collected i.e empty cell
        
        cp1(row, col+1, grid, ccsf+cherries, maxcc); // move in right direction
        cp1(row+1, col, grid, ccsf+cherries, maxcc); // move in vertically down 
        // backtracking starts
        grid[row][col]=cherries;
        
    }
    
    void bottomToTop(int row, int col, vector<vector<int>>&grid, int ccsf, int &maxcc){
        
        if(row<0 || row>=grid.size() || col<0 || col>= grid[0].size() || grid[row][col]==-1) return;
        if(row==0 && col==0) // Top Left corner
        {
           // finally one Complete path is covered
            maxcc = max(maxcc, ccsf);
            return;
        }
        
        //collect this cherry
        int cherries = grid[row][col];
        grid[row][col]=0; // make this as collected i.e empty cell
        
        bottomToTop(row, col-1, grid, ccsf+cherries, maxcc); // move in left direction
        bottomToTop(row-1, col, grid, ccsf+cherries, maxcc); // move in vertically up
        // backtracking starts
        grid[row][col]=cherries;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
         if(grid.size()==1 && grid[0][0]==1) return 1;
        int ccsf=0; // cherry collected so far
        int maxcc=0; // max cherry collected
        cp1(0,0,grid,ccsf,maxcc); // function cherry pickup-1
        return maxcc;
    }
 
};







Approach - 2 : ( Using Dynamic Programming - Top Down [Recursion + Memoization - 4D dp] )
Time complexity : O(n^4)
Space complexity : O(n^4)

Runtime: 180 ms, faster than 16.43% of C++ online submissions for Cherry Pickup.
Memory Usage: 38.6 MB, less than 15.87% of C++ online submissions for Cherry Pickup.
class Solution {
public:

    // MAIN LOGIC - Instead of coming back to (0,0), send 2 people from start to end
    // Recursion + memoization
    // Four dimension dp required because 4 variables are changing in recursive call.
    int dp[51][51][51][51]; // 4D - dp
    int cp(int r1, int c1, int r2, int c2, vector<vector<int>>&grid)
    {
        if(r1>=grid.size() || r2>=grid.size() || c1>=grid[0].size() || c2>=grid[0].size() || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return INT_MIN;
        }
        
        // if p1 and p2 reach the destination
        if(r1 == grid.size()-1 && c1 == grid[0].size()-1)
        {
            return grid[r1][c1];    
        }
        
        if(dp[r1][c1][r2][c2]!=0)
            return dp[r1][c1][r2][c2];
        
        int cherries = 0;
        if(r1==r2 && c1==c2){
            cherries += grid[r1][c1];
        }
        else {
            cherries += grid[r1][c1] + grid[r2][c2];
        }
        
        int f1 = cp(r1, c1+1, r2, c2+1, grid); // h, h
        int f2 = cp(r1+1, c1, r2, c2+1, grid); // v, h
        int f3 = cp(r1+1, c1, r2+1, c2, grid); // v, v
        int f4 = cp(r1, c1+1, r2+1, c2, grid); // h, v
        
        cherries += max({f1,f2,f3,f4});
        return dp[r1][c1][r2][c2] = cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        memset(dp,0,sizeof(dp));
        int ans = cp(0,0,0,0,grid);
        return (ans < 0) ? 0 : ans;
    }
  
};






Approach - 3 : ( Using Dynamic Programming - Top Down [Recursion + Memoization - 3D dp] )
Time complexity : O(n^4)
Space complexity : O(n^3)

Runtime: 40 ms, faster than 74.22% of C++ online submissions for Cherry Pickup.
Memory Usage: 9.5 MB, less than 90.93% of C++ online submissions for Cherry Pickup.
class Solution {
public:
  
    // Space optimized dp 
    // 3D-dp 
    // using Concept of manhatten distance
    // r1+c1 = r2+c2
    int dp[51][51][51]; 
    int cp(int r1, int c1, int r2, vector<vector<int>>&grid)
    {
        int c2 = r1+c1-r2;
        if(r1>=grid.size() || r2>=grid.size() || c1>=grid[0].size() || c2>=grid[0].size() || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return INT_MIN;
        }
        
        // if p1 and p2 reach the destination
        if(r1 == grid.size()-1 && c1 == grid[0].size()-1)
        {
            return grid[r1][c1];    
        }
        
        if(dp[r1][c1][r2]!=0)
            return dp[r1][c1][r2];
        
        int cherries = 0;
        if(r1==r2 && c1==c2){
            cherries += grid[r1][c1];
        }
        else {
            cherries += grid[r1][c1] + grid[r2][c2];
        }
        
        int f1 = cp(r1, c1+1, r2, grid); // h, h
        int f2 = cp(r1+1, c1, r2, grid); // v, h
        int f3 = cp(r1+1, c1, r2+1, grid); // v, v
        int f4 = cp(r1, c1+1, r2+1, grid); // h, v
        
        cherries += max({f1,f2,f3,f4});
        return dp[r1][c1][r2] = cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        memset(dp,0,sizeof(dp));
        int ans = cp(0,0,0,grid);
        return (ans < 0) ? 0 : ans;
    }
    
};