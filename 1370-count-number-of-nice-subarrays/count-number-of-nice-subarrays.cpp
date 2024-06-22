class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int count = 0;        
        vector<int> odd;
        odd.push_back(-1);

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] % 2)
                odd.push_back(i);
        }

        odd.push_back(nums.size());

        int l = 0;
        int r = k+1;

        while (r < odd.size()){
            count += (odd[l+1] - odd[l]) * (odd[r] - odd[r-1]);
            r++;
            l++;
        }

        return count;
    }
};