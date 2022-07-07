class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_min = prices[0], M = 0;
        for(int i = 1; i < prices.size(); i++){
            M = max(prices[i]-cur_min, M);
            cur_min = min(cur_min, prices[i]);
        }
        return M;
    }
};