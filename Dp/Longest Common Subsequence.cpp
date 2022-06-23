
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

    // Memoiazation
	 int f(int i,int j,string s,string t,vector<vector<int>>&dp)
 {
     // Base Case
     if(i<0 || j<0) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     if(s[i]==t[j]) return dp[i][j] = 1+f(i-1,j-1,s,t,dp);
    return dp[i][j] = max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
 }
    int longestCommonSubsequence(string s, string t) {
    int m = s.length(),n= t.length();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return f(m-1,n-1,s,t,dp);
     }
    
   **Method 2**
// Tabulation
//     int longestCommonSubsequence(string s, string t) {
//     int m = s.length(),n= t.length();
//     vector<vector<int>>dp(m+1,vector<int>(n+1,0));
//     // Base Case 
//    for(int i=0;i<=m;i++) dp[i][0] = 0;
//     for(int j=0;j<=n;j++) dp[0][j] = 0; 
        
//     for(int i=1;i<=m;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//           if(s[i-1]==t[j-1])  dp[i][j] = 1+dp[i-1][j-1]; 
//           else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);  
//         }
//     }
//     return dp[m][n];
//     }

Method 3:

 // Space Optimization
    int longestCommonSubsequence(string s, string t) {
    int m = s.length(),n= t.length();
    vector<int>prev(n+1,0),curr(n+1,0);
    // Base Case 
   for(int i=0;i<=n;i++) prev[i] = 0;//dp[i][0] = 0;
        
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
          if(s[i-1]==t[j-1])  curr[j] = 1+prev[j-1]; //dp[i][j] = 1+dp[i-1][j-1]; 
          else curr[j] = max(prev[j],curr[j-1]); //dp[i][j] = max(dp[i-1][j],dp[i][j-1]);  
        }
    prev = curr;
    }
    return prev[n];//dp[m][n];
    }