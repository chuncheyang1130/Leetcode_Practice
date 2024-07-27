class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int INF = 1e9;
        vector<vector<int>> apsp(26, vector<int>(26, INF));

        for (int i = 0; i < original.size(); i++)
            apsp[original[i]-'a'][changed[i]-'a'] = min(apsp[original[i]-'a'][changed[i]-'a'], cost[i]);
        
        for (int i = 0; i < 26; i++)
            apsp[i][i] = 0;

        for (int k = 0; k < 26; k++){
            for (int i = 0; i < 26; i++){
                for (int j = 0; j < 26; j++){
                    if (apsp[i][j] > apsp[i][k] + apsp[k][j] && apsp[i][k] != INF && apsp[k][j] != INF)
                        apsp[i][j] = apsp[i][k] + apsp[k][j];
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.size(); i++){
            if (apsp[source[i]-'a'][target[i]-'a'] == INF)
                return -1;
            else ans += apsp[source[i]-'a'][target[i]-'a'];
        }

        return ans;
    }
};