

Given two integers num and k, consider a set of positive integers with the following properties:

The units digit of each integer is k.
The sum of the integers is num.
Return the minimum possible size of such a set, or -1 if no such set exists.

Note:

The set can contain multiple instances of the same integer, and the sum of an empty set is considered 0.
The units digit of a number is the rightmost digit of the number.
Input: num = 58, k = 9
Output: 2
Explanation:
One valid set is [9,49], as the sum is 58 and each integer has a units digit of 9.
Another valid set is [19,39].
It can be shown that 2 is the minimum possible size of a valid set.


class Solution {
public:
    int solve(vector<int>&coins,int amount)
    {
         vector<int>dp(amount+1,INT_MAX-1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i)
                {
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        if(dp[amount]==INT_MAX-1)
            return -1;
        else
            return dp[amount];
    }
    int minimumNumbers(int num, int k) {
     vector<int>res;
        for(int i=0;i<=num;i++){
            if(i%10==k)
            {
                res.push_back(i);
            }
        }
        return solve(res,num);
        
    }
};