class Solution {
public:
    
    bool canSortArray(vector<int>& nums) {
        vector<int> n_sb(nums.size(), 0);

        int base = 1;
        for (int i = 0; i <= 8; i++){
            for (int j = 0; j < nums.size(); j++){
                n_sb[j] += (nums[j] & base) >> i;
            }
            base *= 2;
        }

        for (int i = 0; i < nums.size()-1; i++){
            for (int j = 0; j < nums.size()-1-i; j++){
                if (nums[j] > nums[j+1] && n_sb[j] == n_sb[j+1])
                    swap(nums[j], nums[j+1]);
            }
        }

        for (int i = 0; i < nums.size()-1; i++){
            if (nums[i] > nums[i+1])
                return false;
        }
        return true;
    }
};