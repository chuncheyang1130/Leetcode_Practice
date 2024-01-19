class Solution {
public:
    int minSteps(string s, string t) {
        int s_cnt[26] = {0}, t_cnt[26] = {0};
    
        for (int i = 0; i < s.size(); i++)
            s_cnt[s[i]-'a']++;

        for (int i = 0; i < t.size(); i++)
            t_cnt[t[i]-'a']++;
        
        int cnt = 0;
        for (int i = 0; i < 26; i++)
            cnt -= min(s_cnt[i], t_cnt[i]);

        cnt = 2 * cnt + (int)t.size() + (int)s.size();

        return cnt;

    }
};