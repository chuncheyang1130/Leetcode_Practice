class Solution {
public:
    int findParent(vector<int>& parent, int n){
        if (parent[n] == n)
            return n;
        else return findParent(parent, parent[n]);
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> parent(n, 0);
        vector<int> cost(n, INT_MAX);
        vector<int> min_cost(query.size(), 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (int i = 0; i < edges.size(); i++){
            int par_0 = findParent(parent, edges[i][0]);
            int par_1 = findParent(parent, edges[i][1]);

            if (par_0 < par_1){
                parent[par_1] = par_0;
                cost[par_0] = cost[par_0] & cost[par_1] & edges[i][2];
            }else if (par_0 == par_1){
                cost[par_0] = cost[par_0] & edges[i][2];
            }else if (par_0 > par_1){
                parent[par_0] = par_1;
                cost[par_1] = cost[par_1] & cost[par_0] & edges[i][2];
            }
        }

        for (int i = 0; i < query.size(); i++){
            int par_0 = findParent(parent, query[i][0]);
            int par_1 = findParent(parent, query[i][1]);

            if (par_0 != par_1)
                min_cost[i] = -1;
            else min_cost[i] = cost[par_0];
        }

        return min_cost;
    }
};