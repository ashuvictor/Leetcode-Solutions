class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
     int n=rooms.size();
        vector<bool>visited(n,false);
        visited[0]=true;
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int room=q.front();
            q.pop();
            for(auto x:rooms[room])
            {
                if(!visited[x])
                {
                    visited[x]=true;
                    q.push(x);
                }
            }
        }
        for(auto x:visited)
        {
            if(x==false)
                return false;
        }
        return true;
    }
};