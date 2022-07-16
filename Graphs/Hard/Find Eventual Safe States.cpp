There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.





// https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    
    bool DFSRec(int s, vector<bool>&visited, vector<bool>&dfsVisited, vector<vector<int>>& graph, vector<bool> &present_cycle){
        visited[s] = true;
        dfsVisited[s] = true;
        
        vector<int>data = graph[s];
        for(auto x: data){
            if(!visited[x]){
                if(DFSRec(x, visited, dfsVisited, graph, present_cycle)){
                    return present_cycle[s] = true;
                }
            }
            else if(visited[x] && dfsVisited[x]){
                return present_cycle[s] = true;
            }
        }
        
        dfsVisited[s] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        
        int n = graph.size();
        vector<bool>visited(n, false), dfsVisited(n, false);
        vector<bool> present_cycle(n, false);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                DFSRec(i, visited, dfsVisited,graph, present_cycle);
            }
        }
        
        for(int i=0; i<n; i++){
            if(!present_cycle[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

















class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &color, int node)
    {
        if(color[node] == 1) return false;   // If a node is being visited & we visit again (i.e. cycle is detected), return false
        
        color[node] = 1;
        for(int neighbor: graph[node])
        {
            if(color[neighbor] == 2) continue;
            if(color[neighbor] == 1 or !dfs(graph, color, neighbor)) return false;  // If a neighbor is already visited or dfs of the neighbor return false (i.e. cycle is detected), we return false;
        }
        
        color[node] = 2;   // Otherwise, mark the node as safe & return true;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) 
    {
        vector<int> color(graph.size(), 0), result;
		
		for(int i=0; i<graph.size(); i++)
        {
            if(color[i] == 2 or dfs(graph, color, i)) // Add only if node is safe or dfs return true. DFS returns true, only when there is no cycle
                result.push_back(i);
        }
                
        return result;
    }
};