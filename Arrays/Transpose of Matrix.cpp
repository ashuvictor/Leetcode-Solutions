

https://leetcode.com/problems/transpose-matrix/
Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
       int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                ans[j][i]=matrix[i][j];
        }
   return ans; }
};