class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answer(2, vector<int>());
        int win[100001] = {0}, lose[100001] = {0};
        int max_num = 0;
        
        for (int i = 0; i < matches.size(); i++){
            int winner = matches[i][0];
            int loser = matches[i][1];
            win[winner]++;
            lose[loser]++;
            
            max_num = max({matches[i][0], matches[i][1], max_num});
        }

        for (int i = 0; i <= max_num; i++){
            if (lose[i] == 0 && win[i] != 0)
                answer[0].push_back(i);
            if (lose[i] == 1)
                answer[1].push_back(i);
        }

        return answer;
    }
};