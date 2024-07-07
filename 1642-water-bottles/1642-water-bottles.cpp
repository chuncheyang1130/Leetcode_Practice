class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int remain = numBottles;
        int total = numBottles;

        while (remain / numExchange){
            total += remain / numExchange; 
            remain = remain % numExchange + remain / numExchange;
        }

        return total;
    }
};