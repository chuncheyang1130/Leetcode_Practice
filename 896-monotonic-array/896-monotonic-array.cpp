class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1)
            return true;

        int ind = 1;
        while(ind < nums.size() && nums[ind] == nums[ind-1])
            ind++;
        
        if(ind == nums.size())
            return true;
        
        bool inc = (nums[ind] - nums[ind-1] > 0);
        for(int i = ind+1; i < nums.size(); i++){
            if(inc && nums[i] - nums[i-1] < 0)
                return false;
            else if(!inc && nums[i] - nums[i-1] > 0)
                return false;
        }
        return true;
    }
};