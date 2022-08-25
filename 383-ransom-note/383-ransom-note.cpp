class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mag_char(26, 0);
        for(int i = 0; i < magazine.size(); i++)
            mag_char[magazine[i]-'a']++;
        
        for(int i = 0; i < ransomNote.size(); i++)
            if(mag_char[ransomNote[i]-'a'] > 0)
                mag_char[ransomNote[i]-'a']--;
            else return false;
        return true;
    }
};