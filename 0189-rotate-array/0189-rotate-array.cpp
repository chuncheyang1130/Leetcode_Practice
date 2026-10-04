class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> rotated(len);
        k %= len;

        for (int i = 0; i < nums.size(); i++)
            rotated[(i+k)%len] = nums[i];

        for (int i = 0; i < nums.size(); i++)
            nums[i] = rotated[i];


    }
};