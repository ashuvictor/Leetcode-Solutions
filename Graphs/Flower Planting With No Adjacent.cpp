
You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.

All gardens have at most 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.

    Solution 1 :Greedy
    Since none of the nodes have more than 3 neighbors, we can select the 
    color not used by the neighbors.
    TC: O(3*N) ~ O(N)
    
  
*/
class Solution {
public:

	// Solution 1: Greedy
    // TC: O(N)
    // Graph coloring using greedy approach
    vector<int> colorGraph(vector<vector<int>> g) {
        // -1 indicates uncolored
        vector<int> color(g.size(), -1);
        for(int i = 0; i < g.size(); i++) {
            // To track the colors used by neigbors
            vector<bool> color_used(4, false);
            // mark all used colors
            for(const auto& v: g[i])
                if(color[v] != -1)
                    color_used[color[v]-1] = true;
            // look for the unused color
            for(int c = 0; c < 4; c++)
                if(color_used[c] == false) {
                    color[i] = c + 1;
                    break;
                }
                    
        }
        return color;
    }

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        map<int,vector<int>>graph;
        for(int i=0;i<n;i++){
            graph[paths[i][0]].push_back(paths[i][1]);
            graph[paths[i][1]].push_back(paths[i][0]);
            
        }
        vector<int>ans(n);
        for(int i=1;i<=n;i++){
            vector<int>color(5,0);
            for(auto a:graph[i])
            {
                color[ans[a-1]]=1;
            }
            for(int j=1;j<=4;j++){
                if(color[j]==0)
                {
                    ans[i-1]=j;
                }
            }
        }
   return ans; }
};
class Solution {
public:
    void dfs(int v, vector<int> &col, vector<int> adj[]){
        for(int i=1;i<=4;i++){
            bool f=false;
            for(auto x: adj[v]){
                if(col[x]==i){
                    f=true;
                    break;
                }
            }
            if(f==false){
                col[v]=i;
                break;
            }
        }
        for(auto x: adj[v])
            if(col[x]==-1)
               dfs(x, col, adj);
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        for(int i=0;i<paths.size();i++){
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> col(n+1, -1);
        for(int i=1;i<=n;i++){
            if(col[i]==-1){
                dfs(i, col, adj);
            }
        }
        col.erase(col.begin());
        return col;
    }
};