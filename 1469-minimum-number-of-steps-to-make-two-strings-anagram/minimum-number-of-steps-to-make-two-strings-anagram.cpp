class Solution {
public:
    int minSteps(string s, string t) {
        int s_cnt[26] = {0}, t_cnt[26] = {0};
        int n = s.size();

        int alph = 0;

        for (int i = 0; i < n; i++){
            alph = s[i] - 'a';
            s_cnt[alph]++;

            alph = t[i] - 'a';
            t_cnt[alph]++;
        }
        
        int cnt = 0;
        for (int i = 0; i < 26; i++)
            cnt += abs(s_cnt[i]-t_cnt[i]);

        return cnt/2;

    }
};