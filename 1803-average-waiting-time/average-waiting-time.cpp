class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double avg_time = 0.0;
        int cur_time = customers[0][0];
        
        for (int i = 0; i < customers.size(); i++){
            if (cur_time < customers[i][0])
                cur_time = customers[i][0];
                
            cur_time += customers[i][1];
            avg_time += cur_time - customers[i][0];
        }

        avg_time /= customers.size();
        return avg_time;
    }
};