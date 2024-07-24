class Solution {
public:
    static bool cmp(pair<int,int>& p1, pair<int,int>& p2){
        if (p1.first < p2.first)
            return true;
        else return false;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums){
        vector<int> ans;
        vector<pair<int, int>> map_v;

        string val_str;
        int val, remain, map_val, base;

        for (int i = 0; i < nums.size(); i++){
            val_str = "";
            val = nums[i];
            while (val / 10){
                remain = val % 10;
                val_str.insert(val_str.begin(), '0'+remain);
                val /= 10;
            }

            val_str.insert(val_str.begin(), '0'+val);

            base = 1;
            val = 0;
            for (int j = val_str.size()-1; j >= 0; j--){
                map_val = mapping[val_str[j]-'0'];
                val += map_val * base;
                base *= 10;
            }

            // cout << val_str << " " << val << " " << nums[i] << endl;
            map_v.push_back(make_pair(val, nums[i]));
        }

        sort(map_v.begin(), map_v.end(), cmp);

        for (int i = 0; i < map_v.size(); i++)
            ans.push_back(map_v[i].second);

        return ans;       
    }
};