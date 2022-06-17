

Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

 

Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n==k)
            return true;
        if(n<k)
            return false;
         vector<int>cnt(26,0);
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;
        }
        int odd=0;
        for(int i=0;i<26;i++){
            if(cnt[i]%2)
                odd++;
        }
        //odd character in middle and even in end
        if(odd<=k)
            return true;
        return false;
        
        
        
        
    }
};