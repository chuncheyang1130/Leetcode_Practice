class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int min_pos = 0;

        gas[0] -= cost[0];
        int min_diff = gas[0];
        for (int i = 1; i < gas.size(); i++){
            gas[i] += gas[i-1] - cost[i];
            if (gas[i] < min_diff){
                min_pos = i;
                min_diff = gas[i];
            }
        }

        if (gas.back() < 0)
            return -1;

        return (min_pos+1)%gas.size();

    }
};