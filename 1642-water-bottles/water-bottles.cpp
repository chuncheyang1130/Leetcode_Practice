class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int remain = numBottles;
        int total = numBottles;
        int new_exchange;

        while (remain / numExchange){
            new_exchange = remain / numExchange;
            total += new_exchange; 
            remain = remain % numExchange + new_exchange;
        }

        return total;
    }
};