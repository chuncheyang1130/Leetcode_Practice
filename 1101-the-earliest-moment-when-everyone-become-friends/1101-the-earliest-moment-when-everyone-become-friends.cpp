class Solution {
public:
    int findParent(vector<int>& parent, int src){
        if (parent[src] != src)
            parent[src] = findParent(parent, parent[src]);

        return parent[src];
    }

    static bool cmp(vector<int>& v1, vector<int>& v2){
        return v1[0] < v2[0];
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
        int timestamp = 0;

        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        sort(logs.begin(), logs.end(), cmp);

        int p1, p2;
        for (int i = 0; i < logs.size(); i++){
            p1 = findParent(parent, logs[i][1]);
            p2 = findParent(parent, logs[i][2]);
            
            if (p1 == p2)
                continue;
            else{
                if (p1 > p2)
                    parent[p1] = p2;
                else if (p1 < p2)
                    parent[p2] = p1;   

                timestamp = logs[i][0];
            }
        }

        for (int i = 1; i < n; i++){
            if (findParent(parent, i) != 0)
                return -1;
        }

        return timestamp;
    }
};