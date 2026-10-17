class Solution {
public:
    static bool cmp(pair<int,int> &p1, pair<int,int> &p2){
        if (p1.second > p2.second)
            return false;
        else if (p1.second == p2.second)
            return p1.first <= p2.first;

        return true;
    }

    int minSwaps(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> mp;
        vector<pair<int, int>> num_and_val(nums.size());

        for (int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;

            int rem = nums[i], val = 0;
            while (rem){
                val += rem % 10;
                rem /= 10;
            }

            num_and_val[i].first = nums[i];
            num_and_val[i].second = val;
        }
        
        sort(num_and_val.begin(), num_and_val.end(), cmp);
        // for (int i = 0; i < nums.size(); i++)
        //     cout << nums[i] << " ";
        // cout << endl;

        for (int i = 0; i < nums.size(); i++){
            int targ_num = num_and_val[i].first;
            int orig_targ_pos = mp[targ_num];

            if (orig_targ_pos != i){
                int swap_val = nums[i];

                // cout << nums[i] << ": " << mp[nums[i]] << endl;
                // cout << swap_val << ": " << mp[swap_val] << endl;

                mp[swap_val] = orig_targ_pos;
                nums[orig_targ_pos] = swap_val;

                mp[targ_num] = i;
                nums[i] = targ_num;

                count += 1;

                // cout << nums[i] << ": " << mp[nums[i]] << endl;
                // cout << swap_val << ": " << mp[swap_val] << endl;
                // cout << "=============" << endl;
            }
        }

        return count;
    }
};