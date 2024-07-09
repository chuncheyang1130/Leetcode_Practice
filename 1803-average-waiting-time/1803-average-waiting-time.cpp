class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double avg_time = customers[0][1];
        customers[0][0] += customers[0][1];
        
        for (int i = 1; i < customers.size(); i++){
            if (customers[i][0] > customers[i-1][0])
                customers[i-1][0] = customers[i][0];

            avg_time += customers[i-1][0] + customers[i][1] - customers[i][0];
            customers[i][0] = customers[i-1][0] + customers[i][1];
        }

        avg_time /= customers.size();
        return avg_time;
    }
};