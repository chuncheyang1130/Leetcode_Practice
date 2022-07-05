class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        int l = 0, r = nums.size()-1;
        int cur_jump = l;
        for(int i = 0; i < nums.size(); i++){
            cur_jump = max(cur_jump, i+nums[i]);
            if(i == l){
                if(l == cur_jump && l < r)
                    return false;
                else l = cur_jump;
            }
        }
        return true;
        
    }
};