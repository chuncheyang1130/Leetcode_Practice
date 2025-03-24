class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        vector<int> dist(n, 1e9);
        dist[s] = 0;
        
        int src, dst, wgt;
        int min_cost = 1e9;
        while (n--){
            for (int i = 0; i < edges.size(); i++){
                src = edges[i][0];
                dst = edges[i][1];
                wgt = edges[i][2];

                dist[dst] = min(dist[dst], dist[src] + wgt);
            }
        }

        for (int i = 0; i < marked.size(); i++)
            min_cost = min(min_cost, dist[marked[i]]);
        
        if (min_cost == 1e9)
            return -1;
        return min_cost;
    }
};