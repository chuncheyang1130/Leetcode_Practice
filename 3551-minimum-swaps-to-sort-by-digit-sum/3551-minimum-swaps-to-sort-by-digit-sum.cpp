class Solution {
public:
    static bool cmp(int &n1, int &n2){
        int val1 = 0, val2 = 0;
        int rem1 = n1, rem2 = n2;

        while (rem1){
            val1 += rem1 % 10;
            rem1 /= 10;    
        }

        while (rem2){
            val2 += rem2 % 10;
            rem2 /= 10;
        }

        if (val1 > val2)
            return false;
        
        if (val1 == val2 && n1 > n2)
            return false;

        return true;
    }

    int minSwaps(vector<int>& nums) {
        int count = 0;
        map<int, int> mp;
        vector<int> orig_nums(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i;
        
        sort(nums.begin(), nums.end(), cmp);
        // for (int i = 0; i < nums.size(); i++)
        //     cout << nums[i] << " ";
        // cout << endl;

        for (int i = 0; i < nums.size(); i++){
            int orig_pos = mp[nums[i]];

            if (orig_pos != i){
                int swap_val = orig_nums[i];

                // cout << nums[i] << ": " << mp[nums[i]] << endl;
                // cout << swap_val << ": " << mp[swap_val] << endl;

                mp[swap_val] = orig_pos;
                orig_nums[orig_pos] = swap_val;

                mp[nums[i]] = i;
                orig_nums[i] = nums[i];

                count += 1;

                // cout << nums[i] << ": " << mp[nums[i]] << endl;
                // cout << swap_val << ": " << mp[swap_val] << endl;
                // cout << "=============" << endl;
            }
        }

        return count;
    }
};