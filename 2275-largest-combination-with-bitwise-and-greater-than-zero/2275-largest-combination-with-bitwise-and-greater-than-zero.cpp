class Solution {
public:
    int largestCombination(vector<int>& candidates) {

        int count[30] = {0};
        int val = 1;
        for (int b = 0; (1 << b) <= 1e7; b++){
            for (int i = 0; i < candidates.size(); i++){
                if (candidates[i] & val)
                    count[b]++;
            }

            val *= 2;
        }

        int max_n = count[0];
        for (int i = 1; i < 30; i++)
            max_n = max(max_n, count[i]);
        
        return max_n;
    }
};