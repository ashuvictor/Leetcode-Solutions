

https://leetcode.com/problems/distinct-subsequences/

Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag

class Solution {
public:
    vector<vector<int>>dp;
    int choices(string s,string t,int i,int j,int n,int m){
        if(j==m)
            return 1;
        if(i==n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
            return dp[i][j]=choices(s,t,i+1,j+1,n,m)+choices(s,t,i+1,j,n,m);
        else
            return dp[i][j]=choices(s,t,i+1,j,n,m);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.resize(n,vector<int>(m,-1));
        return choices(s,t,0,0,n,m);
    }
};



class Solution {
public:
    int numDistinct(string s, string t) {
        int n=t.size();
        int m=s.size();
       vector<vector<unsigned long long >>dp(n+1,vector<unsigned long long >(m+1,0));
        for(int j=0;j<=m;j++)
            dp[0][j]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t[i-1]==s[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                else
                    dp[i][j]=dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};