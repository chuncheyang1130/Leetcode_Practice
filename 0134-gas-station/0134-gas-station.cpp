class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int sum = 0;
        int m = 1e9, ind = 0;

        for(int i = 0; i < n; i++){
            sum += gas[i] - cost[i];
            
            if(m > sum){
                m = sum;
                ind = i;
            }
        }
        
        if(sum < 0)
            return -1;
        else return (ind+1)%n;
    }
};