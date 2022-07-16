


There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

 
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>adj[100005];
        int n=edges.size();
        for(int i=0;i<edges.size();i++)
        {  int u=edges[i][0];
           int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=100000;i++){
            if(adj[i].size()==n)
                return i;
        }
        return -1;
    }
};



/* since we need to find the node that is connected to every node so it will be common. so just check with first 2 edges. eg: [[1,2],[4,2],[2,3]]
so 2 is present in all the edges. check if 1==2 no then 1==4 no then just return 2 because there is one element that is common in every node.]] */

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
     
        if(edges[0][0]==edges[1][0])
        {
            return edges[0][0];
        }
        else if(edges[0][0]==edges[1][1])
        {
            return edges[0][0];
        }
        return edges[0][1];
    }
};