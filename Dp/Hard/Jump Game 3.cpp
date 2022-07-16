

Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 


class Solution {
public:
    void solve(vector<int>&arr,int index,bool &flag){
        if(index<0 or index>=arr.size())
            return;
        if(arr[index]==0)
        {
            flag=true;
            return;
        }
        solve(arr,index+arr[index],flag);
        solve(arr,index-arr[index],flag);
    }
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==0)
            return true;
        bool flag=false;
        solve(arr,start,flag);
        return flag;
    }
};
class Solution {
public:
    
    bool ff(vector<int>& arr, vector<bool>& visited, int i) {
        if (i < 0 || i >= arr.size() || visited[i]) return false;
        if (arr[i] == 0) return true;
        visited[i] = true;
        return ff(arr, visited, i + arr[i]) || ff(arr, visited, i - arr[i]);
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return ff(arr, visited, start);
    }
};