class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = 0, cur = 0;
        int stairNum = cost.size();
        for(int i = 2; i < stairNum; i++){
            swap(prev, cur);
            cur = min(prev+cost[i-1], cur+cost[i-2]);
        }
        
        return min(prev+cost[stairNum-2], cur+cost[stairNum-1]);
        
    }
};