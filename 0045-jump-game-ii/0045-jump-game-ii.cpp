class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;

        int prev_jump = 0, cur_jump = 0, n_jump = 0;

        for (int i = 0; i < nums.size(); i++){
            cur_jump = max(cur_jump, i+nums[i]);
            // cout << "cur_jump: " << cur_jump << endl;
            if (i == prev_jump){
                n_jump += 1;
                prev_jump = cur_jump;
                if (cur_jump >= nums.size()-1)
                    break;
            }
        }

        return n_jump;
    }
};