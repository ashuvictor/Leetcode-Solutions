

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

CYCLE DETECTION IN A DIRECTED GRAPH
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int>adj[numCourses];
        queue<int>q;
        vector<int>indegree(numCourses,0);
        //store 
         for(int i =0; i< prerequisites.size(); i++ ){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //indegree u -> v
        for(int i =0; i < prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
            
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>result;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto x:adj[node])
            {
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
            result.push_back(node);
            
        }
        if(result.size()==numCourses)
            return true;
        return false;
    }
};