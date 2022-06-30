class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> row(numRows, "");
        
        if(numRows == 1)
            return s;
        
        int cur_row = 0;
        bool goDown = true;
        
        for(int i = 0; i < s.size(); i++){
            row[cur_row] += s[i];
            
            if(cur_row == numRows-1)
                goDown = false;
            else if(cur_row == 0)
                goDown = true;
            
            if(goDown)
                cur_row += 1;
            else cur_row -= 1;
        }
        
        string ans = "";
        for(int i = 0; i < numRows; i++)
            ans += row[i];
        
        return ans;
    }
};