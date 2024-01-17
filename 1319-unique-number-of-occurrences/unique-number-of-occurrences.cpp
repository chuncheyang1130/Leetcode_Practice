class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int occur[2001] = {0};
        unordered_map<int, int> cnt;

        for (int i = 0; i < arr.size(); i++){
            occur[arr[i]+1000]++;
        }

        for (int i = 0; i < 2001; i++){
            cnt[occur[i]]++;
        }

        for (int i = 1; i < 1000; i++){
            if (cnt[i] > 1)
                return false;
        }

        return true;
    }
};