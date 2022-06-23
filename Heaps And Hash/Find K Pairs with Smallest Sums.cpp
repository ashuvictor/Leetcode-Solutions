
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]


class Solution {
    struct comp{
        bool operator()(pair<int,int> p1, pair<int,int> p2){
            return p1.first+p1.second < p2.first+p2.second;
        }
      };
public:
   vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                pq.push({nums1[i], nums2[j]});
                if(pq.size()>k)
                    pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;
    }
};