class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> st;
        for(int i = 0; i < words.size(); i++){
            string str = "";
            for(int j = 0; j < words[i].size(); j++)
                str += table[words[i][j]-'a'];
            
            if(st.find(str) == st.end())
                st.insert(str);
        }
        return st.size();
    }
};