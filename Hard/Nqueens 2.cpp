


The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.



class Solution {
public:
    bool isSafe(vector<vector<bool>>&board,int row,int col){
        for(int x=0;x<row;x++){
            for(int y=0;y<board.size();y++){
                if(board[x][y])
                {
                    if(y==col or abs(x-row)==abs(y-col))
                        return false;
                }
            }
        }
        return true;
    }
    int solve(vector<vector<bool>>&board,int row){
        if(row==board.size())
            return 1;
        int count=0;
        for(int i=0;i<board.size();i++){
            if(isSafe(board,row,i))
            {
                board[row][i]=true;
                count+=solve(board,row+1);
                board[row][i]=false;
            }
        }
        return count;
    }
    int totalNQueens(int n) {
        vector<vector<bool>>board(n,vector<bool>(n,false));
        return solve(board,0);
    }
};