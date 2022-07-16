

Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Time = O(n^2) | Auxiliary Space = O(n^2)

class Solution
{
    private:
        bool helper(int i, int j, string &s, vector<vector < int>> &dp, int &maxlen, int &start)
        {
            if (i > j) return true;
            if (dp[i][j] != -1) return dp[i][j];
            if (s[i] == s[j])
            {
                dp[i][j] = helper(i + 1, j - 1, s, dp, maxlen, start);
            }
            else
            {
                dp[i][j] = false;
            }
            if (dp[i][j] == 1)
            {
                if (maxlen < j - i + 1)
                {
                    maxlen = j - i + 1;
                    start = i;
                }
            }
            return dp[i][j];
        }
    public:
        string longestPalindrome(string s)
        {
            int n = s.size();
            int start = 0, maxlen = 1;
			
            vector<vector < int>> dp(n, vector<int> (n, -1));
            for (int i = 0; i < n; i++)
            {
                for (int j = i; j < n; j++)
                {
                    helper(i, j, s, dp, maxlen, start);
                }
            }
            return s.substr(start, maxlen);
        }
};
class Solution {
public:
    string longestPalindrome(string s) {
       int n=s.size();
        string ans;
        int maxLength=0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int diff=0;diff<n;diff++)
        {
            for(int i=0,j=i+diff;j<n;j++,i++)
            {
                if(i==j)
                    dp[i][j]=1;//first diag
                else if(diff==1)
                {
                    dp[i][j]=(s[i]==s[j])?2:0;
                    
                }
                else
                {
                    if(s[i]==s[j] and dp[i+1][j-1]!=0)
                    {
                        dp[i][j]=2+dp[i+1][j-1];
                    }
                }
                if(dp[i][j])
                {
                    if(j-i+1>maxLength)
                    {
                        maxLength=j-i+1;
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};




Here is an implementation of the Manacher's Algorithm which finds the longest palindromic string in O(n) time.

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        string s2 ="";
        vector<int> pradii(2 * n + 1);
        s2 += '*';
        for (int i = 0; i < n; i++)
        {
            s2 += s[i];
            s2 += '*';
        }
        int center = 0, radii = 0;
        int oldC, oldR;
        while (center < 2 * n + 1)
        {
            while (center - radii - 1 >= 0 && center + radii + 1 < 2 * n + 1 && s2[center - radii - 1] == s2[center + radii + 1])
                radii++;
            pradii[center] = radii;
            oldC = center;
            oldR = radii;
            center++;
            radii = 0;
            while (center <= oldC + oldR)
            {
                int maxR = oldC + oldR - center;
                int mc = oldC - (center - oldC);
                if (pradii[mc] < maxR)
                    pradii[center++] = pradii[mc];
                else if (pradii[mc] > maxR)
                    pradii[center++] = maxR;
                else
                {
                    radii = maxR;
                    break;
                }
            }
        }
        int max = 0, id = 0;
        for (int i = 0; i < 2 * n + 1; i++)
        {
            if (max < pradii[i])
            {
                max = pradii[i];
                id = i;
            }
        }
        id /= 2;
        return s.substr(id - max/2, max);
    }
};