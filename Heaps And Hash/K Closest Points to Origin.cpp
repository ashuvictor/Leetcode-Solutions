

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<points.size();i++){
            int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({dist,{points[i][0],points[i][1]}});
            if(pq.size()>k)
                pq.pop();
            
        }
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};


class Solution {
public:
    struct comp{
    bool operator()(vector<int> a, vector<int> b){
        return ((a[0] * a[0] + a[1] * a[1])>(b[0] * b[0] + b[1] * b[1])) ;
    }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        priority_queue<vector<int>,vector<vector<int>>, comp> pq;
        int n=points.size();
        
        for(int i=0;i<n;i++){
           pq.push(points[i]);
           
           
        }
         
        
        
        vector<vector<int>> t;
        
        for(int i=0;i<K;i++){
          t.push_back(pq.top());
          pq.pop();
            
        }
        return t;
    }
};