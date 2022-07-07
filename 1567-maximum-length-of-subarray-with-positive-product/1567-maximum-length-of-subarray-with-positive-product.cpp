class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int M = 0, local_pos = 0, local_neg = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                swap(local_pos, local_neg);
                local_neg++;
                if(local_pos > 0)
                    local_pos++;
            }else if(nums[i] == 0){
                local_pos = 0;
                local_neg = 0;
            }else{
                local_pos++;
                if(local_neg > 0)
                    local_neg++;
            }
            
            M = max(M, local_pos);    
        }
        return M;
    }
};