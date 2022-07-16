



https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 
#include<bits/stdc++.h>
int solve(int ind,int buy,vector<int>prices){
    if(ind>=prices.size())
        return 0;
    int profit=0;
    if(buy==1)
    {
        profit=max(-prices[ind]+solve(ind+1,0,prices),solve(ind+1,1,prices));
    }
    else
    {
        profit=max(prices[ind]+solve(ind+2,1,prices),solve(ind+1,0,prices));
    }
    return profit;
}
int stockProfit(vector<int> &prices){
    // Write your code here.
    return solve(0,1,prices);
}



#include<bits/stdc++.h>
int solve(int ind,int buy,vector<int>prices,vector<vector<int>>&dp){
    if(ind>=prices.size())
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    int profit=0;
    if(buy==1)
    {
        profit=max(-prices[ind]+solve(ind+1,0,prices,dp),solve(ind+1,1,prices,dp));
    }
    else
    {
        profit=max(prices[ind]+solve(ind+2,1,prices,dp),solve(ind+1,0,prices,dp));
    }
    return dp[ind][buy]=profit;
}
int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return solve(0,1,prices,dp);
}



int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
                if(buy==1)
    {
        profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
    }
    else
    {
        profit=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
    }
            dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}


Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int t[n+1];
        memset(t,0,sizeof(t));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=i;j++){
                t[i]=max(t[i-1], max(t[i],prices[i-1]-prices[j-1]));
                if(j-2>=0)
                   t[i]=max(t[i],t[j-2]+prices[i-1]-prices[j-1]); 
            }
        }
        return t[n];
    }
};
idea:
cost records the minimum cost would incur up to now;
profit1 records the maximum profit we can get up to previous day (for cooldown);
profit2 records the maximum profit up to now;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX;
        int profit1 = 0;
        int profit2 = 0;
        
        for (auto price: prices) {
            cost = min(cost, price - profit1);
            profit1 = profit2;
            profit2 = max(profit2, price - cost);
        }
        
        return profit2;
    }
};