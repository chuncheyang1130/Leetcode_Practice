bool cmp(vector<int>& p1, vector<int>& p2){
    if(p1[0] < p2[0])
        return true;
    else if(p1[0] == p2[0] && p1[1] > p2[1])
        return true;
    else return false;
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<int> pos_left(people.size());
        vector<vector<int>> new_order(people.size());
        for(int i = 0; i < people.size(); i++)
            pos_left[i] = i;
        
        for(int i = 0; i < people.size(); i++){
            int pos = people[i][1];
            new_order[pos_left[pos]] = people[i];
            pos_left.erase(pos_left.begin()+pos);
        }
        
        return new_order;
    }
};