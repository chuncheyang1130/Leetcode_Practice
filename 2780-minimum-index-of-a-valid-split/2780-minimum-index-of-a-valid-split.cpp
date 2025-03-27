class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        // Record number of each value
        map<int, int> accum;
        for (int i = 0; i < nums.size(); i++){
            if (accum.find(nums[i]) == accum.end())
                accum[nums[i]] = 1;
            else accum[nums[i]]++;
        }

        // Find the number appears the most time
        int target = nums[0];
        for (auto it = accum.begin(); it != accum.end(); it++){
            if (it->second > accum[target])
                target = it->first;
        }

        if (accum[target] < (nums.size()+1)/2 + 1)
            return -1;
        
        int cur_total = 0, idx = 0;
        for (idx = 0; idx < nums.size(); idx++){
            if (nums[idx] == target)
                cur_total++;
            if (cur_total > (idx+1)/2)
                break;
        }

        return idx;
    }
};