class Solution {
public:
    bool rotateString(string s, string goal) {
        int max_turns = goal.size();

        for (int i = 0; i < max_turns; i++){
            if (s == goal){
                return true;
            }else{
                goal.insert(goal.end(), goal[0]);
                goal.erase(goal.begin());
            }
        }

        return false;
    }
};