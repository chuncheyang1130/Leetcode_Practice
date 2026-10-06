class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)
            return 0;

        int max_profit = 0;
        int min_val = prices[0];

        for (int i = 1; i < prices.size()-1; i++){
            if (prices[i] < prices[i-1])
                min_val = prices[i];
            else if (prices[i] >= prices[i-1] && prices[i] > prices[i+1])
                max_profit += prices[i] - min_val;
        }

        if (prices[prices.size()-1] >= prices[prices.size()-2])
            max_profit += prices.back() - min_val;

        return max_profit;
    }
};