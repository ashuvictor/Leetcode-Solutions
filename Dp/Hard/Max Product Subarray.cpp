
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
int maxProduct(vector<int>& nums) {
        
        int p=1,max_p=0;
        int n = nums.size();
        if(n == 1) return nums[0];
        // Here we're movin forward in the array and finding max_product
        for(int i=0; i<n; i++)
        {
            p = p*nums[i];
            max_p = max(max_p,p);
            
            if(p == 0){
                p=1;
            }
        }
				
    //It's okay that we find max_product by moving forward in the Array,
    //but sometimes we won't get max_product like consider this TestCase:- {-8,5,6,3,1}
    //Here the max_product  is 90 which can be obatined by backward traversing (1*3*6*5 == 90). 
	//From forward traversing we get -720,  which is not the answer!.
	
	//This loop is for backward traversal of array & finding max_product
        p=1;
        for(int j=n-1; j>=0; j--)
        {
            p = p*nums[j];
            max_p = max(max_p,p);

             if(p == 0){
                p=1;
            }
        }
		
		// Pls consider Upvoting this explanation, if it was helpful
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp=nums[0];
        int minp=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)
                swap(maxp,minp);
            maxp=max(maxp*nums[i],nums[i]);
            minp=min(minp*nums[i],nums[i]);
            ans=max(ans,maxp);
        }
        return ans;
    }
};