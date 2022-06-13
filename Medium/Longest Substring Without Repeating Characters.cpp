



Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(256,-1);
        int left=0,right=0;
        int n=s.size();
        int len=0;
        while(right<n){
            if(freq[s[right]]!=-1)
                left=max(freq[s[right]]+1,left);
                freq[s[right]]=right;
        len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};