

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0;
        int maxs=INT_MIN;
        int mins=INT_MAX;
        int sum1=0,sum2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total+=nums[i];
            sum1+=nums[i];
            maxs=max(sum1,maxs);
            sum1=max(0,sum1);
            sum2+=nums[i];
            mins=min(sum2,mins);
            sum2=min(sum2,0);
            
        }
        return maxs<0?maxs:max(maxs,total-mins);
    }
};