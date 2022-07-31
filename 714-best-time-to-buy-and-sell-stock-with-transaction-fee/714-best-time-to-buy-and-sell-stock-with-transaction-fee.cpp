class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 1)
            return 0;
        vector<int> buy(prices.size()), sell(prices.size());
        buy[0] = -prices[0];
        buy[1] = max(-prices[0], -prices[1]);
        sell[0] = 0;
        sell[1] = max(0, buy[0]+prices[1]-fee);
        
        for(int i = 2; i < prices.size(); i++){
            buy[i] = max(buy[i-1], sell[i-1]-prices[i]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]-fee);
        }
        
        return sell.back();
    }
};