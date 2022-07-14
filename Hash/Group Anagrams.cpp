



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto i: strs){
            string temp = i;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(i);
        }
        
        vector<vector<string>> res;
        for(auto i: mp){
            res.push_back(i.second);
        }
        
        return res;
    }
};
Time Complexity: O(n * (m * log(m)))

where n is the total number of strings present in the vector and m is the maximum length of a string in the vector. Here, sorting the strings causes (m * log(m)) addition to the complexity.
Space Complexity: O(n * m)


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>>mpp;  
        for(string s : strs)
        {
            map<char,int>mpp2;
            for(char ch : s)
                mpp2[ch]++;
            mpp[mpp2].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto x : mpp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};