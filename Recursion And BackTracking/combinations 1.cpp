




Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]




class Solution {
public:
  void solve(int n,int k,int index,vector<int>&temp,vector<vector<int>>&ans){
    if(k==0){
        ans.push_back(temp);
        return;
    }
    for(int i=index;i<=n;i++){
        temp.push_back(i);
        solve(n,k-1,i+1,temp,ans);
        temp.pop_back();//backtrack
    }
    
    
    
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>>ans;
    vector<int>temp;
    int index=1;
    solve(n,k,index,temp,ans);
    return ans;
}
};