class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int l = 0;
        int step = 0, max_jump = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > l){
                step += 1;
                l = max_jump;
                max_jump = max(max_jump, i+nums[i]);
                if(l >= nums.size()-1)
                    return step;
            }else
                max_jump = max(max_jump, i+nums[i]);
            
        }
        
        return step+1;
    }
};