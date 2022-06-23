


Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Time Complexity : O ( n * n )
Space Complexity : O ( 1 )

class Solution {
public:
    bool isAnagram(string s,string t)
    {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>idx;
        
        int n=s.size();
        int m=p.size();
        int i;
        for(i=0;i<=n-m;i++)
        {
            string temp=s.substr(i,m);
            if(isAnagram(temp,p))
                idx.push_back(i);
        }
        return idx;
        
    }
};



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size()>s.size())
            return ans;
        vector<int> a(26,0);
        vector<int> b(26,0);
        for(int i=0;i<p.size();i++)
        {
            a[p[i]-'a']++;
            b[s[i]-'a']++;
        }
        for(int i=p.size();i<s.size();i++)
        {
            if(a==b)
                ans.push_back(i-p.size());
            b[s[i-p.size()]-'a']--;
            b[s[i]-'a']++;
            
        }
        if(a==b)
           ans.push_back(s.size()-p.size());
        return ans;
    }
};i=