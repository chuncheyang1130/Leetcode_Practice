class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int len = positions.size();
        stack<pair<int,int>> st;

        vector<pair<int, int>> robot_pos;
        for (int i = 0; i < len; i++)
            robot_pos.push_back(make_pair(positions[i], i));

        sort(robot_pos.begin(), robot_pos.end());

        // for (int i = 0; i < len; i++){
        //     cout << robot_pos[i].second << " " << robot_pos[i].first << endl;
        // }

        vector<pair<int, int>> remain_robot;
        vector<int> ans;

        for (int i = 0; i < len; i++){
            int ind = robot_pos[i].second;
            if (st.empty() && directions[ind] == 'L'){
                remain_robot.push_back(make_pair(ind, healths[ind]));
            }else if (!st.empty() && directions[ind] == 'L'){
                while (1){
                    pair<int, int> left = st.top();
                    st.pop();

                    if (left.second > healths[ind]){
                        left.second--;
                        if (left.second != 0)
                            st.push(left);

                        break;
                    }else if (left.second == healths[ind]){
                        break;
                    }else if (left.second < healths[ind]){
                        healths[ind]--;
                    }

                    if (healths[ind] == 0){
                        break;
                    }else if (st.empty()){
                        remain_robot.push_back(make_pair(ind, healths[ind]));
                        break;
                    }
                }
            }else if (directions[ind] == 'R'){
                st.push(make_pair(ind, healths[ind]));
            }
        }

        int cur_len = remain_robot.size();

        while (!st.empty()){
            pair<int, int> robot = st.top();
            st.pop();
            remain_robot.insert(remain_robot.begin()+cur_len, robot);
        }

        sort(remain_robot.begin(), remain_robot.end());
        for (int i = 0; i < remain_robot.size(); i++){
            ans.push_back(remain_robot[i].second);
        }

        return ans;
    }
};