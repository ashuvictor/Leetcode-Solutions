



https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), val, prev;
        if (n == 1) return 0;

        vector<int> dp (n + 2, 0);
        dp[3] = max(0, prices[1] - prices[0]);
        
		// `i - 2` stands for the day in `prices`
        for (int i = 4; i < n + 2; i++) {
            val = 0;
			
			// if we sell on `i - 2`, then the lockdown must be before or equal to `i - 3`, 
			// so last sell on `j`, lockdown on `j + 1`, buy again on `j + 2`, which is also `i - 2`
            for (int j = 0; j < i - 2; j++) {
                val = max(val, prices[i - 2] - prices[j] + dp[j]);
            }
            dp[i] = max(dp[i - 1], val);
        }
        
        return dp.back();
    }
};
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