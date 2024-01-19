class Solution {
public:
    int minSteps(string s, string t) {
        // int s_cnt[26] = {0}, t_cnt[26] = {0};
        unordered_map<char, int> s_cnt, t_cnt;
        int n = s.size();
    
        for (int i = 0; i < n; i++)
            s_cnt[s[i]]++;
            // s_cnt[s[i]-'a']++;

        for (int i = 0; i < n; i++)
            t_cnt[t[i]]++;
            // t_cnt[t[i]-'a']++;
        
        int cnt = 0;
        for (char alph = 'a'; alph <= 'z'; alph++)
            cnt += abs(s_cnt[alph]-t_cnt[alph]);

        cnt /= 2;

        return cnt;

    }
};