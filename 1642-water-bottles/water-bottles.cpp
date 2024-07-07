class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int total = numBottles;
        int new_exchange = 0;

        while (numBottles / numExchange){
            new_exchange = numBottles / numExchange;
            total += new_exchange; 
            numBottles = numBottles % numExchange + new_exchange;
        }

        return total;
    }
};