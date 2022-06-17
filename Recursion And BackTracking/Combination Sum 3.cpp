

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.




class Solution {
public:
    void solve(int ind,int limit,int k,int target,vector<int>temp,vector<vector<int>>&ans){
        if(target==0 and k==0)
        {
            ans.push_back(temp);return;
        }
        else if(target<0)
        {
            return;
        }
        else
        {
            for(int i=ind;i<=limit;i++){
                temp.push_back(i);
                solve(i+1,limit,k-1,target-i,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        int index=1;int limit=9;
        solve(index,limit,k,n,temp,ans);
        return ans;
    }
};