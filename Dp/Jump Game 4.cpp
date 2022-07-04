Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        
        unordered_map<int, vector<int>> mp;
        
        int step = 0;
        
        //fill map
        for(int i = 0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        
        //queue
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            step++;
            int size = q.size();
            
            for(int i = 0; i<size; i++){
                int j = q.front();
                q.pop();
                
                //jump to j-1
                if(j-1 >= 0 && mp.find(arr[j-1]) != mp.end()){
                    q.push(j-1);
                }
                
                //jump to j+1
                if(j+1 < n && mp.find(arr[j+1]) != mp.end()){
                    if(j+1 == n-1) return step;
                    q.push(j+1);
                }
                
                // jump to equal
                if(mp.find(arr[j]) != mp.end()){
                    for(auto k: mp[arr[j]]){
                        if(k != j){
                            if(k == n-1) return step;
                            q.push(k);
                        }
                    }
                }
                mp.erase(arr[j]);
            }
        }
        return step;
    }
};