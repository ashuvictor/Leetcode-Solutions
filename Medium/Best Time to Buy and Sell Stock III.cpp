
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.


int solve(int ind,int buy,int cap,vector<int>&prices,int n,
         vector<vector<vector<int>>>&dp){
    if(ind==n)
        return 0;
    if(cap==0)
        return 0;
    if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];
    long profit=0;
    if(buy)
    {
        profit=max(-prices[ind]+solve(ind+1,0,cap,prices,n,dp),solve(ind+1,1,cap,prices,n,dp));
    }
    else{
        profit=max(prices[ind]+solve(ind+1,1,cap-1,prices,n,dp),solve(ind+1,0,cap,prices,n,dp));
    }
    return dp[ind][buy][cap]=profit;
}
int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return solve(0,1,2,prices,n,dp);
}
int maxProfit(vector<int>& prices, int n)
{
    // Write your code here.
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                int profit=0;
                  
    if(buy)
    {
        profit=max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
    }
    else{
        profit=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
    }
     dp[ind][buy][cap]=profit;
            }
        }
    }
    return dp[0][1][2];
}



class Solution {
public:
int maxProfit(vector<int>& prices) {
        int n=prices.size();
    int b1;
    int b2;
    b1=INT_MAX;
    b2=INT_MAX;
    
    int s1=0,s2=0;
    for(int i=0;i<n;i++){
        b1=min(b1,prices[i]);
        s1=max(s1,prices[i]-b1);
        b2=min(prices[i]-s1,b2);
        s2=max(s2,prices[i]-b2);
    }
    return s2;
        }
};