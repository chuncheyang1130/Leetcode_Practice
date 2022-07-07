class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> hash_table;
        int length = 0;
        for(int i = 0; i < words.size(); i++){
            swap(words[i][0], words[i][1]);
            if(hash_table.find(words[i]) != hash_table.end() && hash_table[words[i]] != 0){
                hash_table[words[i]] -= 1;
                length += 4;
            }else{
                swap(words[i][0], words[i][1]);
                hash_table[words[i]] += 1;
            }
        }
        
        for(auto it = hash_table.begin(); it != hash_table.end(); it++){
            if(it->second != 0 && it->first[0] == it->first[1]){
                length += 2;
                break;
            }
        }
        return length;
    }
};