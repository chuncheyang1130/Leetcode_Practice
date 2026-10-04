class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;

        vector<int> ref_vec(nums.end()-k, nums.end());
        nums.insert(nums.begin(), ref_vec.begin(), ref_vec.end());
        nums.resize(len);
    }
};