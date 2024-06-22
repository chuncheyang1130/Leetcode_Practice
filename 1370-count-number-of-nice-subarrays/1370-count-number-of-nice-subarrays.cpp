class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int count = 0;        
        // vector<int> odd;
        // odd.push_back(-1);

        int odd[50002] = {0};
        int idx = 0;
        int l = 0, r = k+1;

        odd[idx++] = -1;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] % 2){
                odd[idx++] = i;

                if (idx >= k+2){
                    count += (odd[l+1] - odd[l]) * (odd[r] - odd[r-1]);
                    l++;
                    r++;
                }

            }
                
        }

        odd[idx++] = nums.size();

        if (r < idx)
            count += (odd[l+1] - odd[l]) * (odd[r] - odd[r-1]);

        return count;
    }
};