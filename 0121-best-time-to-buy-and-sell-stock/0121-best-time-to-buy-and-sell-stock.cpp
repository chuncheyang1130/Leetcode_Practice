class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_diff = 0;
        vector<int> min_vec(prices.size(), 0);
        min_vec[0] = prices[0];

        for (int i = 1; i < prices.size(); i++)
            min_vec[i] = min(min_vec[i-1], prices[i]);
        
        for (int i = 1; i < prices.size(); i++)
            max_diff = max(max_diff, prices[i]-min_vec[i-1]);

        return max_diff;
    }
};