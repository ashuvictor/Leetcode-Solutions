class Solution {
public:
    void solve(vector<vector<int>>& graph,int src,vector<bool>&visited,vector<int>&path,vector<vector<int>>&ans)
    {
        visited[src]=true;
        if(src==graph.size()-1)
        {
            ans.push_back(path);
            return;
        }
        for(auto x:graph[src])
        {
            if(!visited[x])
            {  visited[x]=true;
             path.push_back(x);
             solve(graph,x,visited,path,ans);
             path.pop_back();
             visited[x]=false;
                
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>path;
        path.push_back(0);
        vector<bool>visited(graph.size(),false);
        solve(graph,0,visited,path,ans);
        return ans;
    }
};