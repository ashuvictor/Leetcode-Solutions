

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int d=-1;
        for(int i=0;i<nums.size();i++){
            int curr=abs(nums[i]);
            if(nums[curr]<0){
                d=curr;
                break;
            }
            nums[curr]*=-1;
        }
        return d;
    }
}