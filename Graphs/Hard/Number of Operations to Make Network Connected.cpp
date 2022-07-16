There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.


class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj, int i,vector<bool>&visited)
    {
        visited[i]=true;
        for(auto curr:adj[i])
        {
            if(!visited[curr])
            {
                dfs(adj,curr,visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>adj;int edges=0;
        //make adjacency list
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges++;
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(!visited[i])
            {
                dfs(adj,i,visited);components++;
            }
        }
        if(edges<n-1) // if no of edges are less than that in mst
            return -1;
        int redundant=edges-((n-1)-(components-1));
        if(redundant>=(components-1))
            return components-1;
        return -1;
    }
};