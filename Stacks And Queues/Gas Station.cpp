

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

 

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas=accumulate(gas.begin(),gas.end(),0);
        int sumCost=accumulate(cost.begin(),cost.end(),0);
        if(sumGas<sumCost)
            return -1;
        int ans=0;
        int remaining=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            remaining+=gas[i]-cost[i];
            if(remaining<0)
            {
                remaining=0;
                ans=i+1;
            }
        }
        return ans;
    }
};



Brute force - O(N*N)

class Solution {
public:
    bool checkforcycle(vector<int>& gas, vector<int>& cost,int start){
        int n=gas.size();
        int tank=0;
        if(gas[start]<cost[start]) return false;
        tank=gas[start]-cost[start];
        int i=start+1;
        for(i=start+1;(i%n)!=start;i++){
            if(tank+gas[i%n]<cost[i%n]) return false;
            else tank+=gas[i%n]-cost[i%n];
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++){
            if(checkforcycle(gas,cost,i)) return i;
        }
        return -1;
    }
};
Optimal - O(N)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totaldifference=0;
        for(int i=0;i<n;i++){
            totaldifference+=gas[i]-cost[i];
        }
        //if total fuel not sufficient for one round
        if(totaldifference<0) return -1;
        
        int currentdifference=0;
        int start=0;
        for(int i=0;i<n;i++){
            currentdifference+=gas[i]-cost[i];
            //if from point x to point y, fuel not sufficient, then from any 
            //point in (x,y) to point y wont be able to complete cycle
            //so choose next starting point as i+1 because from previous start
            //to i, any point in between wont be able to complete its full cycle 
            //where i is the point when fuel becomes neagtive.
            if(currentdifference<0){
                currentdifference=0;
                start=i+1;
            }
        }
        return start;
    }
};