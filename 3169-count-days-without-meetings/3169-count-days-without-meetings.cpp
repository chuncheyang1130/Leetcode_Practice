class Solution {
public:
    static bool cmp(vector<int>& v0, vector<int>& v1){
        if (v0[0] > v1[0]){
            return false;
        }else if (v0[0] == v1[0]){
            if (v0[1] > v1[1])
                return false;
            else return true;
        }
        return true;
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), cmp);
        int idle = 0, begin = 1;

        for (int i = 0; i < meetings.size(); i++){
            if (meetings[i][0] > begin)
                idle += meetings[i][0] - begin;

            if (meetings[i][1] >= begin)
                begin = meetings[i][1] + 1;
        }

        if (days >= begin)
            idle += days - begin + 1;

        return idle;
    }
};