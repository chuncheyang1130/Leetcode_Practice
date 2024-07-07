class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int total = numBottles;

        while (numBottles / numExchange){
            total += numBottles / numExchange; 
            numBottles = numBottles % numExchange + numBottles / numExchange;
        }

        return total;
    }
};