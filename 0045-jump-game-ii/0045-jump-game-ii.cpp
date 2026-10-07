class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> n_jump(nums.size(), 1e5);
        n_jump[0] = 0;
        
        for (int i = 0; i < nums.size(); i++){
            for (int j = 1; j <= nums[i] && i+j<nums.size(); j++)
                n_jump[i+j] = min(n_jump[i+j], n_jump[i]+1);
        }

        return n_jump.back();
    }
};