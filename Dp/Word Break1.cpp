

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

RECURSION, Time Limit Exceeded o(2^N)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(find(wordDict.begin(),wordDict.end(),s)!=wordDict.end())
            return true;
    
        for(int i=1;i<s.size();i++){
            string left = s.substr(0,i);
            if(find(wordDict.begin(),wordDict.end(),left)!=wordDict.end() && wordBreak(s.substr(i),wordDict)){
                return true;
            }
        }
        return false;
    }
    
};
MEMOIZATION, 22.76% of C++ online submissions

class Solution {
 map <string,bool> m;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(find(wordDict.begin(),wordDict.end(),s)!=wordDict.end())
            return true;
        if(m.find(s)!=m.end())
            return m[s];
        for(int i=1;i<s.size();i++){
            string left = s.substr(0,i);
                 cout<<left<<"#";
            if(find(wordDict.begin(),wordDict.end(),left)!=wordDict.end() && wordBreak(s.substr(i),wordDict)){
                  m[s]=true;
                return true;
            }
        }
   
        m[s]=false;
        return false;
    }
    
};
DP, 16 ms, faster than 54.11% of C++ online submissions

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<bool> dp(len+1,false);
        dp[0] = true;
        
        for(int i=1;i<=len;i++){
            for(int j=0;j<i;j++){
               if(dp[j] and find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                dp[i]=true;   
               }              
            }
        }
         return dp[len];
    }
};