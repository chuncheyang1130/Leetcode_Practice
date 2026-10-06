class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_diff = 0, min_val = prices[0];
        
        for (int i = 1; i < prices.size(); i++){
            max_diff = max(max_diff, prices[i]-min_val);
            min_val = min(min_val, prices[i]);
        }

        return max_diff;
    }
};