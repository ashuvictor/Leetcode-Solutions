


Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13



class Solution {
public:
    int countSmaller(vector<int>&row,int mid){
        int l=0;
        int h=row.size()-1;
        while(l<=h){
            int m=(l+h)>>1;
            if(row[m]<=mid){
                l=m+1;
            }
            else
            {
                h=m-1;
            }
        }
        return l;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        while(low<=high){
            int mid=(low+high)>>1;
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=countSmaller(matrix[i],mid);
            }
            if(cnt<k)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};