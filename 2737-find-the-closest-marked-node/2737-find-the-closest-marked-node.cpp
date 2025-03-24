class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        vector<int> dist(n, 1e9);
        vector<vector<pair<int,int>>> edge_matrix(n, vector<pair<int,int>>());
        dist[s] = 0;
        
        int src, dst, wgt;
        int min_cost = 1e9;

        for (int i = 0; i < edges.size(); i++)
            edge_matrix[edges[i][0]].push_back(make_pair(edges[i][2], edges[i][1]));

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> visited(n, false);
        pq.push(make_pair(dist[s], s));
        
        while (!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();

            if (visited[p.second])
                continue;
            
            visited[p.second] = true;
            dist[p.second] = p.first;

            for (int i = 0; i < edge_matrix[p.second].size(); i++){
                int dst = edge_matrix[p.second][i].second;
                int wgt = edge_matrix[p.second][i].first;

                if (!visited[dst])
                    pq.push(make_pair(p.first+wgt, dst));

            }
        }

        for (int i = 0; i < marked.size(); i++)
            min_cost = min(min_cost, dist[marked[i]]);
        
        if (min_cost == 1e9)
            return -1;
        return min_cost;
    }
};