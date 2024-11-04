class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1;

        for (int i = 1; i < word.size(); i++){
            if (count == 0){
                count = 1;
                continue;
            }

            if (word[i] == word[i-1]){
                count++;
            }else {
                comp.push_back('0'+count);
                comp.push_back(word[i-1]);
                count = 1;
            }

            if (count == 9){
                comp.push_back('9');
                comp.push_back(word[i]);
                count = 0;
            }
        }

        if (count){
            comp.push_back('0'+count);
            comp.push_back(word.back());
        }

        return comp;
    }
};