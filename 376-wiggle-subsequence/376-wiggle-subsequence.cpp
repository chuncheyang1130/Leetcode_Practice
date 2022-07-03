class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        
        int len = 1;
        bool positive;
        for(int i = 1; i < nums.size(); i++){
            if(len == 1 && nums[i] - nums[i-1] == 0){
                continue;
            }else if(len == 1 && nums[i]-nums[i-1] != 0){
                positive = (nums[i] - nums[i-1] > 0);
                len++;
            }else if(positive && nums[i]-nums[i-1] < 0){
                positive = false;
                len++;
            }else if(!positive && nums[i]-nums[i-1] > 0){
                positive = true;
                len++;
            }
        }

        return len;
    }
};