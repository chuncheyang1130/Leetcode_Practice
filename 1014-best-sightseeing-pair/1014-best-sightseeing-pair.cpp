class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int front = values[0];
        int M = front + values[1] - 1;
        
        for(int i = 2; i < values.size(); i++){
            front = max(front, values[i-1]+i-1);
            M = max(front+values[i]-i, M);
        }
        return M;
    }
};