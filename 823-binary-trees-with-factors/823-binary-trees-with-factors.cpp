class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int m = (int)1e9 + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> table;
        
        
        for(int i = 0; i < arr.size(); i++){
            table[arr[i]]++;
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] == 0){
                    int tmp = (long long)table[arr[j]] * table[arr[i]/arr[j]] % m;
                    table[arr[i]] = (int)((table[arr[i]] + tmp) % m);
                }
            }
        }
        
        int total = 0;
        for(auto it = table.begin(); it != table.end(); it++)
            total = (total + it->second) % m;
        return total;
    }
};