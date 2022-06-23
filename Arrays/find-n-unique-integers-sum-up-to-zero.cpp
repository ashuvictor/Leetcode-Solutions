
Given an integer n, return any array containing n unique integers such that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]


class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2==1)
            ans.push_back(0);
        for(int i=1;i<=n/2;i++)
            ans.push_back(i);
        for(int i=1;i<=n/2;i++)
            ans.push_back(-i);
        return ans;
    }
};