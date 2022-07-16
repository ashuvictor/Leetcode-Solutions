It is very clear that every node of the graph has two states :
i) It can be reached with last edge being red and,
ii) It can be reched with last edge being blue.

I have denoted red with 0 and blue with 1;

For the Initialization past it obvious that node 0 can be reached with last edge red and blue both, that why i have pushed {0,0} and {0,1} int the queue.

And the rest of the code is just bfs.

#define se second
#define fi first

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        
//         every node has 2 states 0->red and 1->blue
        bool vis[101][2];
        memset(vis,0,sizeof(vis));
        
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        
        vis[0][0]=vis[0][1]=1;
        
//         Separate adjacency list for red edges and blue edges
        vector<int> r[101],b[101];
        
        for(auto it:red)
        {
            r[it[0]].push_back(it[1]);
        }
        
        for(auto it:blue)
        {
            b[it[0]].push_back(it[1]);
        }
        
        int level=0;
        vector<int> ans(n,INT_MAX);
        
        while(!q.empty())
        {
            int sz=q.size();
            for(int jt=0;jt<sz;jt++)
            {
                pair<int,int> p=q.front();
                q.pop();
                int node=p.fi;
                int col=p.se;
                //here i am taking minimum of previous path length and current path length because the node can be reached with both red and blue last edges.
                ans[node]=min(level,ans[node]);
                
//                 so if the last edge color is red, i will check for the next edge in blue adjacency list.
                if(col==0)
                {
                    for(auto x:b[node])
                    {
                        if(!vis[x][1])
                        {
                            vis[x][1]=1;
                            q.push({x,1});
                        }
                    }
                }
//                 and if the last color is blue, i will check for red adjacency list.
                else
                {
                    for(auto x:r[node])
                    {
                        if(!vis[x][0])
                        {
                            vis[x][0]=1;
                            q.push({x,0});
                        }
                    }
                }
            }
            level++;
        }
        
//         at last if i am not able to reach any node, i will simply mark its path length as -1.
        for(int& i:ans)
        {
            if(i==INT_MAX)i=-1;
        }
        return ans;
        
        
    }
};