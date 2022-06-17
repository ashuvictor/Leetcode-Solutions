
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/


Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.




class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v(nums.begin(),nums.end());
        sort(v.begin(),v.end());
        int start=0;
        int end=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=v[i])
            {
                start=i;break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]!=v[i])
            {
                end=i;break;
            }
        }
        if(start!=end)
            return end-start+1;
        return 0;
    }
};