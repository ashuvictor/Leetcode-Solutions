
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)>>1;
            if(nums[mid]==target)
            {
                ans[0]=mid;
                end=mid-1;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        if(ans[0]!=-1)
        {
            start=0;
            end=nums.size()-1;
            while(start<=end){
                int mid=(start+end)/2;
                if(nums[mid]==target)
                {
                    ans[1]=mid;
                    start=mid+1;
                }
                else if(nums[mid]<target)
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    
    int lowerbound(vector<int>& nums, int target){
       int l=0,h=nums.size()-1;
       while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]<target)
                l=mid+1;
            else
                h=mid-1; 
       }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int> ans(2);
        ans[0]=-1;
        ans[1]=-1;
       int l=lowerbound(nums, target);
       int r=lowerbound(nums, target+1)-1;
       if(l<nums.size() && nums[l]==target){
            return {l,r};
        }
        return ans;
    }
};