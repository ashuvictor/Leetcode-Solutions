
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.



class Solution {
public:
    void dfs(int s,vector<vector<int>>& adj,vector<bool>&visited)
    {visited[s]=true;
        for(int i=0;i<adj[s].size();i++){
            if(visited[i]==false and adj[s][i]!=0)
                dfs(i,adj,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i])
            {
                ans++;
                dfs(i,isConnected,visited);
            }
        }
        return ans;
    }
};