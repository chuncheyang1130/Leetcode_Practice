class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> front(values.size());
        front[0] = values[0];
        int M = front[0] + values[1] - 1;
        
        for(int i = 2; i < values.size(); i++){
            front[i-1] = max(front[i-2], values[i-1]+i-1);
            M = max(front[i-1]+values[i]-i, M);
        }
        return M;
    }
};