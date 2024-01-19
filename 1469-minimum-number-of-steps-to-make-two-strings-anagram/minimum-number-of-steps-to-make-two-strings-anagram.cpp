class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26] = {0};
        int n = s.size();
    
        for (int i = 0; i < n; i++)
            cnt[s[i]-'a']++;

        for (int i = 0; i < n; i++)
            cnt[t[i]-'a']--;
        
        int step = 0;
        for (int i = 0; i < 26; i++)
            step += abs(cnt[i]);

        step = step >> 1;

        return step;

    }
};