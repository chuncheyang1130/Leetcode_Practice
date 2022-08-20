class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int, vector<int>, less<int>> pq;
        
        int remain = startFuel;
        int prev = 0, fuel_time = 0;
        
        for(int i = 0; i < stations.size(); i++){
            remain -= stations[i][0] - prev;
            while(!pq.empty() && remain < 0){
                fuel_time++;
                remain += pq.top();
                pq.pop();
            }
            
            if(remain < 0)
                return -1;
            pq.push(stations[i][1]);
            prev = stations[i][0];
        }
        
        prev += remain;
        remain = 0;
        
        if(prev < target){
            while(!pq.empty()){
                prev += pq.top();
                pq.pop();
                fuel_time++;
                if(prev >= target)
                    return fuel_time;
            }
            return -1;
        }else return fuel_time;
    }
};