class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if (nums.size() == 1)
            return;

        int inc_pos = -1;

        short count[101] = {0};
        short sub_count[101] = {0};

        for (int i = 0; i < nums.size(); i++)
            count[nums[i]]++;

        for (int i = 0; i < nums.size()-1; i++){
            if (nums[i] < nums[i+1]){
                inc_pos = i;

                for (int j = 0; j <= 100; j++){
                    if (sub_count[j] > 0){
                        count[j] -= sub_count[j];
                        sub_count[j] = 0;
                    }
                }

                sub_count[nums[i]]++;
            }else {
                sub_count[nums[i]]++;
            }
        }

        short min_n = 0;

        if (inc_pos == -1){
            for (int i = 0; i < nums.size(); i++){
                for (int n = min_n; n <= 100; n++){
                    if (count[n] > 0){
                        nums[i] = n;
                        count[n]--;
                        min_n = n;
                        break;
                    }
                }                
            }
            return;
        }
        
        for (int n = nums[inc_pos]+1; n <= 100; n++){
            if (count[n] > 0){
                nums[inc_pos] = n;
                count[n]--;
                break;
            }
        }

        for (int pos = inc_pos+1; pos < nums.size(); pos++){
            for (int n = min_n; n <= 100; n++){
                if (count[n] > 0){
                    nums[pos] = n;
                    count[n]--;
                    min_n = n;
                    break;
                }
            }
        }
    }
};