class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = (nums.size() + 1) / 2;

        int head = 0, tail = n-1;

        while(head != tail){
            int mid = (head + tail) / 2;
            int pos = mid * 2;

            if(pos != 0 && nums[pos] == nums[pos+1]){
                head = mid + 1;
            }else if(pos == 0 && nums[pos] != nums[pos+1]){
                return nums[pos];
            }else if(nums[pos] != nums[pos+1] && nums[pos] != nums[pos-1]){
                return nums[pos];
            }else if(nums[pos] == nums[pos+1]){
                head = mid + 1;
            }else if(nums[pos] != nums[pos+1]){
                tail = mid;
            }
        }
        return nums[head*2];
    }
};