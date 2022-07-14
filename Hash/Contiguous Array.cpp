


Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len=0;
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]==0)?-1:1;
            if(mp.find(sum)!=mp.end())
            {
                len=max(len,i-mp[sum]);
            }
            else
                mp[sum]=i;
        }
        return len;
    }
};