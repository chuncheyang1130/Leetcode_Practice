class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> value(days.back()+1, 0);
        
        for(int i = days.front(); i < value.size(); i++){
            if(*lower_bound(days.begin(), days.end(), i, less<int>()) == i){
                int od, sd, thd;
                od = value[i-1] + costs[0];
                sd = (i-7 >= 0) ? value[i-7] + costs[1] : costs[1];
                thd = (i-30 >= 0) ? value[i-30] + costs[2] : costs[2];
                value[i] = min({od, sd, thd});
            }else value[i] = value[i-1];
        }
        return value.back();
    }
};