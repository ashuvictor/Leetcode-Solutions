https://leetcode.com/problems/n-queens/
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

class Solution {
public:
   bool isSafe(vector<string>&temp,int i,int j){
        for(int x=0;x<i;x++){
            for(int y=0;y<temp.size();y++){
                if(temp[x][y]=='Q'){
                    if(y==j or(abs(x-i)==abs(y-j))){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    void fun(int i,int n,vector<vector<string>>&ans,vector<string>&temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(temp,i,j)){
                temp[i][j]='Q';
                fun(i+1,n,ans,temp);
                temp[i][j]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        fun(0,n,ans,temp);
        return ans;
    }
};