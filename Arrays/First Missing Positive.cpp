
Given an unsorted integer array nums, find the smallest missing positive integer.

Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]<=0 || nums[i]>n)
                i++;
            else{
                int v=nums[i]-1;
                if(nums[i]!=i+1 && nums[v]!=v+1)
                {
                    swap(nums[i], nums[v]);
                }
                else
                    i++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};