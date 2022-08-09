class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int m = (int)1e9 + 7;
        sort(arr.begin(), arr.end());
        map<int, int> table;
        int total = 0;
        
        for(int i = 0; i < arr.size(); i++){
            table[arr[i]]++;
            for(int j = 0; j < i && arr[j] <= sqrt(arr[i]); j++){
                if(arr[i] % arr[j] == 0){
                    int tmp = (long long)table[arr[j]] * table[arr[i]/arr[j]] % m;
                    table[arr[i]] = (int)((table[arr[i]] + tmp) % m);
                    if(arr[i] != arr[j] * arr[j])
                        table[arr[i]] = (int)((table[arr[i]] + tmp) % m);
                }
            }
            total = (total + table[arr[i]]) % m;
        }
        return total;
    }
};