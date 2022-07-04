class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> table;
        int prev = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > prev){
                table.push_back(pair<int,int>(nums[i], nums[i]));
                prev = nums[i];
            }else table.back().second += nums[i];
        }
        
        vector<int> cur_max(table.size());
        cur_max[0] = table[0].second;
        
        for(int i = 1; i < table.size(); i++){
            if(table[i-1].first == table[i].first-1 && i >= 2){
                cur_max[i] = max(cur_max[i-1], cur_max[i-2] + table[i].second);
            }else if(table[i-1].first == table[i].first-1 && i < 2){
                cur_max[i] = max(table[i-1].second, table[i].second);
            }else cur_max[i] = cur_max[i-1] + table[i].second;
        }
        return cur_max.back();
    }
};