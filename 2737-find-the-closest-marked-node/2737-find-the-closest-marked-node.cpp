class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        vector<int> dist(n, 1e9);
        vector<vector<pair<int,int>>> edge_matrix(n, vector<pair<int,int>>());
        
        unordered_map<int, int> hash_table;
        for (int i = 0; i < marked.size(); i++)
            hash_table[marked[i]] = 1;

        dist[s] = 0;
        
        int dst, wgt;

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

            if (hash_table.find(p.second) != hash_table.end())
                return p.first;

            for (int i = 0; i < edge_matrix[p.second].size(); i++){
                dst = edge_matrix[p.second][i].second;
                wgt = edge_matrix[p.second][i].first;

                if (!visited[dst])
                    pq.push(make_pair(p.first+wgt, dst));

            }
        }

        return -1;
    }
};