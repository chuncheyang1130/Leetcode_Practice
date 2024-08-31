class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;
        vector<vector<pair<int, double>>> adj(n, vector<pair<int, double>>());

        for (int i = 0; i < edges.size(); i++){
            int src = edges[i][0];
            int dst = edges[i][1];
            adj[src].push_back(make_pair(dst, succProb[i]));
            adj[dst].push_back(make_pair(src, succProb[i]));
        }

        priority_queue<pair<double, int>> pq;
        pq.push(make_pair(1.0, start_node));

        while (!pq.empty()){
            int src = pq.top().second;
            pq.pop();
            
            for (int i = 0; i < adj[src].size(); i++){
                int dst = adj[src][i].first;
                
                if (prob[src] * adj[src][i].second > prob[dst]){
                    prob[dst] = prob[src] * adj[src][i].second;
                    pq.push(make_pair(prob[dst], dst));
                }
            }
        }

        return prob[end_node];
    }
};