
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

 

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
//wrong 
class Solution {
public:
    static bool comp(vector<int>x,vector<int>y){
        return x[2]<y[2];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),comp);
        int n=trips.size();
        int end=trips[0][2];
        int left=capacity-trips[0][0];
        for(int i=1;i<n;i++){
            if(trips[i][1]<end){
                if(left>=trips[i][0])
                {
                    left=capacity;end=trips[i][2];
                }
                else{
                    return false;
                }
            }
            else{
                left=capacity-trips[i][1];
                end=trips[i][2];
            }
        }
        return true;
    }   
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>mp;
        for(auto v:trips){
            int start=v[1];
            int end=v[2];
            mp[start]+=v[0];
            mp[end]-=v[0];
        }
        int sum=0;
        for(auto x:mp){
            sum+=x.second;
            if(sum>capacity)
                return false;
        }
        return true;
    }
};