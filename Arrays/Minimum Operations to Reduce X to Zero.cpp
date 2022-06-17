

You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Approach 1: Hash map, prefix sum, two sum
- Idea: + create hash map satisfy mapLeft[prefix sum] = i, i is last index in prefix sum
		+  brute force from last index in array to first index and create suffix sum, find i satisfy mapLeft[x - suffix sum] > 0 
		   => that's mean prefix sum + suffix sum = x,  and min operation = min (min operation, size(prefix sum) + size(suffix sum) );
+ Time: O(n)
+ Space: O(n)
		   
class Solution {
public:
	int minOperations(vector<int>& nums, int x) {
		unordered_map<int, int> mapLeft;
		int n = nums.size();
		int ans = INT_MAX;

		for(int i = 0, prefixSum = 0; i < n; i++) {
			prefixSum += nums[i];
			mapLeft[prefixSum] = i + 1;
			if (prefixSum == x)
				ans = min(ans, i + 1);
		}

		for(int i = n - 1, suffixSum = 0; i >= 0; i--) {
			suffixSum += nums[i];
			if(suffixSum == x)
				ans = min(ans, n - i);
			if(mapLeft[x - suffixSum] > 0 && i + 1 > mapLeft[x - suffixSum]) // if i + 1 <= mapLeft => both prefix sum and suffix sum have same elements
				ans = min(ans, n - i + mapLeft[x - suffixSum]); // n - i is size suffix sum, mapLeft[x - suffixSum] is size prefix sum
		}

		return ans == INT_MAX ? -1 : ans;
	}
};

Approach 2: longest subarray have sum == sum(nums) - x
- Idea: If u find longest subarray have sum == sum(nums) - x 
		=> minimun operation = nums.size() - size(longest subarray)

        + Time: O(n)
+ Space: O(1)

class Solution {
public:
	int minOperations(vector<int>& nums, int x) {
		int sum = accumulate(nums.begin(), nums.end(), 0);

		if(sum < x) return -1;
		if(sum == x) return nums.size();

		int target = sum - x, currentSum = 0, start = 0, maxSize = 0;
		for(int i = 0; i < nums.size(); i++) {
			currentSum += nums[i];

			while(currentSum > target)
				currentSum -= nums[start++];

			if(currentSum == target)
				maxSize = max(maxSize, i - start + 1);
		}

		return (maxSize == 0) ? - 1 : nums.size() - maxSize;
	}
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
     int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum<x)
            return -1;
        if(sum==x)
            return nums.size();
        int target=sum-x;
        int csum=0;
        int start=0;int end=0;int ans=0;
        while(end<nums.size()){
            csum+=nums[end];
            while(csum>target)
                csum-=nums[start++];
            if(csum==target)
                ans=max(ans,end-start+1);
            end++;
        }
        if(ans==0)
            return -1;
        return nums.size()-ans;
    }
};