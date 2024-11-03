class Solution {
public:
    bool rotateString(string s, string goal) {
        int max_turns = goal.size();

        for (int i = 0; i < goal.size(); i++){
            if (s == goal){
                return true;
            }else{
                char ch = goal.front();
                goal.erase(goal.begin());
                goal.push_back(ch);
            }
        }

        return false;
    }
};