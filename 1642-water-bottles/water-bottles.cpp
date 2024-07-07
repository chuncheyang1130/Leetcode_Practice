class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int remain = numBottles;
        int total = numBottles;

        while (remain / numExchange){
            int new_exchange = remain / numExchange;
            total += new_exchange; 
            remain = remain % numExchange + new_exchange;
        }

        return total;
    }
};