class Solution {
public:
    static bool cmp(pair<int, int>& p1, pair<int,int>& p2){
        if (p1.second < p2.second)
            return true;
        else if (p1.second == p2.second)
            return p1.first >= p2.first;
        else return false;
    }

    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> num_cnt;
        unordered_map<int, int> cnt;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++){
            if (cnt.count(nums[i]))
                cnt[nums[i]]++;
            else cnt[nums[i]] = 1;
        }

        for (auto it = cnt.begin(); it != cnt.end(); it++)
            num_cnt.push_back(*it);

        sort(num_cnt.begin(), num_cnt.end(), cmp);
        
        for (int i = 0; i < num_cnt.size(); i++){
            while (num_cnt[i].second--)
                ans.push_back(num_cnt[i].first);
        }

        return ans;
    }
};