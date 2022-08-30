
_Potter_'s avatar
_Potter_

94
June 24, 2022 8:56 PM

276 VIEWS

class Solution {
public:
	
	// custom comparator for heap
    struct compare{
        bool operator()(vector<int> &a, vector<int> &b){
            return a[0]+a[1] < b[0]+b[1];
        }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		// Max heap
        priority_queue<vector<int>, vector<vector<int>>, compare> heap;
        
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
				// Push if there aren't enough elements in heap
                if(heap.size() < k){
                    heap.push({nums1[i], nums2[j]});
                }
				// Update if there's new minimum
                else if(heap.top()[0] + heap.top()[1] > nums1[i]+nums2[j]){
                    heap.pop();
                    heap.push({nums1[i], nums2[j]});
                }
                // Very very important because there's no need to check if sum > top of heap
                // Because on traversing right the sum only increases
                else{
                    break;
                }
            }
        }
		
        vector<vector<int>> ans;
        while(!heap.empty()){
            ans.push_back(heap.top());
            heap.pop();
        }
        return ans;
    }
};