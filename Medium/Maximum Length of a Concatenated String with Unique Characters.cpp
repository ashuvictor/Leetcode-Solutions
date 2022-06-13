https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

class Solution {
public:
     
    int ans = 0;
    
    int max(int a, int b)
    {
        return a > b? a: b;
    }
    
    // Function to check if there is any common char between the 2 strings
    bool intersect(string a, string b)
    {
        string temp = a + b;
        set<char> s;
        
        for(int i=0; i<temp.length(); i++)
        {
            if(s.find(temp[i]) != s.end()) return true;
            s.insert(temp[i]);
        }
        
        return false;
    }
    
    // Backtrack main function
    void helper(vector<string> &arr, string temp, int index)
    {
        if(index == arr.size()) return;
        
        for(int i=index; i<arr.size(); i++)
        {            
            if(intersect(temp, arr[i])) continue;
            int l = temp.length();
            
            temp += arr[i];
            ans = max(ans, temp.length());
            
            helper(arr, temp, i+1);
            
            temp = temp.substr(0, l);    // Backtrack
        }
    }
    
    int maxLength(vector<string>& arr) 
    {
        string temp = "";
        
        helper(arr, temp, 0);
        return ans;   
    }
};




We can simply do it with naive recursion , by generating all subsequences of the given vector of string s and then checking the valid ones from 2^n subsequences and finally returning the maximum length of a valid subsequence
But it can be optimized by using backtracking.

The backtracking condition here is to check if creating a particular subsequence will result in duplicate character in the string , if yes then its invalid and we dont choose it
If it is valid at the current point then we return the max value of both the availible choices

TO check whetther the current subsequence is valid or not we have plenty of options std::unordered_set,std::vector,std::set etc.

But bitset is by far the most optimized one
Thus as the string will always contain lowercase alphabets we just need to maintain a mask of 26 bits to check whether a character has appeared earlier and we are done

class Solution {
public:
    int solve(vector<string> &v,int low,bitset<26> bits=0,string s="")
    {
        if(low==v.size()) return s.size();  //base case
        bitset<26> b{bits};
        for(auto &i: v[low])
        {
            if(b[i-'a']==1)   // character is already in the string 
            {
                return solve(v,low+1,bits,s);  //backtracking step
            }
           else b[i-'a']=1;  //updating our mask
        }
        return max(solve(v,low+1,b,s+v[low]),solve(v,low+1,bits,s)); //if the string is valid and it didnt fall into backtracking step then we have to check both choices and return the max value we get
    }
    int maxLength(vector<string>& arr) {
       return solve(arr,0);
    }
};




class Solution {
    int maxLen = 0;
    void util(vector<string> &arr, int idx, int freq, int currLen) {
        int n = arr.size(), maxSize = 0;
        for(int i = idx; i < n; i++) {
            int currFreq = 0;
            for(char ch: arr[i]) {
                int currBit = (1 << (ch - 'a')); 
                // Duplicates
                if((currFreq & currBit) != 0) {
                    currFreq = -1;
                    break;
                }
                currFreq += currBit;
            }
            if(currFreq != -1 && (currFreq & freq) == 0) util(arr, i + 1, (currFreq | freq), currLen + arr[i].size());
        }
        maxLen = max(maxLen, currLen);
    }    
  public:
    int maxLength(vector<string> &arr) {
        util(arr, 0, 0, 0);
        return maxLen;
    }
};