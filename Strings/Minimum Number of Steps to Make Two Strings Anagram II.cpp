


You are given two strings s and t. In one step, you can append any character to either s or t.

Return the minimum number of steps to make s and t anagrams of each other.

An anagram of a string is a string that contains the same characters with a different (or the same) ordering.

 

Example 1:

Input: s = "leetcode", t = "coats"
Output: 7
Explanation: 
- In 2 steps, we can append the letters in "as" onto s = "leetcode", forming s = "leetcodeas".
- In 5 steps, we can append the letters in "leede" onto t = "coats", forming t = "coatsleede".
"leetcodeas" and "coatsleede" are now anagrams of each other.
We used a total of 2 + 5 = 7 steps.
It can be shown that there is no way to make them anagrams of each other with less than 7 steps.
Example 2:

Input: s = "night", t = "thing"
Output: 0
Explanation: The given strings are already anagrams of each other. Thus, we do not need any further steps.




class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> countLetterOfS, countLetterOfT;
        for(int i = 0; i < s.size(); i++){
            countLetterOfS[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            countLetterOfT[t[i]]++;
        }
        int step = 0;
        for(auto i: countLetterOfS){
            if(i.second > countLetterOfT[i.first]){
                step += (i.second - countLetterOfT[i.first]);
                countLetterOfT[i.first] = i.second;
            }
        }
        for(auto i: countLetterOfT){
            if(i.second > countLetterOfS[i.first]){
                step += (i.second - countLetterOfS[i.first]);
                countLetterOfS[i.first] = i.second;
            }
        }
        return step;
    }
};
class Solution {
public:
    int minSteps(string s, string t) {
        int result=0;
        vector<int>ans(26,0);
        for(int i=0;i<s.size();i++)
            ans[s[i]-'a']++;
        for(int i=0;i<t.size();i++)
            ans[t[i]-'a']--;
        for(int i=0;i<26;i++)
            result+=abs(ans[i]);
        return result;
    }
};