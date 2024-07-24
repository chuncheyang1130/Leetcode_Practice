class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<pair<int, string*>> sort_v;

        for (int i = 0; i < heights.size(); i++)
            sort_v.push_back(make_pair(heights[i], &names[i]));
        
        sort(sort_v.begin(), sort_v.end(), greater<pair<int, string*>>());

        for (int i = 0; i < heights.size(); i++){
            ans.push_back(*(sort_v[i].second));
        }

        return ans;
    }
};