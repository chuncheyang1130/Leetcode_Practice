class Solution {
public:
    int findParent(int target, vector<int>& parent){
        if (parent[target] == target)
            return target;
        int par = findParent(parent[target], parent);
        parent[target] = par;
        return par;
    }
    void dfs(int src, vector<vector<bool>>& connected, vector<bool>& visited){
        for (int dst = 0; dst < connected[src].size(); dst++){
            if (!visited[dst] && connected[src][dst]){
                visited[dst] = true;
                dfs(dst, connected, visited);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, 0);
        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;
        
        vector<int> v_cnt(n, 1);
        vector<int> e_cnt(n, 0);

        int v0, v1, p0, p1;
        for (int i = 0; i < edges.size(); i++){
            v0 = edges[i][0];
            v1 = edges[i][1];

            p0 = findParent(v0, parent);
            p1 = findParent(v1, parent);

            if (p0 < p1){
                parent[p1] = p0;
                v_cnt[p0] += v_cnt[p1];

                // if (e_cnt[p0] == -1)
                //     e_cnt[p0] = 0;
                // if (e_cnt[p1] == -1)
                //     e_cnt[p1] = 0;

                // cout << p0 << "/" << p1 << " " << e_cnt[p0] << "/" << e_cnt[p1] << endl;
                e_cnt[p0] += e_cnt[p1] + 1;
            }else if (p0 == p1){
                e_cnt[p0] += 1;
            }else if (p0 > p1){
                parent[p0] = p1;
                v_cnt[p1] += v_cnt[p0];

                // if (e_cnt[p0] == -1)
                //     e_cnt[p0] = 0;
                // if (e_cnt[p1] == -1)
                //     e_cnt[p1] = 0;
                
                // cout << p0 << "/" << p1 << " " << e_cnt[p0] << "/" << e_cnt[p1] << endl;
                e_cnt[p1] += e_cnt[p0] + 1;
            }
        }

        unordered_map<int, int> grp;
        for (int i = 0; i < n; i++){
            if (grp.find(findParent(i, parent)) == grp.end())
                grp[parent[i]] = 1;
        }

        int n_v, ans = 0;    
        for (auto it = grp.begin(); it != grp.end(); it++){
            n_v = v_cnt[it->first];
            if (e_cnt[it->first] == n_v * (n_v-1) / 2)
                ans++;
        }

        return ans;
    }
};