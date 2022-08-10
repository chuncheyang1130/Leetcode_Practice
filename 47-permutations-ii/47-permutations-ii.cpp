class Solution {
public:
    void permute(vector<int>& nums, vector<bool>& used, vector<vector<int>>& ans, vector<int>& cur, int pos, int len){
        if(pos == len){
            ans.push_back(cur);
            return;
        }
        
        set<int> st;
        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i]) == st.end() && !used[i]){
                st.insert(nums[i]);
                used[i] = true;
                cur[pos] = nums[i];
                permute(nums, used, ans, cur, pos+1, len);
                used[i] = false;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        vector<int> cur(nums.size());
        
        permute(nums, used, ans, cur, 0, nums.size());
        return ans;
    }
};