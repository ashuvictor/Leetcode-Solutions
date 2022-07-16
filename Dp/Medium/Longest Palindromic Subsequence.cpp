

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int sz=s.size();
        int dp[sz+1][sz+1];
  for(int i=0;i<sz+1;i++)
         for(int j=0;j<sz+1;j++)
         {
            if(i==0||j==0)
                dp[i][j]=0;
          }
        for(int i=1;i<sz+1;i++)
        {
            for(int j=1;j<sz+1;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[sz][sz];
    }
};