class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int len = words[0].size();
        
        unordered_map<string, int> table;
        for(int i = 0; i < words.size(); i++)
            table[words[i]]++;
        
        for(int i = 0; i < len; i++){
            unordered_map<string, int> count;
            int left = i, cnt = 0;
            for(int j = i; j <= (int)s.size()-len; j += len){
                string sub = s.substr(j, len);
                if(table.find(sub) != table.end()){
                    count[sub]++;
                    cnt++;
                    if(count[sub] <= table[sub]){
                        cout << sub << endl;
                        if(cnt == words.size()){
                            ans.push_back(left);
                            string tmp = s.substr(left, len);
                            count[tmp]--;
                            cnt--;
                            left += len;
                        }
                    }else{
                        string str_pass = "";
                        while(str_pass != sub){
                            str_pass = s.substr(left, len);
                            left += len;
                            count[str_pass]--;
                            cnt--;
                        }
                    }
                }else{
                    cnt = 0;
                    left = j + len;
                    count.clear();
                }
            }
        }
        return ans;
    }
};