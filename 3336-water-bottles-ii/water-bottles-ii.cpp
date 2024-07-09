class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = 0;

        while (numBottles / numExchange){
            total += numExchange;
            numBottles -= (numExchange - 1);
            numExchange++;
        }

        return total + numBottles;
    }
};