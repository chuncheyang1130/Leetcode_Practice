class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int count = 0;        
        // vector<int> odd;
        // odd.push_back(-1);

        int odd[nums.size()+2];
        int idx = 0;
        odd[idx++] = -1;

        for (int i = 0; i < nums.size(); i++){
            // if (nums[i] % 2)
            //     odd.push_back(i);
            if (nums[i] % 2)
                odd[idx++] = i;
            
        }

        // odd.push_back(nums.size());
        odd[idx++] = nums.size();

        int l = 0;
        int r = k+1;

        while (r < idx){
            count += (odd[l+1] - odd[l]) * (odd[r] - odd[r-1]);
            r++;
            l++;
        }

        return count;
    }
};