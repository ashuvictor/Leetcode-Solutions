You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, 
and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1.
rid is rectangular, width and height don't exceed 100
. Determine the perimeter of the island.

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int r, int c, int &perimeter)
    {
        // Mark as visited
        grid[i][j] = 2;
        
        // Calculate perimeter in all the 4 directions of the current cell
        if(i == 0 || grid[i-1][j] == 0)
            perimeter++;
        
        if(i == r || grid[i+1][j] == 0)
            perimeter++;
        
        if(j == 0 || grid[i][j-1] == 0)
            perimeter++;
        
        if(j == c || grid[i][j+1] == 0)
            perimeter++;
        
        // Check all the 4 directions
        // If land is found then recursively call dfs function
        if(i > 0 && grid[i-1][j] == 1)
            dfs(grid,i-1,j,r,c,perimeter);
        
        if(i < r && grid[i+1][j] == 1)
            dfs(grid,i+1,j,r,c,perimeter);
        
        if(j > 0 && grid[i][j-1] == 1)
            dfs(grid,i,j-1,r,c,perimeter);
        
        if(j < c && grid[i][j+1] == 1)
            dfs(grid,i,j+1,r,c,perimeter);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        // r = total rows
        // c = total columns
        int r = grid.size();
        int c = grid[0].size();
        
        // Create a variable to store perimeter
        int perimeter = 0;
        
        // Traverse the grid
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                // If land is found (i.e. grid[i][j] == 1)
                if(grid[i][j] == 1)
                {
                    dfs(grid,i,j,r-1,c-1,perimeter);
					break;
                }
            }
        }
        
        // Return the result
        return perimeter;
    }
};