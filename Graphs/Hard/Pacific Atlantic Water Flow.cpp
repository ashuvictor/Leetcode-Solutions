


There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.






class Solution {
public:
    void dfs(vector<vector<int>>& mat,int i,int j,int prev,vector<vector<int>>& ocean){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()) return;
        if(mat[i][j]<prev || ocean[i][j])return;
        
        ocean[i][j]=true;
        
        dfs(mat,i+1,j,mat[i][j],ocean);
        dfs(mat,i,j+1,mat[i][j],ocean);
        dfs(mat,i-1,j,mat[i][j],ocean);
        dfs(mat,i,j-1,mat[i][j],ocean);
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> ans;
        if(mat.size()==0)return ans;
        
        int row=mat.size();
        int col=mat[0].size();
        
        vector<vector<int>> pacific(row,vector<int>(col,false));
        vector<vector<int>> atlantic(row,vector<int>(col,false));
        
        for(int i=0;i<col;i++){
            dfs(mat,0,i,INT_MIN,pacific);
            dfs(mat,row-1,i,INT_MIN,atlantic);
        }
        for(int i=0;i<row;i++){
            dfs(mat,i,0,INT_MIN,pacific);
            dfs(mat,i,col-1,INT_MIN,atlantic);
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};
