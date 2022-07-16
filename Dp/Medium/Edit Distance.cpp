

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

class Solution {
public:
    int dp[502][502];
    int solve(string word1, string word2,int m,int n){
        if(m==-1)
            return n+1;
        if(n==-1)
            return m+1;
        if(word1[m]==word2[n])
            return dp[m][n]=solve(word1,word2,m-1,n-1);
        int a=solve(word1,word2,m-1,n-1);
        int b=solve(word1,word2,m-1,n);
        int c=solve(word1,word2,m,n-1);
       return dp[m][n]=min(a,min(b,c))+1;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int m=word1.size();
        int n=word2.size();
        return solve(word1,word2,m-1,n-1);
    }
};



class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                }
                    
            }
        }
        return dp[m][n];
    }
};