class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin()+(nums.size()-1)/2, nums.end());
        int median = *(nums.begin()+(nums.size()-1)/2);
        int move = 0;
        for(int i = 0; i < nums.size(); i++){
            move += abs(nums[i] - median);
        }
        return move;
    }
};