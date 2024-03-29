class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        
        for(int i = 0; i < nums.size(); i++)
            total += nums[i];
        
        if(total % 2)
            return false;
        
        vector<bool> table(total+1, false);
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = table.size()-1; j >= 1; j--)
                if(table[j])
                    table[j+nums[i]] = true;
            
            table[nums[i]] = true;
            if(table[total/2])
                return true;
        }
        
        return false;
    }
};