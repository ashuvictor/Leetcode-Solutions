
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/



You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.



class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,0));
        dp[0][0]=-(prices[0]+fee);
        for(int i=1;i<prices.size();i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-prices[i]-fee);
            dp[i][1]=max(dp[i-1][0]+prices[i],dp[i-1][1]);
        }
        return dp[prices.size()-1][1];
    }
};




class Solution {
public:
    //INTUITION: At any point of time let's keep 2 states: 
    //(i) If we buy current stock then what would be the net profit (in the future)
    //(ii) If we sell the current in hand stock what would be the net profit (till now)
    
    //At any time, we can either have a stock in hand(which we can sell) or we don't (so we can only buy a stock)
    int maxProfit(vector<int>& prices, int fee) {
        int profitWithStockInHand = INT_MIN, profitWithoutStockInHand = 0;
        for(auto p: prices)
        {
            int t = profitWithoutStockInHand;
            //(i) When we already have a stock in hand, we sell the already in hand stock
            //NOTE: Here we don't use transaction fee because profitWithStockInHand, that we use to update profitWithoutStockInHand, already has transaction fee deducted at every stock
            profitWithoutStockInHand = max(profitWithoutStockInHand, profitWithStockInHand + p );
            //(ii) When we don't have a stock in hand, we buy the current stock(with transaction fee)
            profitWithStockInHand = max(profitWithStockInHand, t - p - fee);
        }
        
        return profitWithoutStockInHand;
    }
};