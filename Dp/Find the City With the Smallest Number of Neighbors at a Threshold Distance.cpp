

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.


Dijkstra Algorithm
class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> hash;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(auto& a: edges){
            hash[a[0]].push_back({a[1], a[2]});
            hash[a[1]].push_back({a[0], a[2]});
        }
        int result = 1e9, ans = -1;
        for(int i = 0; i < n; i++){
            int found = dijkstra(i, n, distanceThreshold);
            if(found <= result)
                result = found, ans = i;
        }
        return ans;
    }
    int dijkstra(int& i, int& n, int& dt){
        vector<int> dist(n, INT_MAX);
        dist[i] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({0, i});
        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();
            for(auto& a: hash[node]){
                int b = cost + a.second;
                if(dist[a.first] > b){
                    dist[a.first] = b;
                    pq.push({b, a.first});
                }
            }
        }
        int count = 0;
        for(int j = 0; j < n; j++)
            count += dist[j] <= dt;
        return count;
    }
};
Floyd-Warshall Algorithm
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dist(n, vector<int>(n, 1e6));
        for(auto& a: edges)
            dist[a[0]][a[1]] = dist[a[1]][a[0]] = a[2];
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }
        int minC = 1e9, result = -1;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                count += dist[i][j] <= dt;
            }
            if(count <= minC)
                result = i, minC = count;
        }
        return result;
    }
};