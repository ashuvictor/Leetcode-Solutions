

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

example 
3 2 7 5 10 3
dp table of 3*Note
0 0 0 0 0  0
0 0 5 5 8 8
0 0 5 5 10 3



-3+0
-2+0
-7+5
in case we will get the profit also


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
     int n=prices.size();
        if(n==0)
            return 0;
        int profit[k+1][n];
        memset(profit,0,sizeof(profit));
        for(int i=1;i<=k;i++){
            int prev=INT_MIN;
            for(int j=1;j<n;j++){
                prev=max(prev,profit[i-1][j-1]-prices[j-1]);
                profit[i][j]=max(profit[i][j-1],prices[j]+prev);
            }
        }
        return profit[k][n-1];
    }
};