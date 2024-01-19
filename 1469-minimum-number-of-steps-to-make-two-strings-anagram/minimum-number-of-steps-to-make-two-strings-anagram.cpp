class Solution {
public:
    int minSteps(string s, string t) {
        int s_cnt[26] = {0}, t_cnt[26] = {0};
        int n = s.size();

        for (int i = 0; i < n; i++){
            s_cnt[s[i]-'a']++;
            t_cnt[t[i]-'a']++;
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++)
            cnt += abs(s_cnt[i]-t_cnt[i]);

        return cnt/2;

    }
};