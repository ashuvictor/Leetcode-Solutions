
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int res = 0;
        int cur_min = prices.back(), cur_max = prices.back();
        for (int i = prices.size() - 2; i >= 0; i--)
        {
            if (prices[i] > prices[i + 1])
            {
                res += (cur_max - cur_min);
                cur_min = cur_max = prices[i];
            }
            else if (prices[i] > cur_max)
                cur_max = prices[i];
            else
                cur_min = prices[i];
        }
        res += (cur_max - cur_min);
        return res;
    }
};

class Solution {
public:
    int solve(int ind,int buy,vector<int>&prices,int n,vector<vector<int>>&dp){
        if(ind==n)
            return 0;
        int profit=0;
         if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        if(buy)
        { 
            profit=max(-prices[ind]+solve(ind+1,0,prices,n,dp),0+solve(ind+1,1,prices,n,dp));
            
        }
        else{
            profit=max(prices[ind]+solve(ind+1,1,prices,n,dp),solve(ind+1,0,prices,n,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,prices,n,dp);
    }
};




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy)
                {
                    profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                }
                else
                {
                    profit=max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
                }
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};