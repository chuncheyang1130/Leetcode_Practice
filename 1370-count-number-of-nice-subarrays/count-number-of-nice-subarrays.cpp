class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int count = 0;        
        // vector<int> odd;
        // odd.push_back(-1);

        int idx = 0;
        int l = -1, r = k;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] % 2){
                nums[idx++] = i;

                if (idx >= k+1 && l == -1){
                    count += (nums[l+1] + 1) * (nums[r] - nums[r-1]);
                    l++;
                    r++;
                }else if (idx >= k+1){
                    count += (nums[l+1] - nums[l]) * (nums[r] - nums[r-1]);
                    l++;
                    r++;
                }

            }
                
        }

        if (r == k && l == -1 && r <= idx)
            count += (nums[l+1] + 1) * (nums.size() - nums[r-1]);
        else if (r <= idx && idx >= k+1)
            count += (nums[l+1] - nums[l]) * (nums.size() - nums[r-1]);

        return count;
    }
};