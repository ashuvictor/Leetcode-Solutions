Method 1 (Brute Force) 
If the length of string is n, then there can be n*(n+1)/2 possible substrings. A simple way is to generate all the substring and check each one whether it has exactly k unique characters or not. If we apply this brute force, it would take O(n2) to generate all substrings and O(n) to do a check on each one. Thus overall it would go O(n3).
We can further improve this solution by creating a hash table and while generating the substrings, check the number of unique characters using that hash table. Thus it would improve up to O(n2).

Method 2 (Linear Time) 
The problem can be solved in O(n). Idea is to maintain a window and add elements to the window till it contains less or equal k, update our result if required while doing so. If unique elements exceeds than required in window, start removing the elements from left side. 
Below are the implementations of above. The implementations assume that the input string alphabet contains only 26 characters (from ‘a’ to ‘z’). The code can be easily extended to 256 characters. 


class Solution{
  public:
    int longestKSubstr(string s, int k) 
    {
        int res = -1;
        unordered_map<char,int> map;
        int j = 0;
        for(int i = 0; i < s.size(); i++)
        {
            map[s[i]]++;
            if(map.size() == k)
            {
                res = max(res,(i-j)+1);
            }
            if(map.size() > k)
            {
                while(map.size() != k)
                {
                    map[s[j]]--;
                    if(map[s[j]] == 0){
                        map.erase(s[j]);
                    }
                    j++;
                }
            }
        }
        return res;
    }
};