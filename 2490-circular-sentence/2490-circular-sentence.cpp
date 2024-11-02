class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<int> begin, end;
        int len = sentence.size();

        begin.push_back(0);
        bool found = true;
        for (int i = 1; i < len; i++){
            if (sentence[i] == ' '){
                end.push_back(i-1);
                found = false;
            }else if (!found){
                found = true;
                begin.push_back(i);
            }
        }       

        if (found)
            end.push_back(len-1);

        for (int i = 0; i < begin.size(); i++){
            if (i == begin.size()-1){
                if (sentence[end[i]] != sentence[begin[0]])
                    return false;
            }else {
                if (sentence[end[i]] != sentence[begin[i+1]])
                    return false;
            }

        }
        return true;
    }
};