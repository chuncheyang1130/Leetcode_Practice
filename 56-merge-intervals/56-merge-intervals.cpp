bool cmp(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int l = 0;
        int left = intervals[0][0], right = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= right){
                right = max(right, intervals[i][1]);
            }else{
                intervals[l][0] = left;
                intervals[l][1] = right;
                left = intervals[i][0];
                right = intervals[i][1];
                if(l+1 != i)
                    intervals.erase(intervals.begin()+l+1, intervals.begin()+i);
                i = ++l;
            }
        }
        if(l != intervals.size()-1){
            intervals[l][0] = left;
            intervals[l][1] = right;
            intervals.erase(intervals.begin()+l+1, intervals.end());
        }
        return intervals;
    }
};