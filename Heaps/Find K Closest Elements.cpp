

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]




class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-1;
        
        while (right - left + 1 > k) {
            
            if (arr[right] - x < x - arr[left]) left++;
            else right--;
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
        
    }
};



class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<arr.size();i++)
        {
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int l=0, r=n-1;
        int ind=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]>x)
               r=mid-1;
            else{
                ind=mid;
                l=mid+1;
            }
        }
        cout<<ind;
        l=max(ind-k,0), r=min(ind+k,n-1);
        vector<int> ans;
        int c=0;
        while(r-l>=k){
            if(abs(arr[l]-x)<=abs(arr[r]-x)){
                r--;
            }
            else{
                l++;
            }
        }
        for(int i=l;i<=r;i++)
            ans.push_back(arr[i]);
        return ans;
    }
};
© 2022 GitHub, Inc.