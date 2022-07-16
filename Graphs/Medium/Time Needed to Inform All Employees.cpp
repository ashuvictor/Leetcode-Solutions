A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.

Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.

 

Example 1:

Input: n = 1, headID = 0, manager = [-1], informTime = [0]
Output: 0
Explanation: The head of the company is the only employee in the company.




class Solution {
public:
    vector<vector<int>> children;
    int dfs(int node,vector<int>& informTime)
    {
        int time=0;
        for(int &n:children[node])
            time=max(time,dfs(n,informTime));		//Get the max time to reach the last child under the current node.
        return informTime[node]+time;				//Return the time required for this employee to inform + the time for it's children to inform all under them
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        children.resize(n);
        for(int i=0;i<manager.size();i++)				//Create Adjacency list
            if(manager[i]!=-1)
                children[manager[i]].push_back(i);
        return dfs(headID,informTime);
    }
};


class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int> >m;
        for(int i=0;i<manager.size();i++) {
            m[manager[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push(make_pair(headID,0));
        int maxi=0;
        while(!q.empty()) {
            int n=q.size();
            for(int i=0;i<n;i++) {
                int head=q.front().first;
                int timeTaken=q.front().second;
                q.pop();
                int dur=informTime[head]+timeTaken;
                maxi=max(maxi,dur);
                for(auto it:m[head]) {
                    q.push(make_pair(it,dur));
                }
            }
        }
        return maxi;
    }
};