class Solution {
public:
    void permute(vector<int>& nums, vector<bool>& used, vector<vector<int>>& ans, vector<int>& cur, int pos, int len){
        if(pos == len){
            ans.push_back(cur);
            return;
        }
        
        for(int i = 0; i < used.size(); i++){
            if(!used[i]){
                cur[pos] = nums[i];
                used[i] = true;
                permute(nums, used, ans, cur, pos+1, len);
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<vector<int>> ans;
        vector<int> cur(nums.size());
        
        permute(nums, used, ans, cur, 0, nums.size());
        return ans;
    }
};