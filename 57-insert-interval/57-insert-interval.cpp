class comp{
public:
    bool operator()(vector<int>& v1, vector<int>& v2){
        return v1[0] < v2[0];
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = -1, right = -1;
        for(int i = 0; i < intervals.size(); i++){
            if(newInterval[0] <= intervals[i][1] && left == -1)
                left = i;
            if(newInterval[1] >= intervals[i][0] && (i == intervals.size()-1 || newInterval[1] < intervals[i+1][0]))
                right = i;
        }
        // if(left != -1 && right != -1){
        //     cout << newInterval[0] << " " << newInterval[1] << endl;
        //     cout << intervals[left][0] << " " << intervals[left][1] << endl;
        //     cout << intervals[right][0] << " " << intervals[right][1] << endl;
        // }
        
        if(left == -1)
            intervals.push_back(newInterval);
        else if(right == -1)
            intervals.insert(intervals.begin(), newInterval);
        else{
            int new_left = min(intervals[left][0], newInterval[0]);
            int new_right = max(intervals[right][1], newInterval[1]);
            vector<int> tmp = {new_left, new_right};
            intervals.erase(intervals.begin()+left, intervals.begin()+right+1);
            intervals.insert(intervals.begin()+left, tmp);
        }
        return intervals;
    }
};