class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;

        vector<int> ref_vec(nums.end()-k, nums.end());
        nums.insert(nums.begin(), ref_vec.begin(), ref_vec.end());
        // for (int i = 0; i < nums.size(); i++){
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        nums.resize(len);
    }
};