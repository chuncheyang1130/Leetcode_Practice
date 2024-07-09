class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = 0;

        while (numBottles / numExchange){
            total += numExchange;
            numBottles = numBottles - numExchange + 1;
            numExchange++;
        }

        if (numBottles)
            total += numBottles;
            

        return total;
    }
};